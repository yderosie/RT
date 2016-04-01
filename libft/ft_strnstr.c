/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:58:25 by yderosie          #+#    #+#             */
/*   Updated: 2015/11/09 19:24:46 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t hlen)
{
	size_t	nlen;
	int		lastresult;

	if (*needle == '\0')
		return ((char*)haystack);
	nlen = ft_strlen(needle);
	lastresult = 1;
	while (nlen <= hlen && *haystack != '\0'
		&& (lastresult = ft_strncmp(haystack, needle, nlen)))
	{
		hlen--;
		haystack++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)haystack);
}
