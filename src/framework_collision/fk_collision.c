/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/29 22:28:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "framework/fk_collision.h"
#include "framework/fk_objects.h"
#include "framework/fk_light.h"

#define VECTOR_UP ((t_vector3) { .x = 0, .y = 1, .z = 0 })


inline t_vertex3	vector_to_vertex(t_vector3 vec)
{
	t_vertex3	tmp;

	tmp.x = vec.x;
	tmp.y = vec.y;
	tmp.z = vec.z;
	return (tmp);
}

t_vector3	vertex_to_vector(t_vertex3 vec)
{
	t_vector3	tmp;

	tmp.x = vec.x;
	tmp.y = vec.y;
	tmp.z = vec.z;
	return (tmp);
}

t_intersect	nearest_vertex(t_ray ray, t_intersect new, t_intersect old)
{
	unsigned int	lengthv1;
	unsigned int	lengthv2;

	lengthv1 = vector_magnitude(vector_substract(vertex_to_vector(ray.pos), vertex_to_vector(new.pos)));
	lengthv2 = vector_magnitude(vector_substract(vertex_to_vector(ray.pos), vertex_to_vector(old.pos)));
	if (FT_MIN(lengthv1, lengthv2) == lengthv1)
		return (new);
	return (old);
}

t_rgba		ft_trace_ray(t_env env, t_ray ray)
{
	t_object	arr[16];
	t_object	light1[16];
	t_intersect	inter;
	t_intersect	tmp;
	t_bool		already_has_radius;
	int			i;

	ft_memcpy(	arr + 0,
				&(t_sphere){	SPHERE,
								(t_vertex3) {4.17, -5.65, 13.5},
								(t_rgba) {200, 10, 200, 0},
								1.70},
				sizeof(t_sphere));

	ft_memcpy(light1 + 0,
				&(t_spotlight){	SPOTLIGHT,
								(t_vertex3) {1.36, 1.97, 4.97},
								(t_rgba) {255, 255, 255, 0},
								0.45,
								0.9},
				sizeof(t_spotlight));

	arr[1].type = DEFAULT;
	already_has_radius = FALSE;
	i = 0;
	while (i < 16)
	{
		if (arr[i].type == DEFAULT)
			break;
		if (env.fctinter[arr[i].type](ray, arr + i, &tmp))
		{
			if (already_has_radius)
				inter = nearest_vertex(ray, inter, tmp);
			else
			{
				inter = tmp;
				already_has_radius = TRUE;
			}
			return (iter_light(tmp, (t_spotlight *)&light1[0], arr[i].color));
		}
		i++;
	}
	return (t_rgba) { 0, 0, 0, 0 };
}

void		ft_render(t_env env)
{
	t_rgba			rgba;
	t_ray			ray;
	int				y;
	int				x;
	t_vector3		vpRight;
	t_vector3		vpUp;
	float			halfWidth;
	float			halfHeight;
	float			pixelWidth;
	float			pixelHeight;

	halfWidth = tan(M_PI * (env.fov / 2) / 180);
	halfHeight = env.resolution.height / env.resolution.width * halfWidth;
	pixelWidth = halfWidth * 2 / (env.resolution.width - 1);
	pixelHeight = halfHeight * 2 / (env.resolution.height - 1);
	vpRight = vector_unit(vector_product(env.dir_camera, VECTOR_UP));
	vpUp = vector_unit(vector_product(vpRight, env.dir_camera));
	ray.pos = env.pos_absolute_camera;
	y = 0;
	while (y <= env.resolution.height)
	{
		x = 0;
		while (x <= env.resolution.width)
		{
			ray.dir = env.dir_camera;
			ray.dir = vector_sum(ray.dir, vector_scale(vpRight, (x * pixelWidth) - halfWidth));
			ray.dir = vector_sum(ray.dir, vector_scale(vpUp, (y * pixelHeight) - halfHeight));
			x == env.resolution.width && y == 0 ?
			dprintf(2, "max rayon haut-doite : {%f , %f , %f}\n", ray.dir.x, ray.dir.y, ray.dir.z) : 0;
			y == 0 && x == 0 ?
			dprintf(2, "max rayon haut-gauche : {%f , %f , %f}\n", ray.dir.x, ray.dir.y, ray.dir.z) : 0;
			x == env.resolution.width && y == env.resolution.height ?
			dprintf(2, "max rayon bas-droite : {%f , %f , %f}\n", ray.dir.x, ray.dir.y, ray.dir.z) : 0;
			x == 0 && y == env.resolution.height ?
			dprintf(2, "max rayon haut-gauche : {%f , %f , %f}\n", ray.dir.x, ray.dir.y, ray.dir.z) : 0;
			ray.dir = vector_unit(ray.dir);
			rgba = ft_trace_ray(env, ray);
			mlx_pixel_put(env.mlx, env.win, x, y, rgba_to_dword(rgba));
			x++;
		}
		y++;
	}
}
