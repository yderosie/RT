/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:36:16 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:39:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vectoriel.h"
#include "framework/fk_math.h"
#include <math.h>

float			vector_magnitude(t_vector3 u)
{
	return (sqrt(ABS(SQUARE(u.x) + SQUARE(u.y) + SQUARE(u.z))));
}
