/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:12:58 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 21:18:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_env.h>
#include <fk_objects.h>

void		ft_setup_fct_inter(t_fctinter *inter)
{
	inter[SPHERE] = intersect_sphere;
	inter[PLANE] = NULL;
	inter[CYLINDER] = NULL;
	inter[CONE] = NULL;
	inter[DEFAULT] = NULL;
}
