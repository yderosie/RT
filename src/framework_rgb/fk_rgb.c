/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:06:20 by roblabla          #+#    #+#             */
/*   Updated: 2016/01/29 18:24:34 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_rgb/fk_rgb.h"
#include "framework_math/fk_math.h"
#include <stdio.h>
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

t_rgba				color_div(t_rgba rgba, unsigned int n)
{
	rgba.r = rgba.r / n;
	rgba.g = rgba.g / n;
	rgba.b = rgba.b / n;
	rgba.a = rgba.a / n;
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

t_rgba					color_sum(t_rgba a, t_rgba b)
{
	return ((t_rgba){	FT_MIN(a.r + b.r, 255),
						FT_MIN(a.g + b.g, 255),
						FT_MIN(a.b + b.b, 255),
						FT_MIN(a.a + b.a, 255)});
}

t_rgba					color_moy(unsigned int len, ...)
{
	va_list ap;
	unsigned int n;
	t_rgba		tmp;
	t_rgba		newcolor;

	if (len == 0)
		return ((t_rgba){0, 0, 0, 0});
	va_start(ap, len);
	ft_bzero(&newcolor, sizeof(t_rgba));
	n = 0;
	while (n < len)
	{
		tmp = va_arg(ap, t_rgba);
		newcolor.r += tmp.r;
		newcolor.g += tmp.g;
		newcolor.b += tmp.b;
		newcolor.a += tmp.a;
		n++;
	}
	newcolor = color_div(newcolor, len);
	va_end(ap);
	return (newcolor);
}

t_rgba				color_canonicalize(t_rgba c)
{
	return ((t_rgba) {
		FT_MIN(c.r, 255),
		FT_MIN(c.g, 255),
		FT_MIN(c.b, 255),
		FT_MIN(c.a, 255)
	});
}
