/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 15:50:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 10:59:45 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/fk_collision.h"

t_ray		ray_new(t_vertex3 v, t_vector3 dir)
{
	return ((t_ray) {.pos = v, .dir = dir});
}

t_ray		ray_modif_pos(t_ray ray, t_vertex3 pos)
{
	return ((t_ray) {.pos = pos, .dir = ray.dir});
}
