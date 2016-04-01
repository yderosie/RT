/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vcolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:19:22 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 18:19:24 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"
#include "framework_shape/fk_objects.h"

t_color3		color_new(float r, float g, float b)
{
	t_color3	color;

	color = (t_color3) {.r = (r / 255.), .g = (g / 255.), .b = (b / 255.)};
	return (color);
}
