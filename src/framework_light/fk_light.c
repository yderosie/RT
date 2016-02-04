/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/04 15:04:19 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_light.h"
#include "framework_shape/fk_type.h"
#include <stdlib.h>

static t_color3	lambert_low(t_intersect inter, t_spotlight light, t_color3 ptcolor)
{
	float		angle;
	t_vector3	v_light;

	v_light = vector_unit(vector_substract(light.pos, inter.pos));
	angle = vector_dotproduct(light.dir, inter.v_normal) * light.intensity;
	return (vector_product(vector_mul(ptcolor, light.intensity),
				vector_mul(light.color, angle)));
}

t_color3			iter_light(t_intersect inter, t_spotlight *light)
{
	return (lambert_low(inter, *light, ((t_object *)inter.obj)->color));
}
