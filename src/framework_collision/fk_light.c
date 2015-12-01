/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/01 14:10:26 by mbarbari         ###   ########.fr       */
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
	//if (angle < 0)
	//	return ((t_rgba){0, 0, 0, 0});
	result.r = ABS(((light.intensity * (ptcolor.r / 255.0)) * (light.color.r / 255.0) *  angle)) * 255;
	result.g = ABS(((light.intensity * (ptcolor.g / 255.0)) * (light.color.g / 255.0) * angle)) * 255;
	result.b = ABS(((light.intensity * (ptcolor.b / 255.0)) * (light.color.b / 255.0) * angle)) * 255;
	result.a = ptcolor.a;
	return (result);
}

static t_rgba	test(t_intersect inter, t_spotlight light, t_rgba ptcolor)
{
	return (ptcolor);
}

t_rgba			iter_light(t_intersect inter, t_spotlight *light, t_rgba color)
{
	return (lambert_low(inter, *light, color));
	return (color);
	return (test(inter, *light, color));
}
