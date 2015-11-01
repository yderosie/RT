/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:09:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 18:33:39 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_ENV_H
# define FT_ENV_H
# include <fk_objects.h>

typedef struct		s_env t_env;

struct				s_env
{
	t_resolution	resolution;
	t_vertex3		pos_absolute_camera;
	t_fct_inter		fctinter[DEFAULT];
};
#endif
