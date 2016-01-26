/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:12:58 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/25 12:29:07 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_normal.h"
#include "framework_light/fk_normal_plan.h"
#include "framework_light/fk_normal_sphere.h"
#include "framework_light/fk_normal_cylinder.h"

void		ft_setup_inter(t_fctinter *inter)
{
	inter[SPHERE] = (float (*)(t_ray, void*, float *))&intersect_sphere;
	inter[PLANE] = (float (*)(t_ray, void*, float *))&intersect_plan;
	inter[CYLINDER] = (float (*)(t_ray, void*, float *))&intersect_cylinder;
	inter[CONE] = NULL;
	inter[DEFAULT] = NULL;
}

void		ft_setup_normal(t_fctnormal *normal)
{
	normal[SPHERE] = (t_vector3 (*)(t_vector3, void *))&normal_sphere;
	normal[PLANE] = (t_vector3 (*)(t_vector3, void *))&normal_plan;
	normal[CYLINDER] = (t_vector3 (*)(t_vector3, void *))&normal_cylinder;
	normal[CONE] = NULL;
	normal[DEFAULT] = NULL;
}
