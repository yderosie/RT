/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_paraboloid.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 21:36:08 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/27 21:36:10 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_PARABOLOID_H
# define FK_NORMAL_PARABOLOID_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_paraboloid.h"
# include "framework_collision/fk_intersect.h"

void		normal_paraboloid(t_intersect *inter, t_paraboloid *obj);

#endif
