/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:18:19 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 18:18:21 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_sphere.h"
#include "framework_shape/fk_type.h"
#include "framework_shape/fk_newelement.h"

void		new_sphere(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_sphere){ SPHERE,
		new_material(val),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		json_get(val.data.obj, "ambient").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "specular").data.number,
		json_get(val.data.obj, "light").data.boolean,
		new_position(val),
		new_direction(val),
		json_get(val.data.obj, "radius").data.number
	}, sizeof(t_sphere));
}
