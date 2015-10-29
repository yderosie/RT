/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/29 22:53:53 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fk_objects.h>
#include <fk_collision.h>

t_sphere		*new_sphere(t_vector pos, unsigned int radius)
{
	t_sphere	newsphere;

	newsphere = malloc(sizeof(t_sphere));
	newsphere->position = (t_vector3) {.x = pos.x, .y = pos.y, .z = pos.z};
	newsphere->radius = radius;
	newsphere->intersect = get_function_intersect(SPHERE);
	return (newsphere);
}

void			modif_sphere(t_sphere *obj, t_sphere modify)
{
	t_position	pos;

	pos = modify.pos;
	obj->position = (t_vector3) {.x = pos.x, .y = pos.y, .z = pos.z};
	obj->radius = modify.radius;
}
