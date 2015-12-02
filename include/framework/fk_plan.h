/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:42:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/02 21:39:40 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAN_H
# define FT_PLAN_H

#include "framework/fk_type.h"
#include "framework/fk_vertexiel.h"
#include "framework/fk_rgb.h"

typedef struct		s_plan t_plan;
struct				s_plan
{
	t_type			type;
	t_rgba			color;
	t_vertex3		pos;
	t_vector3		normal;
};


# include "framework/fk_objects.h"
# include "framework/fk_collision.h"
# include "framework/fk_vectoriel.h"
# include "framework/fk_math.h"

t_bool			intersect_plan(t_ray ray, t_plan* obj, t_intersect *inter);
t_plan			*new_plan(t_vector3 pos, unsigned int radius);

#endif
