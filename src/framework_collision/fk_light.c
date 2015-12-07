/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/04 15:00:44 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_light.h"
#include "framework/fk_type.h"
#include <stdlib.h>

static t_rgba	lambert_low(t_intersect inter, t_spotlight light, t_rgba ptcolor)
{
	double		angle;
	t_vector3	v_light;
	t_rgba		result;

	v_light = vector_substract(inter.pos, light.pos);
	angle = vector_dotproduct(inter.v_light, vector_unit(v_light));
	return (color_product(color_mul(ptcolor, light.intensity),
				color_mul(light.color, angle)));
}

static t_rgba	test(t_intersect inter, t_spotlight light, t_rgba ptcolor)
{
	return (ptcolor);
}

t_rgba			iter_light(t_intersect inter, t_spotlight *light, t_object *obj)
{
	//if (obj->type == PLANE)
	//	return (obj->color);
	return (lambert_low(inter, *light, obj->color));
	return (test(inter, *light, obj->color));
	return (obj->color);
}
