/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vsub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:22:26 by yderosie          #+#    #+#             */
/*   Updated: 2016/02/04 14:40:40 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_sub(t_vector3 u, float r)
{
	return ((t_vector3) { .x = u.x - r, .y = u.y - r, .z = u.z - r });
}
