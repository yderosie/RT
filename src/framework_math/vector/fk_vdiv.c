/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vectoriel_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:21:42 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:52:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_div(t_vector3 u, float r)
{
	return ((t_vector3) {	.x = u.y / r,
							.y = u.z / r,
							.z = u.x / r});
}
