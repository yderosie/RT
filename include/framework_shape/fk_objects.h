/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/13 22:27:21 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

#include "framework_shape/fk_type.h"
#include "framework_rgb/fk_rgb.h"

typedef struct		s_object t_object;
typedef struct		s_material t_material;

struct				s_object
{
	t_type			type;
	t_rgba			color;
	char			stuff[128];
};


#endif
