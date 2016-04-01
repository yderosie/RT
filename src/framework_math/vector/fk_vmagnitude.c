/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:36:16 by yderosie          #+#    #+#             */
/*   Updated: 2015/12/23 21:01:08 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"
#include "framework_math/fk_math.h"

float			vector_magnitude(t_vector3 u)
{
	return (sqrt(ABS(SQUARE(u.x) + SQUARE(u.y) + SQUARE(u.z))));
}
