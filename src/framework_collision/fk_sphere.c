/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/26 23:45:06 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include "framework/fk_vectoriel.h"
#include <stdlib.h>
#include <ft_printf.h>

#define DPI (PI - (PI / 2))
#define RAD_TO_DEGREES(X) (((X) * 180) / PI)
#define ABS(X) (X) < 0 ? -(X) : (X)

static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	t_vector3		v_eyetocenter;
	double			d_ray;
	double			d_radius;
	double			tmp;

	dprintf(2, "affichage init : ray pos{%f, %f, %f} dir{%f, %f, %f} et sphere pos{%f, %f, %f} sphereRad %f",
			ray.pos.x ,ray.pos.y ,ray.pos.z ,ray.dir.x ,ray.dir.y ,ray.dir.z ,sphere.pos.x ,sphere.pos.y ,sphere.pos.z ,sphere.radius );
	v_eyetocenter = vector_substract (ray.pos, sphere.pos);
	dprintf(2, "test de eyetocenter : {%f, %f, %f} sphereRadius %f\n", v_eyetocenter.x, v_eyetocenter.y, v_eyetocenter.z, sphere.radius);
	d_ray = vector_dotproduct(v_eyetocenter, ray.dir);
	dprintf(2, "test de d_ray : %f\n", d_ray);
	if (d_ray < 0)
		return (dprintf(2, C_CYAN"on retourne d_ray < 0\n"C_NONE), FALSE);
	tmp = vector_dotproduct(v_eyetocenter, v_eyetocenter) - pow(d_ray, 2.0);
	dprintf(2, "test de tmp : %f\n", tmp);
	d_radius = (double)sqrt(ABS(pow(sphere.radius, 2.0) - tmp));
	if (d_radius > sphere.radius)
		return (dprintf(2, C_CYAN"on retourne d_radius > sphere.radius\n"C_NONE), FALSE);
	dprintf(2, "test de tmp final : %f et radius %f\n", tmp, d_radius);
	tmp = d_ray - d_radius;
	dprintf(2, "test de d_ray : %f et radius %f et tmp %f\n", d_ray, d_radius, tmp);
	tmp = d_ray - d_radius;
	i->pos = (t_vertex3)vector_sum(ray.pos, vector_scale(ray.dir, tmp));
	dprintf(2, C_GREEN"test de l'intersection : {%f, %f, %f}\n"C_NONE, i->pos.x, i->pos.y, i->pos.z);
	exit(0);
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
