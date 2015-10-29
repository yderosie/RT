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

typedef struct	s_camera t_camera;

struct			s_camera;
{
	unsigned int	angular;
	t_position		position;
	t_rotation		rotation;

};

int			ft_ray_tracer(t_camera cam, t_objects *obj);


#endif
