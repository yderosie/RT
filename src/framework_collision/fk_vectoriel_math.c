/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel_math.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:37:32 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/31 23:19:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fk_vectoriel.h>

t_vector3		vector_substract(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) {.x = u.x - v.x, .y = u.y - v.y, .z = u.z - v.z});
}

t_vector3		vector_sum(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) {.x = u.x + v.x, .y = u.y + v.y, .z = u.z + v.z});
}

t_vector3		vector_product(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) {.x = u.x * v.x, .y = u.y * v.y, .z = u.z * v.z});
}
