/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 22:32:53 by yderosie          #+#    #+#             */
/*   Updated: 2016/02/03 18:47:07 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_ray.h"
#include "framework_math/fk_vector.h"
#include "framework_math/fk_math.h"
#include "framework_collision/fk_collision.h"

t_vector3		create_intersect(t_ray ray, float dist)
{
	return (vector_sum(ray.pos, vector_mul(ray.dir, dist)));
}
