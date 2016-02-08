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


t_vector3		normal_cone(t_vector3 inter, t_cone *obj)
{
	t_vector3	v_normal;

	v_normal.x = inter.x - obj->pos.x;
	v_normal.y = 0;
	v_normal.z = inter.z = obj->pos.z;
	v_normal = vector_unit(v_normal);
	return (vector_div(v_normal, obj->radius));
}
