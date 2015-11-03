/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/03 19:57:01 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "framework/fk_collision.h"
#include "framework/fk_objects.h"

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

t_rgb		ft_trace_ray(t_env env, t_ray ray)
{
	t_object	arr[16];
	t_intersect	inter;
	t_intersect	tmp;
	int			i;

	ft_memcpy(arr + 0, &(t_sphere){ SPHERE, (t_vertex3) { 1, 1, 10 }, 5 }, sizeof(t_sphere));
	ft_memcpy(arr + 1, &(t_sphere){ SPHERE, (t_vertex3) { 1, 8, 10 }, 2 }, sizeof(t_sphere));
	inter.radius = -1;
	i = 0;
	while (i < 16)
	{
		if (arr[i].type == DEFAULT)
			continue;
		if (env.fctinter[arr[i].type](ray, arr + i, &tmp) && inter.radius > -1)
			inter = nearest_vertex(ray, inter, tmp);
		else if (inter.radius <= -1)
			inter = tmp;
		i++;
	}
	if (inter.radius > -1)
		return (t_rgb) { 255, 255, 255, 0 };
	else
		return (t_rgb) { 0, 0, 0, 0 };
}

void		ft_render(t_env env)
{
	t_rgb			rgb;
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
	while (y < env.resolution.height)
		x = 0;
		while (x < env.resolution.width)
		{
			ray.dir = env.dir_camera;
			ray.dir = vector_sum(ray.dir, vector_scale(vpRight, (x * pixelWidth) - halfWidth));
			ray.dir = vector_sum(ray.dir, vector_scale(vpUp, (y * pixelHeight) - halfHeight));
			rgb = ft_trace_ray(env, ray);
			//draw(env, inter, rgb);
			x++;
		}
		y++;
}
