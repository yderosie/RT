/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:28:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 20:24:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fk_collision.h>

t_intersect	nearest_vertex(t_ray ray, t_intersect new, t_intersect old)
{
	t_vector3		tmp;
	unsigned int	lenghtv1;
	unsigned int	lenghtv2;

	tmp = vector_translation(ray.dir, new.pos);
	lenghtv1 = lenght_segment(ray.pos, (t_vertex3)tmp);
	tmp = vector_translation(ray.dir, old.pos);
	lenghtv2 = lenght_segment(ray.pos, (t_vertex3)tmp);
	if (FT_MIN(lenghtv1, lenghtv2) == lenghtv1)
		return (new);
	return (old);
}

t_bool		ft_throwing_ray(t_env env, t_ray ray, t_intersect *inter)
{
	t_object	arr[16];
	t_intersect	tmp;
	int			i;

	ft_memcpy(arr + 0, (t_sphere){ SPHERE, 0, (t_vertex3) { 1, 1, 10 }, 5 });
	ft_memcpy(arr + 1, (t_sphere){ SPHERE, 0, (t_vertex3) { 1, 8, 10 }, 2 });
	i = 0;
	while (arr[i] && arr[i].type != DEFAULT)
	{
		fctinter[arr[i].type](ray, arr + i, &tmp);
		*inter = nearest_vertex(ray, inter, tmp);
		i++;
	}
	return (inter);
}

void		ft_render(t_env env, t_object objs)
{
	t_intersect		inter;
	t_rgb			rgb;
	t_ray			ray;

	while (y < env.resolution.height)
		while (x < env.resolution.width)
		{
			ray = ray_new(env.pos_absolute_camera, (t_vector3){ x, y, z });
			if (ft_throwing_ray(env, ray, &inter) == TRUE)
				rgb = (t_rgb) {0xAA, 0x17, 0x44};
			else
				rgb = (t_rgb) {0xFF, 0xFF, 0xFF};
			draw(env, inter, rgb);
		}
}
