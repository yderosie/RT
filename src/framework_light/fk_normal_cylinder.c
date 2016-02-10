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


t_vector3		normal_cylinder(t_ray ray, t_vector3 inter, t_cylinder *obj)
{
	float		m;
	float		len;
	t_vector3	tmp;

	len = vector_magnitude(vector_substract(inter, ray.pos));
	m = vector_dotproduct(ray.dir, obj->dir) * len;
	m += vector_dotproduct(vector_substract(ray.pos, obj->pos), obj->dir);
	tmp = vector_substract(inter, obj->pos);
	tmp = vector_unit(vector_substract(tmp, vector_mul(obj->dir, m)));
	return (tmp);
}
