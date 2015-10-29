/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vectoriel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:48:34 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/29 16:06:11 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VECTORIEL_H
# define FK_VECTORIEL_H

typedef struct	s_vector t_vector;

struct			s_vector
{
	float x;
	float y;
	float z;
};

t_vector		new_vector(float x1, float y1, float z1);
t_vector		*cpy_vector(t_vector *vect);
t_vector		*unit_vector(t_vector vect);

t_vector		dot

#endif
