/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/04 12:15:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_plan.h"

static t_bool	plan_crossroad(t_ray ray, t_plan plan, t_intersect *i)
{
	double		t;
	double		d_ray;

	d_ray = vector_dotproduct(plan.normal, ray.dir);
	if (d_ray == 0)
		return (FALSE);
	t = (-vector_dotproduct(plan.normal, vector_substract(ray.pos, plan.pos))) / d_ray;
	if (t < 0.0)
		return (FALSE);
	i->pos = vector_sum(ray.pos, vector_scale(ray.dir, t));
	if (d_ray < 0)
		i->v_light = plan.normal;
	else
		i->v_light = vector_scale(plan.normal, -1);
	return (TRUE);
}

static t_bool	plan_crossroad2(t_ray ray, t_plan plan, t_intersect *i)
{
	double		t;
	double		d_ray;

	d_ray = vector_dotproduct(plan.normal, ray.dir);
	if (d_ray > 0.0001f)
	{
		t = vector_dotproduct(vector_substract(plan.pos, ray.pos), plan.normal) / d_ray;
		if (t >= 0)
		{
			i->pos = vector_sum(ray.pos, vector_scale(ray.dir, t));
			if (d_ray < 0)
				i->v_light = plan.normal;
			else
				i->v_light = vector_scale(plan.normal, -1);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool		intersect_plan(t_ray ray, t_plan *obj, t_intersect *inter)
{
	return (plan_crossroad2(ray, *obj, inter));
}
