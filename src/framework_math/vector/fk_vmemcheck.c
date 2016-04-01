/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vmemcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:21:32 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/29 12:23:04 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

int			vector_check(t_vector3 v, t_vector3 u)
{
	return ((v.x == u.x && v.y == u.y && v.z == u.z));
}
