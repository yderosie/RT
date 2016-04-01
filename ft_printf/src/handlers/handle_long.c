/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:24:55 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/17 18:14:08 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "ft_printf.h"
#include <libft.h>

ssize_t	handle_long(char **format, va_list *args, t_arg *arg)
{
	arg->length = l;
	return (get_handler(ft_tolower(**format))(format, args, arg));
}
