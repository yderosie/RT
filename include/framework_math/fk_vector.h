/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2016/02/01 21:06:54 by barbare           #+#    #+#             */
/*   Updated: 2016/02/01 23:00:48 by barbare          ###   ########.fr       */
=======
/*   Created: 2015/10/28 12:48:34 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/02 17:08:37 by roblabla         ###   ########.fr       */
>>>>>>> 5e5fbe9f00c93ff26bd80cc16616ad1061f46d09
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VECTOR_H
# define FK_VECTOR_H

# include "stuff.cecinestpasunh"

typedef	struct s_vector3	t_vector3;
typedef t_vector2	t_vertex3;

union		u_vector3
{
	struct	s_vector
	{
		float x;
		float y;
		float z;
	}		noop;
	struct	s_color
	{
		float r;
		float g;
		float b;
	}		noop;
};

/*
** ****************************************************************************
** fk_vectoriel_transformation.c
** ****************************************************************************
*/
t_vector3	vector_new(float x1, float y1, float z1);
t_vector3	vector_cpy(t_vector3 u);
t_vector3	vector_unit(t_vector3 u);
t_vertex3	vector_translation(t_vector3 u, t_vertex3 v);
t_vector3	vector_mul(t_vector3 u, float r);
t_vector3	vector_div(t_vector3 u, float r);

<<<<<<< HEAD
=======
t_vector3		vector_add(t_vector3 u, float r);
t_vector3		vector_sub(t_vector3 u, float r);
t_vector3		vector_div(t_vector3 u, float r);
>>>>>>> 5e5fbe9f00c93ff26bd80cc16616ad1061f46d09
/*
** ****************************************************************************
** fk_vectoriel_math.c
** ****************************************************************************
*/
t_vector3	vector_substract(t_vector3 u, t_vector3 v);
t_vector3	vector_sum(t_vector3 u, t_vector3 v);
t_vector3	vector_product(t_vector3 u, t_vector3 v);
t_vector3	vector_scale(t_vector3 u, float f);

/*
** ****************************************************************************
** fk_vectoriel.c
** ****************************************************************************
*/
t_vector3	vector_reverse(t_vector3 u);
float		vector_dotproduct(t_vector3 u, t_vector3 v);
float		vector_magnitude(t_vector3 u);

#endif
