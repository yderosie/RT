/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:45:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 20:57:24 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fk_vectoriel.h>

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

t_vector3		vector_translation(t_vector3 u, t_vertex3 v)
{
	t_vector3		translate;

	translate = vector_cpy(u);
	translate.pos = v;
	return (translate);
}
