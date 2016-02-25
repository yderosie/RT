/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/24 16:04:11 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPHERE_H
# define FT_SPHERE_H

# include "libft.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"


typedef struct		s_sphere t_sphere;
struct				s_sphere
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	float			diffuse;
	t_bool			light;
	t_vertex3		pos;
	t_vector3		dir;
	float			radius;
};

t_bool			intersect_sphere(t_ray ray, t_sphere* obj, float *dist);

#endif
