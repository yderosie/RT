/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:48:34 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 10:29:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VECTOR_H
# define FK_VECTOR_H

typedef struct	s_vector3 t_vector3;
typedef			t_vector3 t_vertex3;

struct			s_vector3
{
	float x;
	float y;
	float z;
};

/*
** ****************************************************************************
** fk_vector_transformation.c
** ****************************************************************************
*/
t_vector3		vector_new(float x1, float y1, float z1);
t_vector3		vector_cpy(t_vector3 u);
t_vector3		vector_unit(t_vector3 u);
t_vertex3		vector_translation(t_vector3 u, t_vertex3 v);

t_vector3		vector_mul(t_vector3 u, float r);
t_vector3		vector_div(t_vector3 u, float r);
/*
** ****************************************************************************
** fk_vector_math.c
** ****************************************************************************
*/
t_vector3		vector_substract(t_vector3 u, t_vector3 v);
t_vector3		vector_sum(t_vector3 u, t_vector3 v);
t_vector3		vector_product(t_vector3 u, t_vector3 v);
t_vector3		vector_scale(t_vector3 u, float f);

/*
** ****************************************************************************
** fk_vector.c
** ****************************************************************************
*/
t_vector3		vector_reverse(t_vector3 u);
float			vector_dotproduct(t_vector3 u, t_vector3 v);
float			vector_magnitude(t_vector3 u);

#endif
