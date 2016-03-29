/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:54:10 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/29 12:54:13 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_triangle.h"
#include "framework_math/fk_math.h"

t_bool			intersect_triangle(t_ray ray, t_triangle *obj, float *out)
{
	t_vector3		e1;
	t_vector3		e2;
	t_vector3		p;
	t_vector3		t;
	t_vector3		q;
	float			u;
	float			det;
	float			v;

	e1 = vector_substract(obj->pos2, obj->pos);
	e2 = vector_substract(obj->pos3, obj->pos);
	p = vector_product(ray.dir, e2);
	det = vector_dotproduct(e1, p);
	if (det > -1e-4f && det < 1e-4f)
		return (FALSE);
	det = 1.f / det;
	t = vector_substract(ray.pos, obj->pos);
	u = vector_dotproduct(t, p) * det;
	if (u< 0. || u > 1.)
		return (FALSE);
	q = vector_product(t, e1);
	v = vector_dotproduct(ray.dir, q) * det;
	if (v < 0. || (u + v) > 1.)
		return (FALSE);
	*out = vector_dotproduct(e2, q) * det;
	if (*out > 1e-4f)
		return (TRUE);
	return (FALSE);
}
