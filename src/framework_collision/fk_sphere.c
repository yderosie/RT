/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/26 17:40:05 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include <stdlib.h>
#include <ft_printf.h>

#define DPI (PI - (PI / 2))
#define RAD_TO_DEGREES(X) (((X) * 180) / PI)
#define ABS(X) (X) < 0 ? -(X) : (X)

static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	double			angle;
	double			eyetocenter;
	double			opposite;
	double			eyetoa;
	double			atob;

	dprintf(2, C_CYAN"Ray: pos{%f, %f, %f} dir{%f, %f, %f}\nSphere {%f, %f, %f}\n"C_NONE, ray.pos.x, ray.pos.y,ray.pos.z,ray.dir.x, ray.dir.y,ray.dir.z,sphere.pos.x, sphere.pos.y,sphere.pos.z);
	eyetocenter = sqrt(SQUARE((sphere.pos.x - ray.pos.x)) + SQUARE((sphere.pos.y - ray.pos.y)));
	angle = ABS(atan(ray.dir.y / ray.dir.x));
	angle -= acos (ABS(sphere.pos.x) / eyetocenter);
	dprintf(2, "2) Angle suite acos %f degrees et %f radian\n", RAD_TO_DEGREES(angle), angle);
	dprintf(2, "eyetocenter = %f \n ", eyetocenter);
	if ((opposite = sin(angle) * eyetocenter) > sphere.radius)
		return (FALSE);
	dprintf(2, "opposite suite pythagore %f\n", opposite);
	dprintf(2, "Radius : %f\n", sphere.radius);
	eyetoa = cos (angle) * eyetocenter;
	atob = sqrt(SQUARE(sphere.radius) - SQUARE(opposite));
	dprintf(2, "lecture de eyetoa : %f et lecture de atob : %f\n", eyetoa, atob);
	i->pos = vector_scale(ray.dir, (eyetoa - atob));
	dprintf(2, C_GREEN"test du point B: pos{%f, %f, %f} \n"C_NONE, i->pos.x, i->pos.y, i->pos.z);
	return (opposite > sphere.radius ? FALSE : TRUE);
}


t_bool		intersect_sphere(t_ray ray, t_sphere* obj, t_intersect *inter)
{
	return (sphere_crossroad(ray, *obj, inter));
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
