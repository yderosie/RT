/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 19:23:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_plan.h"

static t_bool	plan_crossroad(t_ray ray, t_plan plan, t_intersect *i)
{
	float	d;

	d = - (plan.pos.x  + plan.pos.y + plan.pos.z);
	d = -((vector_dotproduct(ray.pos, plan.normal) + d) / (vector_dotproduct(ray.dir, plan.normal)));
	if (d >= 0.)
	{
		i->pos = vector_sum(ray.pos, vector_scale(ray.dir, d));
		i->v_light = plan.normal;
		return (TRUE);
	}
	return (FALSE);
}

t_bool		intersect_plan(t_ray ray, t_plan *obj, t_intersect *inter)
{
	return (plan_crossroad(ray, *obj, inter));
}
