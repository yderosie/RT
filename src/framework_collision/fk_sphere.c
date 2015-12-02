/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/02 22:50:08 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include "framework/fk_vectoriel.h"
#include <stdlib.h>
#include <ft_printf.h>

static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	t_vector3		etoc;
	double			d[2];
	double			d_hc;
	double			perp;
	double			radius;

	etoc = vector_substract(sphere.pos, ray.pos);
	if ((d[0] = vector_dotproduct(etoc, ray.dir)) < 0.0)
		return (FALSE);
	perp = vector_dotproduct(etoc, etoc) - SQUARE(d[0]);
	if (perp > (radius = SQUARE(sphere.radius)))
		return (FALSE);
	d[1] = sqrt(radius - perp);
	d[1] = FT_MIN((d[0] - d[1]), (d[0] + d[1]));
	i->pos = vector_sum(ray.pos, vector_scale(ray.dir, d[1]));
	i->v_light = vector_substract (i->pos, sphere.pos);
	d[1] = vector_dotproduct(i->v_light, i->v_light);
	d[1] = 1.0 / sqrt(d[1]);
	i->v_light = vector_scale(i->v_light, d[1]);
	return (TRUE);
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
