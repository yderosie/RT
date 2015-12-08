/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:37:37 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:38:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vectoriel.c"

t_vector3		vector_reverse(t_vector3 u)
{
	return ((t_vector3) {.x = -u.x, .y = -u.y, .z = -u.z});
}

