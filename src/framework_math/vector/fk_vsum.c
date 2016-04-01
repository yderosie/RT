/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:41:39 by yderosie          #+#    #+#             */
/*   Updated: 2015/12/07 18:42:05 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_sum(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) { .x = u.x + v.x, .y = u.y + v.y, .z = u.z + v.z });
}
