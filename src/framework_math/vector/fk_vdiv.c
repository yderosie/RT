/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vectoriel_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:21:42 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/09 13:47:05 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_div(t_vector3 u, float r)
{
	return ((t_vector3) {	.x = u.x / r,
							.y = u.y / r,
							.z = u.z / r});
}
