/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:56 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/05 11:45:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_cylinder.h"
#include "framework_math/fk_math.h"


t_bool			intersect_cylinder(t_ray ray, t_cylinder* obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		d;
	t_vector3	x;

	a = vector_dotproduct(ray.dir, ray.dir) - SQUARE(vector_dotproduct(ray.dir, obj->dir));
	x = vector_substract(ray.pos, obj->pos);
	b = (vector_dotproduct(ray.dir, x) - vector_dotproduct(ray.dir, obj->dir) * vector_dotproduct(x, obj->dir))* 2;
	c = vector_dotproduct(x, x) - SQUARE(vector_dotproduct(x, obj->dir)) - (obj->radius * obj->radius);
	d = b * b - 4 * a * c;
	if (d > 0.)
	{
		if (((-b - sqrt(d)) / (2 * a)) > 0)
			*t = (-b - sqrt(d)) / (2 * a);
		else
			*t = (-b + sqrt(d)) / (2 * a);
		return (TRUE);
	}
	return (FALSE);
}