/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 13:40:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_plan.h"

t_bool			intersect_plan(t_ray ray, t_plan *obj, float *t)
{
	*t = - (plan.pos.x  + plan.pos.y + plan.pos.z);
	*t = -((vector_dotproduct(ray.pos, plan.normal) + *t) / (vector_dotproduct(ray.dir, plan.normal)));
	if (*t >= 0.)
	{
		i->pos = vector_sum(ray.pos, vector_scale(ray.dir, *t));
		i->v_normal = plan.normal;
		return (TRUE);
	}
	return (FALSE);
}
