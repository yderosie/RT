/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:06:20 by roblabla          #+#    #+#             */
/*   Updated: 2015/12/17 18:12:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_rgb/fk_rgb.h"
#include "framework_math/fk_math.h"
#include <stdarg.h>

t_dword				rgba_to_dword(t_rgba rgba)
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

t_rgba				color_cpy(t_rgba b)
{
	return ((t_rgba){b.r, b.g, b.b, b.a});
}

t_rgba				color_div(t_rgba rgba, unsigned int n)
{
	t_rgba ret;

	ret.r = (unsigned int)(rgba.r / n);
	ret.g = (unsigned int)(rgba.g / n);
	ret.b = (unsigned int)(rgba.b / n);
	return (ret);
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

t_rgba					color_sum(t_rgba a, t_rgba b)
{
	return ((t_rgba){a.r + b.r, a.g + b.g, a.b + b.b, 0});
}

t_rgba					color_moy(unsigned int n, ...)
{
	va_list ap;
	unsigned int len;
	t_rgba		newcolor;

	len = n;
	ft_bzero(&newcolor, sizeof(t_rgba));
	if (len <= 0)
		return ((t_rgba){0, 0, 0, 0});
	va_start(ap, n);
	newcolor = color_cpy(va_arg(ap, t_rgba));
	while (len > 0)
		newcolor = color_sum(newcolor, va_arg(ap, t_rgba));
	va_end(ap);
	return (color_div(newcolor, n));
}
