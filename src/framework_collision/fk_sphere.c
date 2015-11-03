/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/03 17:31:50 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include <stdlib.h>

static int			dist_sphere_crossroad(t_ray ray, t_sphere sphere)
{
	int				angle;
	t_vector3		eyetocenter;
	unsigned int	adjacent;

	eyetocenter = (t_vector3) { ray.pos.x - sphere.pos.x,
								ray.pos.y - sphere.pos.y,
								ray.pos.z - sphere.pos.z };
	angle = vector_dotproduct(ray.dir, eyetocenter);
	angle = acos(angle);
	adjacent = vector_magnitude(eyetocenter) * sin(angle);
	return (sqrt(-(SQUARE(sphere.radius) + SQUARE(adjacent))));
}


t_bool		intersect_sphere(t_ray ray, t_sphere* obj, t_intersect *inter)
{
	int				dist;

	if ((dist = dist_sphere_crossroad(ray, *obj)) > obj->radius)
		return (FALSE);
	inter->pos = vertex_sum(obj->pos, dist);
	return (TRUE);
}

t_sphere		*new_sphere(t_vector3 pos, unsigned int radius)
{
	t_sphere		*newsphere;

	newsphere = malloc(sizeof(t_sphere));
	newsphere->type = SPHERE;
	newsphere->pos = (t_vertex3) {.x = pos.x, .y = pos.y, .z = pos.z};
	newsphere->radius = radius;
	return (newsphere);
}
