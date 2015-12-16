/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:18:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/15 18:43:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_sphere.h"
#include "framework_math/fk_math.h"

t_vector3		normal_sphere(t_vector3 inter, t_sphere *obj)
{
	t_vector3	v_normal;
	float		mod;

	v_normal = vector_substract(inter, obj->pos);
	mod = vector_dotproduct(v_normal, v_normal);
	v_normal = vector_scale(v_normal, 1 / sqrt(mod));
	return (v_normal);
}
