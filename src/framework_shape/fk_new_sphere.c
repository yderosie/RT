/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:02:54 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 19:04:00 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "framework_math/fk_vector.h"

t_sphere		*new_sphere(t_vector3 pos, unsigned int radius)
{
	t_sphere		*newsphere;

	newsphere = malloc(sizeof(t_sphere));
	newsphere->type = SPHERE;
	newsphere->pos = (t_vertex3) {.x = pos.x, .y = pos.y, .z = pos.z};
	newsphere->radius = radius;
	return (newsphere);
}
