/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/29 22:28:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include "framework/fk_vectoriel.h"
#include <stdlib.h>
#include <ft_printf.h>


static double	min_positif(double a, double b)
{
	if (a > 0 && b > 0)
		return (a < b ? a : b);
	else if (a < 0 && b > 0)
		return (b);
	else if (b < 0 && a > 0)
		return (a);
	return (-1);
}
/**/
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
	i->pos = vector_sum(ray.pos, vector_scale(ray.dir, tmp));
	dprintf(2, "position de l'intersect : {%f, %f, %f}\n", i->pos.x, i->pos.y, i->pos.z);
	//Calcul v_light non teste !!!!!!
	i->v_light = vector_substract(sphere.pos, i->pos);
	i->v_light = vector_div(i->v_light, vector_magnitude(i->v_light));
	i->v_light = vector_unit(i->v_light);
	dprintf(2, "position de l'intersect : {%f, %f, %f}\n", i->v_light.x, i->v_light.y, i->v_light.z);
	//i->v_light = vector_unit(vector_substract(i->pos, sphere.pos));
	return (TRUE);
}
/**/
/*
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
	tmp = pow(vector_magnitude(v_eyetocenter), 2.0) - pow(d_ray, 2.0);
	if (tmp > (d_radius = pow(sphere.radius, 2.0)))
		return (FALSE);
	if ((tmp = min_positif((d_ray + sqrt(tmp)), (d_ray - sqrt(tmp)))) < 0)
		return (FALSE);
	i->pos = vector_mul(ray.pos, tmp);
	i->v_light = vector_unit(vector_substract(sphere.pos, i->pos));
	return (TRUE);
}
*/

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
