/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_sphere.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:44:39 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/01 11:18:02 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_SPHERE_H
# define FK_NORMAL_SPHERE_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_sphere.h"

t_vector3		normal_sphere(t_ray ray, t_vector3 inter, t_sphere *obj);

#endif
