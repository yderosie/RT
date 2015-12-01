/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/01 14:12:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include "framework/fk_vectoriel.h"
#include <stdlib.h>
#include <ft_printf.h>


static double	min_positif(double a, double b)
{
	if (a < 0 || b < 0)
		return (-1);
	if (a < b)
		return (a);
	return (b);
}
/**/
static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	t_vector3		v_eyetocenter;
	double			d_ray;
	double			l_eyetocenter;
	double			opposite;
	double			t;

	v_eyetocenter = vector_substract (sphere.pos, ray.pos);
	d_ray = vector_dotproduct(v_eyetocenter, ray.dir);
	l_eyetocenter = vector_dotproduct(v_eyetocenter, v_eyetocenter);
	if (d_ray < 0 && l_eyetocenter > SQUARE(sphere.radius))
		return (FALSE);
	if ((opposite = l_eyetocenter - SQUARE(d_ray)) > SQUARE(sphere.radius))
		return (FALSE);
	t = sqrt(SQUARE(sphere.radius) - opposite);
	if (l_eyetocenter > SQUARE(sphere.radius))
		t = d_ray - t;
	else
		t = d_ray + t;
	i->pos = vector_sum(ray.pos, vector_scale(ray.dir, t));
	i->v_light = vector_unit(vector_div(vector_sum(i->pos, sphere.pos), sphere.radius));
	dprintf(2, " direction : (%f, %f, %f)\n sphere.radius %f et sqrt radius %f\n veyecenter : (%f, %f, %f)\n  lveyecenter %f\n d_ray %f\n opposite %f\n t : %f \n vintersect : (%f, %f, %f)\n normal (%f, %f, %f)\n",
			ray.dir.x, ray.dir.y, ray.dir.z,
			sphere.radius, SQUARE(sphere.radius),
			v_eyetocenter.x, v_eyetocenter.y, v_eyetocenter.z,
			l_eyetocenter,
			d_ray,
			opposite,
			t,
			i->pos.x, i->pos.y, i->pos.z,
			i->v_light.x, i->v_light.y, i->v_light.z);
	//exit(0);
	return (TRUE);
}
/**/
static t_bool	sphere_crossroad2(t_ray ray, t_sphere sphere, t_intersect *i)
{
	double tmp;
	double tmp2;
	double delta;
	t_vector3	dray;

	dray = vector_substract(sphere.pos, ray.pos);
	tmp = vector_dotproduct(dray, ray.dir);
	tmp2 = vector_dotproduct(dray, dray) - (sphere.radius * sphere.radius);
	if ((delta = ((tmp * tmp) - tmp2)) < 0.0)
		return (dprintf(2, "Delta < 0.0 : %f\n", delta), FALSE);
	if (delta != 0)
	{
		delta = (double)sqrt(delta);
		if ((tmp2 = min_positif((-(-tmp + delta)), -((-tmp - delta)))) < 0)
			return (dprintf(2, "valeur < 0 pour le calcul du point : (%f) && (%f)\n", (-tmp + delta), (-tmp - delta)), FALSE);
	}
	else
		tmp2 = (-tmp);
	i->pos = vector_sum(ray.pos, vector_scale(ray.dir, tmp2));
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
