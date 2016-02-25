/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/24 16:04:01 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

#include "libft.h"
#include "framework_shape/fk_type.h"
#include "framework_math/fk_vector.h"

typedef struct		s_object t_object;
typedef struct		s_material t_material;

struct				s_object
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	float			diffuse;
	t_bool			light;
	t_vertex3		pos;
	char			stuff[128];
};


#endif
