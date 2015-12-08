/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:32:26 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 10:30:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_LIGHT
# define FK_LIGHT
# include "framework_shape/fk_type.h"
# include "framework_rgb/fk_rgb.h"
# include "framework_math/fk_vector.h"

typedef struct		s_spotlight		t_spotlight;
struct				s_spotlight
{
	t_type			type;
	t_rgba			color;
	t_vertex3		pos;
	float			radius;
	float			intensity;
};

# include "framework_shape/fk_objects.h"
# include "framework_collision/fk_collision.h"
# include "framework_math/fk_math.h"
t_rgba				iter_light(t_intersect inter, t_spotlight *light, t_object *obj);
#endif
