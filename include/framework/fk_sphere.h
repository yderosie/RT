/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 21:18:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPHERE_H
# define FT_SPHERE_H

# include <fk_objects.h>
# include <fk_collision.h>
# include <fk_vectoriel.h>
# include <fk_vertexiel.h>
# include <fk_math.h>

struct				s_sphere
{
	e_type			type;
	t_vertex3		position;
	float			radius;
};

int				dist_sphere_crossroad(t_ray ray, t_sphere sphere);
t_bool			intersect_sphere(t_ray ray, void* obj, t_intersect *inter);
t_sphere		*new_sphere(t_vector pos, unsigned int radius);
void			modif_sphere(t_sphere *obj, t_sphere modify);

#endif
