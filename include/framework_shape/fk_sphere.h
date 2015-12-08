/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 11:55:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPHERE_H
# define FT_SPHERE_H

# include "framework_shape/fk_type.h"
# include "framework_rgb/fk_rgb.h"
# include "framework_math/fk_vector.h"

typedef struct		s_sphere t_sphere;
struct				s_sphere
{
	t_type			type;
	t_rgba			color;
	t_vertex3		pos;
	float			radius;
};


# include "framework_shape/fk_objects.h"
# include "framework_collision/fk_collision.h"
# include "framework_math/fk_math.h"

t_bool			intersect_sphere(t_ray ray, t_sphere* obj, t_intersect *inter);
t_sphere		*new_sphere(t_vector3 pos, unsigned int radius);
void			modif_sphere(t_sphere *obj, t_sphere modify);

#endif
