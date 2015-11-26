/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vertex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:14:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/25 17:18:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vertexiel.h"

t_vertex3		vertex_ofvector3(t_vector3 v)
{
	return ((t_vertex3){v.x, v.y, v.z});
}
