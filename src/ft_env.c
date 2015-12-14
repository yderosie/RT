/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:12:58 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/14 18:56:27 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "framework_shape/fk_listobj.h"

void		ft_setup_inter(t_fctinter *inter)
{
	inter[SPHERE] = (float (*)(t_ray, void*, float *))&intersect_sphere;
	inter[PLANE] = NULL; //(float *(*)(t_ray, void*, t_intersect*))&intersect_plan;
	inter[CYLINDER] = NULL;
	inter[CONE] = NULL;
	inter[DEFAULT] = NULL;
}

void		ft_setup_normal(t_fctnormal *normal)
{
	normal[SPHERE] = (t_vector3 (*)(t_vector3, void *))&normal_sphere;
	normal[PLANE] = (t_vector3 (*)(t_vector3, void *))&normal_plan;
	normal[SPHERE] = (t_vector3 (*)(t_vector3, void *))&normal_sphere;
	normal[SPHERE] = (t_vector3 (*)(t_vector3, void *))&normal_sphere;
	normal[SPHERE] = (t_vector3 (*)(t_vector3, void *))&normal_sphere;
}
