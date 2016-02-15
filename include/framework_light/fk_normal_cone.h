/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cone.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:29:23 by yderosie          #+#    #+#             */
/*   Updated: 2016/02/01 11:18:31 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_CONE_H
# define FK_NORMAL_CONE_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_cone.h"

t_vector3		normal_cone(t_ray ray, t_vector3 inter, t_cone *obj);

#endif
