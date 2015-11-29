/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/29 22:29:27 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_light.h"
#include <stdlib.h>

static t_rgba	lambert_low(t_intersect inter, t_spotlight light, t_rgba ptcolor)
{
	double		angle;
	t_vector3	v_light;
	t_rgba		result;

	v_light = vector_substract(inter.pos, light.pos);
	angle = vector_dotproduct(inter.v_light, vector_unit(v_light));
	if (angle > 0)
		return (ptcolor);
	result.r = ABS(((0.8 * (ptcolor.r / 255.0)) * (light.color.r / 255.0) *  angle)) * 255;
	result.g = ABS(((0.8 * (ptcolor.g / 255.0)) * (light.color.g / 255.0) * angle)) * 255;
	result.b = ABS(((0.8 * (ptcolor.b / 255.0)) * (light.color.b / 255.0) * angle)) * 255;
	result.a = ptcolor.a;
	dprintf(2, "test de color R = %i ; G = %i ; B = %i ; A = %i\n", result.r, result.g, result.b, result.a);
	return (result);
}

static t_rgba	test(t_intersect inter, t_spotlight light, t_rgba ptcolor)
{
	double		angle;
	double		testrgb;
	t_vector3	v_light;

	v_light = vector_unit(vector_substract(inter.pos, light.pos));
	dprintf(2, "vector light : {%f, %f, %f}\n", v_light.x, v_light.y, v_light.z);
	angle = vector_dotproduct(inter.v_light, v_light);
	testrgb = (ptcolor.r / 255.0) + (light.color.r / 255.0) * angle * 0.4;
	ptcolor.r = testrgb * 255;
	testrgb = (ptcolor.g / 255.0) + (light.color.g / 255.0) * angle * 0.4;
	ptcolor.g = testrgb * 255;
	testrgb = (ptcolor.b / 255.0) + (light.color.b / 255.0) * angle * 0.4;
	ptcolor.b = testrgb * 255;
	return (ptcolor);
}

t_rgba			iter_light(t_intersect inter, t_spotlight *light, t_rgba color)
{
	return (lambert_low(inter, *light, color));
	return (color);
	return (test(inter, *light, color));
}
