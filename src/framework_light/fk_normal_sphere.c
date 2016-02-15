/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:18:56 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/23 16:32:26 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_sphere.h"
#include "framework_math/fk_math.h"

t_vector3		normal_sphere(t_ray ray, t_vector3 inter, t_sphere *obj)
{
	t_vector3	v_normal;

	(void)ray;
	v_normal = vector_substract(obj->pos, inter);
	return (vector_unit(v_normal));
}
