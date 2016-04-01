/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector_dotproduct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:38:56 by yderosie          #+#    #+#             */
/*   Updated: 2015/12/08 13:39:33 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

float			vector_dotproduct(t_vector3 u, t_vector3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
