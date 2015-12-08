/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:51:08 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:51:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_scale(t_vector3 v, float f)
{
	return (t_vector3) { .x = v.x * f, .y = v.y * f, .z = v.z * f };
}
