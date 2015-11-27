/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/27 15:21:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_MATH_H
# define FT_MATH_H

# include <math.h>

# ifndef PI
#  define PI M_PI
# endif

#define SQUARE(x) ((x) * (x))
#define DPI (PI - (PI / 2))
#define RAD_TO_DEGREES(X) (((X) * 180) / PI)
#define ABS(X) (X) < 0 ? -(X) : (X)

#endif
