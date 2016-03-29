/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:19:03 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/09 11:24:40 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_cylinder.h"
#include "framework_math/fk_math.h"


/*void		normal_cylinder(t_intersect *inter, t_cylinder *obj)
{
	const double a = 1.0 - (vector_dotproduct(obj->pos,obj->pos) / sqrt(inter->pos.x*inter->pos.x + inter->pos.y*inter->pos.y));
	inter->v_normal.x = a * inter->pos.x;
	inter->v_normal.y = a * inter->pos.y;
	inter->v_normal.z = inter->pos.z;
	inter->v_normal = vector_unit(inter->v_normal);
}*/
 
void		normal_cylinder(t_intersect *inter, t_cylinder *obj)
{
	float		radius;
	t_vector3	ctop;
	t_vector3	qtop;
	t_vector3	v_normal;		
	  		  
	ctop = vector_substract(inter->pos, obj->pos);
	radius = vector_dotproduct(ctop, obj->dir);
	qtop = vector_substract(ctop, vector_mul(obj->dir, radius));
	inter->v_normal = vector_unit(vector_div(qtop, -obj->radius));
}
