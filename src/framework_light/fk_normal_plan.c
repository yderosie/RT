/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:08:36 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/09 11:24:59 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_plan.h"
#include "framework_math/fk_math.h"

void		normal_plan(t_intersect *inter, t_plan *obj)
{
	(void)obj;
	inter->v_normal = obj->normal;
}

void		normal_finished_plan(t_intersect *inter, t_fplan *obj)
{
	(void)obj;
	inter->v_normal = obj->normal;
}
