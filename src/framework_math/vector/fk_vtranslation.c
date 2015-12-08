/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:51:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:52:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vertex3		vector_translation(t_vector3 u, t_vertex3 v)
{
	return ((t_vertex3) {.x = u.x + v.x, .y = u.y + v.y, .z = u.z + v.z});
}
