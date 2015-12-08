/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:42:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 11:41:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAN_H
# define FT_PLAN_H

# include "framework_shape/fk_type.h"
# include "framework_math/fk_vector.h"
# include "framework_rgb/fk_rgb.h"

typedef struct		s_plan t_plan;
struct				s_plan
{
	t_type			type;
	t_rgba			color;
	t_vertex3		pos;
	t_vector3		normal;
};


# include "framework_shape/fk_objects.h"
# include "framework_collision/fk_collision.h"
# include "framework_math/fk_math.h"

t_bool			intersect_plan(t_ray ray, t_plan* obj, t_intersect *inter);
t_plan			*new_plan(t_vector3 pos, unsigned int radius);

#endif
