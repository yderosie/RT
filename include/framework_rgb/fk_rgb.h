/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 00:30:13 by roblabla          #+#    #+#             */
/*   Updated: 2016/01/29 16:35:50 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_RGB_H
# define FK_RGB_H

/*
** Alpha blending is up to us !
*/
typedef unsigned long t_dword;
typedef struct	s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a; // TODO : reserved
}				t_rgba;

t_dword					rgba_to_dword(t_rgba rgba);
t_rgba					dword_to_rgba(t_dword color);
t_rgba					color_sum(t_rgba a, t_rgba b);
t_rgba					color_mul(t_rgba rgba, double n);
t_rgba					color_moy(unsigned int len, ...);
t_rgba					color_product(t_rgba rgba, t_rgba rgba2);

#endif
