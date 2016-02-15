/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:49:00 by barbare           #+#    #+#             */
/*   Updated: 2016/02/03 18:49:02 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_mul(t_vector3 v, float f)
{
	return (t_vector3) { .x = v.x * f, .y = v.y * f, .z = v.z * f };
}
