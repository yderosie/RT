/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vectoriel_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:21:42 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/27 16:18:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vectoriel.h"

t_vector3		vector_new(float x1, float y1, float z1)
{
	return ((t_vector3) {.x = x1, .y = y1, .z = z1});
}

t_vector3		vector_cpy(t_vector3 u)
{
	return ((t_vector3) {.x = u.x, .y = u.y, .z = u.z});
}

t_vector3		vector_unit(t_vector3 u)
{
	t_vector3		unitvector;

	unitvector.x = u.x / vector_magnitude(u);
	unitvector.y = u.y / vector_magnitude(u);
	unitvector.z = u.z / vector_magnitude(u);
	return (unitvector);
}

t_vector3		vector_scale(t_vector3 v, double f)
{
	return (t_vector3) { .x = v.x * f, .y = v.y * f, .z = v.z * f };
}

t_vertex3		vector_translation(t_vector3 u, t_vertex3 v)
{
	return ((t_vertex3) {.x = u.x + v.x, .y = u.y + v.y, .z = u.z + v.z});
}

t_vector3		vector_mul(t_vector3 u, double r)
{
	return ((t_vector3) {	.x = u.y * r,
							.y = u.z * r,
							.z = u.x * r});
}

t_vector3		vector_div(t_vector3 u, double r)
{
	return ((t_vector3) {	.x = u.y / r,
							.y = u.z / r,
							.z = u.x / r});
}
