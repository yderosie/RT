/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:32:26 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/04 14:29:45 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_LIGHT
# define FK_LIGHT
# include "framework/fk_type.h"
# include "framework/fk_rgb.h"
# include "framework/fk_vectoriel.h"

typedef struct		s_spotlight		t_spotlight;
struct				s_spotlight
{
	t_type			type;
	t_rgba			color;
	t_vertex3		pos;
	double			radius;
	double			intensity;
};

# include "framework/fk_objects.h"
# include "framework/fk_collision.h"
# include "framework/fk_math.h"
t_rgba				iter_light(t_intersect inter, t_spotlight *light, t_object *obj);
#endif
