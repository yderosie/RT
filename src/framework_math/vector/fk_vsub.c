/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vsub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:22:26 by roblabla          #+#    #+#             */
/*   Updated: 2016/01/29 01:51:04 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_sub(t_vector3 u, float r)
{
	return ((t_vector3) { .x = u.x - r, .y = u.y + r, .z = u.z + r });
}

