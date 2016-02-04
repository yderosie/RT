/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:42:15 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/03 19:36:19 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAN_H
# define FT_PLAN_H

# include "libft.h"
# include "framework_shape/fk_type.h"
# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"


typedef struct		s_plan t_plan;
struct				s_plan
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	t_vertex3		pos;
	t_vector3		normal;
};

t_bool			intersect_plan(t_ray ray, t_plan* obj, float *t);

#endif
