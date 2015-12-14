/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:08:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/14 18:51:39 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_plan.h"
#include "framework_math/fk_math.h"

t_vector3		normal_plan(t_vector3 inter, t_plan *obj)
{
	return (obj->normal);
}
