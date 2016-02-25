/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_cone.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:27:51 by yderosie          #+#    #+#             */
/*   Updated: 2016/02/24 16:04:35 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONE_H
# define FT_CONE_H

# include "libft.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"


typedef struct		s_cone t_cone;
struct				s_cone
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	float			diffuse;
	t_bool			light;
	t_vertex3		pos;
	t_vector3		dir;
	float			radius;
	float			height;
};

t_bool			intersect_cone(t_ray ray, t_cone* obj, float *dist);

#endif
