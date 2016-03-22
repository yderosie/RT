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

static t_color3	lambert(t_intersect inter, t_object light, t_color3 ptcolor,
	float shade)
{
	float		angle;
	t_vector3	v_light;

	v_light = vector_unit(vector_substract(inter.pos, light.pos));
	angle = vector_dotproduct(vector_unit(v_light), vector_unit(inter.v_normal))
	* shade;
	if (angle <= 0)
		angle = 0.0f;
	return (vector_div(vector_mul(vector_sum(ptcolor, vector_mul(light.color,
		angle)), light.intensity), 2));
}

static t_color3	specular(t_intersect inter, t_object light,
	t_color3 ptcolor, float shade)
{
	t_vector3	r;
	t_vector3	v_light;
	t_color3	color;
	float		angle;
	float		spec;

	if (inter.obj->light == TRUE)
		return (ptcolor);
	v_light = vector_unit(vector_substract(light.pos, vector_sum(inter.pos,
		inter.ray.pos)));
	r = vector_unit(vector_substract(v_light, vector_mul(inter.v_normal, (2.0f *
		vector_dotproduct(v_light, inter.v_normal)))));
	angle = vector_dotproduct(inter.ray.dir, r);
	if (angle > 0.0f)
	{
		spec = powf(angle, 20) * inter.obj->specular * shade;
		color = vector_sum(ptcolor, vector_mul(light.color, spec));
		return (color);
	}
	return (ptcolor);
}

t_color3		iter_light(t_intersect inter, t_object *light, float shade)
{
	return (specular(inter, *light, lambert(inter, *light,
		((t_object *)inter.obj)->color, shade), shade));
}
