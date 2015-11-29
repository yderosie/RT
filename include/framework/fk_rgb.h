/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_rgb.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 00:30:13 by roblabla          #+#    #+#             */
/*   Updated: 2015/11/29 15:30:46 by mbarbari         ###   ########.fr       */
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
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_rgba;

t_dword					rgba_to_dword(t_rgba rgba);
t_rgba					dword_to_rgba(t_dword color);

#endif
