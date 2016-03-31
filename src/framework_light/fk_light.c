/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/25 14:11:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_light.h"
#include "framework_shape/fk_type.h"
#include "framework_math/fk_vector.h"
#include "framework_math/fk_math.h"
#include <stdlib.h>

static float	lambert_low(t_intersect inter, t_object light, float shade)
{
	float		angle;
	t_vector3	v_light;

	v_light = vector_unit(vector_substract(inter.pos, light.pos));
	angle = vector_dotproduct(vector_unit(v_light), vector_unit(inter.v_normal))
		* shade * inter.obj->diffuse;
	return (angle);
}

static float	specular_low(t_intersect inter, t_object light, float shade)
{
	t_vector3	v;
	t_vector3	r;
	t_vector3	v_light;
	float		angle;

	if (inter.obj->light == TRUE)
		return (0);
	v_light = vector_unit(vector_substract(light.pos, inter.pos));
	v = inter.ray.dir;
	r = vector_unit(vector_substract(v_light, vector_mul(inter.v_normal, (2.0f
		* vector_dotproduct(v_light, inter.v_normal)))));
	angle = vector_dotproduct(v, r);
	if (angle > 0.0f)
		return (powf(angle, 20) * inter.obj->specular * shade);
	return (0);
}

t_color3		iter_light(t_intersect inter, t_object *light, float shade)
{
	t_color3	out;

	out = vector_mul(inter.color, inter.obj->ambient);
	out = vector_sum(out, vector_mul(light->mat.color1,
		lambert_low(inter, *light, shade)));
	out = vector_sum(out, vector_mul(light->mat.color1,
		specular_low(inter, *light, shade)));
	return (out);
}
