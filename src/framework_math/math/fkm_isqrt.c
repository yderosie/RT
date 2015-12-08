/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:07:51 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:19:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_math.h"

float	fk_isqrt(float nbr)
{
	long				i;
	float				x1;
	float				y;
	static const float	threehalfs = 1.5F;

	x1 = nbr * 0.5F;
	y  = nbr;
	i  = * ( long * ) &y;
	i  = 0x5f375a86 - ( i >> 1 );
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x1 * y * y ) );

	return (y);
}
