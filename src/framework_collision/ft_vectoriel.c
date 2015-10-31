/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:36:16 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/31 23:17:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fk_vectoriel.h>

t_vector3		vector_reverse(t_vector3 u)
{
	return ((t_vector3) {.x = -u.x, .y = -u.y, .z = -u.z});
}

int				vector_dotproduct(t_vector3 u, t_vector3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

unsigned int	vector_magnitude(t_vector3 u)
{
	return (sqrt(square(u.x) + square(u.y) + square(u.z)));
}
