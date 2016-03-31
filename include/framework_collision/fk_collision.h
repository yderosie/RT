/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:45:47 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 02:40:16 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_COLLISION_H
# define FK_COLLISION_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"
# include "parser.h"
# include "ft_env.h"

/*
** ****************************************************************************
** fk_collision.c
** ****************************************************************************
*/
t_color3	ft_trace_ray(t_object *arr, t_ray ray, int depth, t_env env);
void		ft_render(t_env env);
t_ray		ray_calc(t_env env, float offsetx, float offsety);

/*
** ****************************************************************************
** fk_color.c
** ****************************************************************************
*/
t_color3	ft_get_pixel_to_image(t_img img, int x, int y);
void		ft_put_pixel_to_image(t_img img, int x, int y, t_color3 color);
t_color3	process_color(t_object *arr, t_intersect it, t_env env, int depth);
t_color3	getfinalcolor(t_object *arr, t_intersect inter, t_env env);
t_color3	xyz_to_lab(t_color3 color);

/*
** ****************************************************************************
** fk_createscene.c
** ****************************************************************************
*/
void		fill_arr(t_value val, int idx, t_object *data);
void		create_scene(t_value val, t_env *env);

/*
** ****************************************************************************
** fk_reflection.c
** ****************************************************************************
*/
t_ray		create_reflection(t_ray ray, t_intersect inter);

/*
** ****************************************************************************
** fk_antialiasing.c
** ****************************************************************************
*/
void		antialiasing(t_env env);
t_color3	sampling(t_env env, int i);

/*
** ****************************************************************************
** fk_routine.c
** ****************************************************************************
*/
void		*routine_render(void *arg);
void		*routine_aliasing(void *arg);
#endif
