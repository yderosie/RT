/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plan.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:02:06 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/14 20:02:31 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_PLAN_H
# define FK_NORMAL_PLAN_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_plan.h"

t_vector3		normal_plan(t_vector3 inter, t_plan *obj);

#endif
