/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/23 21:04:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_cylinder.h"
#include "framework_math/fk_math.h"

t_bool			intersect_cylinder(t_ray ray, t_cylinder* obj, float *t)
{
	t_vector3	dir;
	t_vector3	cross;
	t_vector3	raydir;
	t_vector3	e;
	float		dist_cross;
	float		alpha;

	dir = vector_substract(ray.pos, obj->pos);
	cross = vector_product(ray.dir, obj->dir);
	dist_cross = vector_dotproduct(cross, cross);
	if (dist_cross == 0.)
	{
		alpha = vector_dotproduct(dir, obj->dir);
		raydir = vector_substract(dir, vector_scale(obj->dir, alpha));
		if ((alpha = vector_dotproduct(raydir, raydir)) > SQUARE(obj->radius))
			return (FALSE);
		*t = FLT_MAX - 1;
		return (dprintf(2, "test de longueur 1 du cylindre : %f\n", *t), TRUE);
	}
	cross = vector_div(cross, sqrt(dist_cross));
	if ((alpha = vector_dotproduct(dir, cross)) > obj->radius)
		return (FALSE);
	e = vector_product(dir, obj->dir);
	*t = -vector_dotproduct(e, vector_div(cross, sqrt(dist_cross)));
	e = vector_unit(vector_product(cross, obj->dir));
	alpha = sqrt(SQUARE(obj->radius) - SQUARE(alpha));
	alpha /= vector_dotproduct(ray.dir, e);
	*t = FT_MIN((*t - alpha), (*t + alpha));
	return (dprintf(2, "test de longueur 2 du cylindre : %f\n", *t), TRUE);
}

