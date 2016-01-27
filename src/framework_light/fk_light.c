/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/27 17:31:26 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_light.h"
#include "framework_shape/fk_type.h"
#include <stdlib.h>

static t_rgba	lambert_low(t_intersect inter, t_spotlight light, t_rgba ptcolor)
{
	float		angle;
	t_vector3	v_light;

	v_light = vector_substract(inter.pos, light.pos);
	v_light = vector_scale(v_light, 1 / vector_dotproduct(v_light, v_light));
	angle = vector_dotproduct(inter.v_normal, vector_unit(v_light));
	return (color_product(color_mul(ptcolor, light.intensity),
				color_mul(light.color, angle)));
}

t_rgba			iter_light(t_intersect inter, t_spotlight *light)
{
	return (lambert_low(inter, *light, ((t_object *)inter.obj)->color));
}
