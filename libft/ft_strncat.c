/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:29:46 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/05 17:20:36 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	char *s1iter;

	s1iter = s1;
	while (*s1iter != '\0')
		s1iter++;
	while (len-- > 0 && *s2 != '\0')
		*s1iter++ = *s2++;
	*s1iter = '\0';
	return (s1);
}
