/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:57:54 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/04 14:57:55 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "framework_collision/fk_collision.h"
# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"
# include "ft_env.h"

typedef struct	s_perlin
{
	int			xx;
	int			yy;
	int			zz;
	int			a;
	int			b;
	int			aa;
	int			ab;
	int			ba;
	int			bb;
	double		u;
	double		v;
	double		w;
}				t_perlin;

t_color3		checkerboard(t_vertex3 pos);
double			perlin_noise(double x, double y, double z);

#endif
