/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 13:40:52 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_sphere.h"
#include "framework_shape/fk_ray.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"

static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	t_vector3		etoc;
	float			t;
	float			radius;
	float			vector_radius;

	etoc = vector_substract(sphere.pos, ray.pos);
	if ((vector_radius = vector_dotproduct(etoc, ray.dir)) < 0.)
		return (FALSE);
	t = vector_dotproduct(etoc, etoc) - SQUARE(vector_radius);
	if (t > (radius = SQUARE(sphere.radius)))
		return (FALSE);
	t = sqrt(radius - t);
	t = FT_MIN((vector_radius - t), (vector_radius + t));
	i->pos = vector_sum(ray.pos, vector_scale(ray.dir, t));
	i->v_normal = vector_substract (i->pos, sphere.pos);
	t = vector_dotproduct(i->v_normal, i->v_normal);
	t = fk_isqrt(t);
	i->v_normal = vector_scale(i->v_normal, t);
	return (TRUE);
}

t_bool			intersect_sphere(t_ray ray, t_sphere* obj, t_intersect *inter)
{
	return (sphere_crossroad(ray, *obj, inter));
}

