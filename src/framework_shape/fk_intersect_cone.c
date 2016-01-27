/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:21:51 by yderosie          #+#    #+#             */
/*   Updated: 2016/01/27 14:21:54 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "framework_shape/fk_cone.h"
#include "framework_math/fk_math.h"


t_bool			intersect_cone(t_ray ray, t_cone* obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		d;
	t_vector3	etoc;

	//etoc = vector_substract(obj->pos, ray.pos);
	etoc = vector_substract(ray.pos, obj->pos);
	a = vector_dotproduct(ray.dir, ray.dir) - ((1 + obj->radius * obj->radius) * SQUARE(vector_dotproduct(ray.dir, obj->dir)));
	b = (vector_dotproduct(ray.dir, etoc) - ((1 + obj->radius * obj->radius) * vector_dotproduct(ray.dir, obj->dir) * vector_dotproduct(etoc, obj->dir))) * 2;
	c = vector_dotproduct(etoc, etoc) - ((1 + obj->radius * obj->radius) * SQUARE(vector_dotproduct(etoc, obj->dir)));
	d = b * b - 4 * a * c;
	if (d >= 0.000001)
	{
			*t = FT_MIN(((-b - sqrt(d)) / (2. * a)), ((-b + sqrt(d)) / (2. * a)));
			if (*t > 0.)
				return (TRUE);
	}
	return (FALSE);
}