/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cylinder.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:16:50 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/01 11:18:47 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_CYLINDER_H
# define FK_NORMAL_CYLINDER_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_cylinder.h"

t_vector3		normal_cylinder(t_ray ray, t_vector3 inter, t_cylinder *obj);

#endif
