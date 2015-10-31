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

#include <ft_sphere.h>

int			dist_sphere_crossroad(t_ray ray, t_sphere sphere)
{
	int				angle;
	t_vector3		eyetocenter;
	unsigned int	adjacent;

	eyetocenter = (t_vector3) { ray.pos.x - sphere.pos.x,
								ray.pos.y - sphere.pos.y,
								ray.pos.z - sphere.pos.z };
	angle = vector_dotproduct(ray.dir, eyetocenter);
	angle = acos(angle);
	adjacent = vector_magnitude(spheretocenter * sin(angle));
	return (sqrt(-(SQUARE(sphere.radius) + SQUARE(adjacent))));
}


t_bool		intersect_sphere(t_ray ray, void* obj, t_intersect *inter)
{
	int	dist_crossroad;

	if ((dist_crossroad = dist_crossroad(ray, (t_sphere)&obj)) > obj->radius)
		return (FALSE);
	inter->position = vertex_sum(obj->position, dist_crossroad);
	return (TRUE);
}

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
