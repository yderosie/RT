/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/27 15:07:14 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_plan.h"
#include "framework_math/fk_math.h"

#define EPSILON 0.00001

t_bool			intersect_plan(t_ray ray, t_plan *plan, float *t)
{
	float		m;
	float		d;
	t_vector3	pos;

	pos = vector_substract(ray.pos, plan->pos);
	m = vector_dotproduct(plan->normal, pos);
	d = vector_dotproduct(plan->normal, ray.dir);
	*t = -m / d;
	if (*t < 0.)
		return (FALSE);
	return (TRUE);
}
