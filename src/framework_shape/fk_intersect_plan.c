/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/27 15:07:14 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_plan.h"
#include "framework_math/fk_math.h"

#define EPSILON 0.00001

t_bool			intersect_plan(t_ray ray, t_plan *plan, float *t)
{
	float		m;
	float		d;
	t_vector3	pos;

	pos = vector_substract(ray.pos, plan->pos);
	m = vector_dotproduct(plan->normal, pos);
	d = vector_dotproduct(plan->normal, ray.dir);
	*t = -m / d;
	if (*t < 0.)
		return (FALSE);
	return (TRUE);
}

static t_bool			intersect_triangle(t_ray ray, t_fplan *obj, float *out)
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

static t_bool			intersect_triangle2(t_ray ray, t_fplan *obj, float *out)
{
	t_vector3		e1;
	t_vector3		e2;
	t_vector3		p;
	t_vector3		t;
	t_vector3		q;
	float			u;
	float			det;
	float			v;

	e1 = vector_substract(obj->pos2, obj->pos4);
	e2 = vector_substract(obj->pos3, obj->pos4);
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

t_bool			intersect_finished_plan(t_ray ray, t_fplan *plan, float *t)
{
	t_bool 	b1;
	t_bool	b2;
	float	ttmp;

	b1 = intersect_triangle(ray, plan, t);
	if (b1)
		ttmp = *t;
	b2 = intersect_triangle2(ray, plan, t);
	if (b1 || b2)
	{
		if (b1)
			*t = ttmp;
		return (TRUE);
	}
	else
		return (FALSE);
}
