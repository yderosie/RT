/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:32:26 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/27 17:53:44 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_LIGHT_H
# define FK_LIGHT_H

# include "framework_shape/fk_type.h"
# include "framework_rgb/fk_rgb.h"
# include "framework_math/fk_vector.h"
# include "framework_collision/fk_collision.h"

typedef struct s_spotlight		t_spotlight;
struct				s_spotlight
{
	t_type			type;
	t_rgba			color;
	float			reflection_index;
	t_vertex3		pos;
	t_vector3		dir;
	float			intensity;
};

t_rgba				iter_light(t_intersect inter, t_spotlight *light);
#endif
