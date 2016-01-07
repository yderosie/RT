/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:45:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/21 11:28:52 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_COLLISION_H
# define FK_COLLISION_H

# include "framework_rgb/fk_rgb.h"
# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"

#include "ft_env.h"
/*
** ****************************************************************************
** fk_collision.c
** ****************************************************************************
*/
void		ft_trace_ray(t_env env, t_ray ray, t_rgba *color);
void		ft_render(t_env env);

/*
** ****************************************************************************
** fk_ray.c
** ****************************************************************************
*/
t_ray				ray_new(t_vertex3 v, t_vector3 dir);
t_ray				ray_modif_pos(t_ray ray, t_vertex3 v);
t_ray				ray_modif_dir(t_ray ray, t_vector3 v);

#endif
