/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:21:11 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/04 12:08:34 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *in, int data, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)in;
	while (len-- > 0)
		*ptr++ = (unsigned char)data;
	return (in);
}
