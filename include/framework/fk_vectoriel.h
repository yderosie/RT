/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vectoriel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:48:34 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/27 16:17:54 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VECTORIEL_H
# define FK_VECTORIEL_H

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
** fk_vectoriel_transformation.c
** ****************************************************************************
*/
t_vector3		vector_new(float x1, float y1, float z1);
t_vector3		vector_cpy(t_vector3 u);
t_vector3		vector_unit(t_vector3 u);
t_vertex3		vector_translation(t_vector3 u, t_vertex3 v);

t_vector3		vector_mul(t_vector3 u, double r);
t_vector3		vector_div(t_vector3 u, double r);
/*
** ****************************************************************************
** fk_vectoriel_math.c
** ****************************************************************************
*/
t_vector3		vector_substract(t_vector3 u, t_vector3 v);
t_vector3		vector_sum(t_vector3 u, t_vector3 v);
t_vector3		vector_product(t_vector3 u, t_vector3 v);
t_vector3		vector_scale(t_vector3 u, double f);

/*
** ****************************************************************************
** fk_vectoriel.c
** ****************************************************************************
*/
t_vector3		vector_reverse(t_vector3 u);
double			vector_dotproduct(t_vector3 u, t_vector3 v);
double			vector_magnitude(t_vector3 u);

#endif
