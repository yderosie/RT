/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:06:20 by roblabla          #+#    #+#             */
/*   Updated: 2015/11/30 22:06:55 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_rgb.h"

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
