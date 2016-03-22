/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/13 23:41:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_sphere.h"
#include "framework_math/fk_math.h"

t_bool			intersect_sphere(t_ray ray, t_sphere *obj, float *t)
{
	t_vector3		etoc;
	float			radius;
	float			vector_radius;

	etoc = vector_substract(obj->pos, ray.pos);
	if ((vector_radius = vector_dotproduct(etoc, ray.dir)) < 0.)
		return (FALSE);
	*t = vector_dotproduct(etoc, etoc) - SQUARE(vector_radius);
	if (*t > (radius = SQUARE(obj->radius)))
		return (FALSE);
	*t = sqrt(radius - *t);
	*t = FT_MIN((vector_radius - *t), (vector_radius + *t));
	return (TRUE);
}
