/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cylinder.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:16:50 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/23 20:18:21 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_CYLINDER
# define FK_NORMAL_CYLINDER

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_cylinder.h"

t_vector3		normal_cylinder(t_vector3 inter, t_cylinder *obj);

#endif
