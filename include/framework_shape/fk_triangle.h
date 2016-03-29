/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_triangle.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:08:28 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/29 15:08:30 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_TRIANGLE_H
# define FK_TRIANGLE_H

# include "libft.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"

typedef struct s_triangle	t_triangle;
struct				s_triangle
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	float			diffuse;
	float			specular;
	t_bool			light;
	t_vertex3		pos;
	t_vector3		dir;
	t_vertex3		pos2;
	t_vertex3		pos3;
};

t_bool				intersect_triangle(t_ray ray, t_triangle *obj, float *dist);

#endif

