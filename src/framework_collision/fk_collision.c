/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/04 12:18:56 by mbarbari         ###   ########.fr       */
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
	t_rgba color;
	t_rgba color2;

	ft_memcpy(	arr + 0,
				&(t_sphere){	SPHERE,
								(t_rgba) {255, 255, 255, 0},
								(t_vertex3) {0, 0, 9.5},
								4.00},
				sizeof(t_sphere));

	ft_memcpy(	arr + 1,
				&(t_plan){	PLANE,
								(t_rgba) {255, 255, 0, 0},
								(t_vertex3) {-1.0, 3.0, 1.0},
								vector_unit((t_vector3) {0.0, 0.0, 0.0})},
				sizeof(t_plan));

	ft_memcpy(light1 + 0,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {0, 255, 0, 0},
								(t_vertex3) {2.3945898028, -2.8880163869, 5.448},
								0.45,
								0.5},
				sizeof(t_spotlight));

	ft_memcpy(light1 + 1,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {0, 255, 255, 0},
								(t_vertex3) {-2.1876005426, 3.688572153, 6.4295767343},
								0.45,
								0.4},
				sizeof(t_spotlight));

	arr[2].type = DEFAULT;
	i = 1;
	already_has_radius = FALSE;
	while (i != 1)
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
		}
		i++;
	}
	if (already_has_radius == TRUE) {
			color = iter_light(inter, (t_spotlight *)&light1[0], arr[i].color);
			color2 = iter_light(inter, (t_spotlight *)&light1[1], arr[i].color);
			return ((t_rgba) {
				(color.r + color2.r) / 2,
				(color.g + color2.g) / 2,
				(color.b + color2.b) / 2
			});
		}
	else
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
			ray.dir = vector_unit(ray.dir);
			rgba = ft_trace_ray(env, ray);
			mlx_pixel_put(env.mlx, env.win, x, y, rgba_to_dword(rgba));
			x++;
		}
		y++;
	}
	dprintf(2, "THE END\n");
}
