/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:19:03 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/09 11:24:40 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_cylinder.h"
#include "framework_math/fk_math.h"

void		normal_cylinder(t_intersect *inter, t_cylinder *obj)
{
	float		m;
	t_vector3	tmp;

	m = vector_dotproduct(inter->ray.dir, obj->dir);
	m += vector_dotproduct(vector_unit(vector_substract(inter->ray.pos,
		obj->pos)), obj->dir);
	if (m < 0)
		m = 0;
	tmp = vector_sum(vector_substract(inter->ray.pos, obj->pos),
		inter->ray.dir);
	tmp = vector_unit(vector_substract(tmp, vector_mul(obj->dir, m)));
	if (vector_dotproduct(inter->ray.dir, vector_unit(tmp)) < 0)
		inter->v_normal = vector_mul(vector_unit(tmp), -1);
	inter->v_normal = tmp;
}
