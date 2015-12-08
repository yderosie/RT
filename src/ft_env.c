/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:12:58 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 11:43:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "framework_shape/fk_objects.h"

void		ft_setup_fct_inter(t_fctinter *inter)
{
	inter[SPHERE] = (float *(*)(t_ray, void*, t_intersect*))&intersect_sphere;
	inter[PLANE] = (float *(*)(t_ray, void*, t_intersect*))&intersect_plan;
	inter[CYLINDER] = NULL;
	inter[CONE] = NULL;
	inter[DEFAULT] = NULL;
}
