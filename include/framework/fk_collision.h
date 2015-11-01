/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:45:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 20:34:07 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_COLLISION_H
# define FK_COLLISION_H

# include <fk_objects.h>

typedef struct		s_intersect t_intersect;
typedef struct		s_ray t_ray;

struct				s_ray
{
	t_vertex3		pos;
	t_vector3		dir;
};

struct				s_intersect
{
	t_vertex3		pos;
	unsigned int	radius;
};

/*
** ****************************************************************************
** fk_collision.c
** ****************************************************************************
*/
t_intersect	nearest_vertex(t_ray ray, t_intersect new, t_intersect old);
t_bool		ft_throwing_ray(t_env env, t_ray ray, t_intersect *inter);
void		ft_render(t_env env, t_object objs);

/*
** ****************************************************************************
** fk_ray.c
** ****************************************************************************
*/
t_ray		ray_new(t_vertex3 v, t_vector3 dir);
t_ray		ray_modif_pos(t_ray ray, t_vertex3 v);
t_ray		ray_modif_dir(t_ray ray, t_vector3 v);

#endif
