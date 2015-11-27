/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/27 16:21:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include "framework/fk_vectoriel.h"
#include <stdlib.h>
#include <ft_printf.h>


static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	t_vector3		v_eyetocenter;
	double			d_ray;
	double			d_radius;
	double			tmp;

	v_eyetocenter = vector_substract (sphere.pos, ray.pos);
	d_ray = vector_dotproduct(v_eyetocenter, ray.dir);
	if (d_ray < 0)
		return (FALSE);
	tmp = vector_dotproduct(v_eyetocenter, v_eyetocenter) - pow(d_ray, 2.0);
	d_radius = sqrt(ABS(pow(sphere.radius, 2.0) - tmp));
	if (d_radius > sphere.radius)
		return (FALSE);
	tmp = d_ray - d_radius;
	tmp = d_ray - d_radius;
	i->pos = (t_vertex3)vector_sum(ray.pos, vector_scale(ray.dir, tmp));
	//Calcul v_light non teste !!!!!!
	i->v_light = vector_substract(sphere.pos, i->pos);
	i->v_light = vector_div(i->v_light, vector_magnitude(i->v_light));
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
