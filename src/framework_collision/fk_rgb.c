/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:06:20 by roblabla          #+#    #+#             */
/*   Updated: 2015/12/02 20:32:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_rgb.h"
#include "framework/fk_math.h"

t_dword		rgba_to_dword(t_rgba rgba)
{
	return ((rgba.r & 0xFF) << 16) | ((rgba.g & 0xFF) << 8) | (rgba.b & 0xFF);
}

t_rgba				dword_to_rgba(t_dword color)
{
	t_rgba	rgba;

	rgba.r = ((color >> 16)) & 0xFF;
	rgba.g = ((color >> 8))  & 0xFF;
	rgba.b = (color) & 0xFF;
	return (rgba);
}

t_rgba				color_mul(t_rgba rgba, double n)
{
	t_rgba ret;

	ret.r = (ABS((rgba.r / 255.0) * n) * 255);
	ret.g = (ABS((rgba.g / 255.0) * n) * 255);
	ret.b = (ABS((rgba.b / 255.0) * n) * 255);
	return (ret);
}

t_rgba					color_product(t_rgba rgba, t_rgba rgba2)
{
	return ((t_rgba) {	(((rgba.r / 255.0) * (rgba2.r / 255.0)) * 255),
						(((rgba.g / 255.0) * (rgba2.g / 255.0)) * 255),
						(((rgba.b / 255.0) * (rgba2.b / 255.0)) * 255),
						rgba.a});
}
