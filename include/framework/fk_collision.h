/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:45:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/29 15:35:53 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_COLLISION_H
# define FK_COLLISION_H

# include <fk_objects.h>

typedef struct		s_intersect t_intersect;
typedef struct		s_ray t_ray;

struct				s_ray
{
	t_vertex3		position;
	t_vector3		direction;
};

struct				s_intersect
{
	t_vertex3		pos;
	unsigned int	radius;
};

int			ft_ray_tracer(t_ray ray, t_objects *obj);


#endif
