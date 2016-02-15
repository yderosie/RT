/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/15 16:17:03 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_light.h"
#include "framework_shape/fk_type.h"
#include <stdlib.h>

static t_color3	lambert_low(t_intersect inter, t_spotlight light, t_color3 ptcolor)
{
	float		angle;
	t_vector3	v_light;

	v_light = vector_unit(vector_substract(inter.pos, light.pos));
	angle = vector_dotproduct(vector_unit(v_light), vector_unit(inter.v_normal));
	return (vector_div(vector_mul(vector_sum(ptcolor, vector_mul(light.color, angle)), light.intensity), 2));
}

static t_color3	light_low(t_intersect inter, t_spotlight light, t_color3 ptcolor)
{
	float		angle;
	float		diff;
	t_vector3	v_light;
	t_color3	color;

	v_light = vector_unit(vector_substract(light.pos, inter.pos));
	angle = vector_dotproduct(inter.v_normal, v_light);
	if (inter.obj->diffuse > 0)
		if (angle > 0)
		{
			diff = angle * inter.obj->diffuse;
			color = vector_sum(ptcolor, vector_mul(vector_product(ptcolor, light.color), diff));
			return color;
		}
	return ptcolor;
}

t_color3			iter_light(t_intersect inter, t_spotlight *light)
{
	return (lambert_low(inter, *light, ((t_object *)inter.obj)->color));
	return (vector_div(vector_sum(light_low(inter, *light, ((t_object *)inter.obj)->color), lambert_low(inter, *light, ((t_object *)inter.obj)->color)), 2));
}
