/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:19:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/23 20:29:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_cylinder.h"
#include "framework_math/fk_math.h"


t_vector3		normal_cylinder(t_vector3 inter, t_cylinder *obj)
{
	float		radius;
	t_vector3	ctop;
	t_vector3	qtop;
	t_vector3	v_normal;

	ctop = vector_substract(inter, obj->pos);
	radius = vector_dotproduct(ctop, obj->dir);
	qtop = vector_substract(ctop, vector_scale(obj->dir, radius));
	return (vector_div(qtop, obj->radius));
}