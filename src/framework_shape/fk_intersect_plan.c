/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/14 17:16:21 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_plan.h"

t_bool			intersect_plan(t_ray ray, t_plan *plan, float *t)
{
	*t = - (plan->pos.x  + plan->pos.y + plan->pos.z);
	*t = -((vector_dotproduct(ray.pos, plan->normal) + *t) / (vector_dotproduct(ray.dir, plan->normal)));
	if (*t >= 0.)
		return (TRUE);
	return (FALSE);
}
