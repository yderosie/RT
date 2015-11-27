/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:36:16 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/27 15:21:24 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vectoriel.h"
#include "framework/fk_math.h"
#include <math.h>

t_vector3		vector_reverse(t_vector3 u)
{
	return ((t_vector3) {.x = -u.x, .y = -u.y, .z = -u.z});
}

double			vector_dotproduct(t_vector3 u, t_vector3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double			vector_magnitude(t_vector3 u)
{
	return (sqrt(ABS(SQUARE(u.x) + SQUARE(u.y) + SQUARE(u.z))));
}
