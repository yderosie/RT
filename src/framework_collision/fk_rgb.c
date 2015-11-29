/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:06:20 by roblabla          #+#    #+#             */
/*   Updated: 2015/11/29 15:00:45 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_rgb.h"

t_dword		rgba_to_dword(t_rgba rgba)
{
	return ((rgba.a << 24) |
			(rgba.r << 16) |
			(rgba.g << 8) |
			(rgba.a));
}

t_rgba				dword_to_rgba(t_dword color)
{
	t_rgba	rgba;

	rgba.a = ((color >> 24)) & 0xFF;
	rgba.r = ((color >> 16)) & 0xFF;
	rgba.g = ((color >> 8))  & 0xFF;
	rgba.b = (color) & 0xFF;
	return (rgba);
}
