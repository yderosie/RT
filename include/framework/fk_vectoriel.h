/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vectoriel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:48:34 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/31 23:46:08 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VECTORIEL_H
# define FK_VECTORIEL_H

typedef struct	s_vector3 t_vector3;

struct			s_vector3
{
	float x;
	float y;
	float z;
};

t_vector3		vector_new(float x1, float y1, float z1);
t_vector3		vector_cpy(t_vector3 u);
t_vector3		vector_unit(t_vector3 u);
t_vector3		vector_substract(t_vector3 u, t_vector3 v);
t_vector3		vector_sum(t_vector3 u, t_vector3 v);
t_vector3		vector_product(t_vector3 u, t_vector3 v);
t_vector3		vector_reverse(t_vector3 u);
int				vector_dotproduct(t_vector3 u, t_vector3 v);
unsigned int	vector_magnitude(t_vector3 u);

#endif
