/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:30:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/27 23:21:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_light.h"

static t_rgb	lambert_low(t_intersect inter, t_spotlight light, t_rgb ptcolor)
{
	double		reb_to_light;
	t_vector3	v_light;

	v_light = vector_unit(vector_substract(inter.pos, light.pos));
	reb_to_light = vector_dotproduct(v_light, vector_unit(inter.v_light));
	reb_to_light *= light.intensity;
	return ((t_rgb) {ptcolor.r + light.color.r * reb_to_light,
					ptcolor.g + light.color.g * reb_to_light,
					ptcolor.b + light.color.b * reb_to_light,
					ptcolor.a});
}

t_rgb			iter_light(t_intersect inter, t_spotlight *light, t_rgb color)
{
	return (lambert_low(inter, *light, color));
}
