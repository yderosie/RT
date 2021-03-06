/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/03 15:45:33 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_light.h"
#include "framework_shape/fk_type.h"
#include "framework_math/fk_vector.h"
#include "framework_math/fk_math.h"
#include <stdlib.h>

static t_color3	lambert_low(t_intersect inter, t_object light, t_color3 ptcolor, float shade)
{
	float		angle;
	t_vector3	v_light;

	/*if (inter.obj->light == TRUE)
		return (ptcolor);*/
	v_light = vector_unit(vector_substract(inter.pos, light.pos));
	angle = vector_dotproduct(vector_unit(v_light), vector_unit(inter.v_normal)) * shade;
	return (vector_div(vector_mul(vector_sum(ptcolor, vector_mul(light.color, angle)), light.intensity), 2));
}

static t_color3	light_low(t_intersect inter, t_object light, t_color3 ptcolor, float shade)
{
	float		angle;
	float		diff;
	t_vector3	v_light;
	t_color3	color;

	v_light = vector_unit(vector_substract(light.pos, inter.pos));
	angle = vector_dotproduct(inter.v_normal, v_light);
	if (inter.obj->diffuse > 0)
	{
		if (angle > 0)
		{
			diff = angle * inter.obj->specular * shade;
			color = vector_sum(ptcolor, vector_product(inter.obj->color, vector_mul(ptcolor, diff)));
			return color;
		}
	}
	return ptcolor;
}

static t_color3	specular_low(t_intersect inter, t_object light, t_color3 ptcolor, float shade)
{
	t_vector3	v;
	t_vector3	r;
	t_vector3	v_light;
	t_color3	color;
	float		angle;
	float		spec;

	if (inter.obj->light == TRUE)
		return (ptcolor);
	v_light = vector_unit(vector_substract(light.pos, inter.pos));
	v = inter.ray.dir;
	r = vector_unit(vector_substract(vector_mul(v_light, 1), vector_mul(inter.v_normal, (2.0f * vector_dotproduct(v_light, inter.v_normal)))));
	angle = vector_dotproduct(v, r);
	if (angle > 0.0f)
	{
		spec = powf(angle, 20) * inter.obj->specular * shade;
		color = vector_sum(ptcolor, vector_mul(light.color, spec));
		return color;
	}
	return ptcolor;
}

t_color3			iter_light(t_intersect inter, t_object *light, float shade)
{
	return (specular_low(inter, *light, lambert_low(inter, *light, ((t_object *)inter.obj)->color, shade), shade));
}
