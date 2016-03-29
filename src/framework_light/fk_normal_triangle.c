/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:54:40 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/29 12:54:42 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_triangle.h"
#include "framework_math/fk_math.h"

void		normal_triangle(t_intersect *inter, t_triangle *obj)
{
	t_vector3 v1;
	t_vector3 v2;
	t_vector3 v3;

	v1 = vector_substract(obj->pos2,obj->pos);
	v2 = vector_substract(obj->pos3,obj->pos);
	v3 = vector_product(v1,v2);
	inter->v_normal = vector_unit(v3);
	dprintf(2, "Lecture de la normal : {%f %f %f}\n", inter->v_normal.x, inter->v_normal.y, inter->v_normal.z);
}
