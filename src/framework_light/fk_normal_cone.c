/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:22:25 by yderosie          #+#    #+#             */
/*   Updated: 2016/01/27 16:30:39 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_cone.h"
#include "framework_math/fk_math.h"

void		normal_cone(t_intersect *inter, t_cone *obj)
{
	t_vector3	tmp;
	t_vector3	v;
	float		m;

	v.x = inter->pos.x - obj->pos.x;
	v.y = 0;
	v.z = inter->pos.z - obj->pos.z;
	m = sqrtf(SQUARE(v.x) + SQUARE(v.z));
	v.x /= m;
	v.y /= m;
	v.z /= m;
	tmp.x = v.x * obj->height / obj->radius;
	tmp.y = v.y * obj->height / obj->radius;
	tmp.z = v.z * obj->height / obj->radius;
	inter->v_normal = vector_unit(vector_mul(tmp, -1));
}
