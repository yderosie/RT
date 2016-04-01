/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:54:56 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/03 10:17:51 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstadd(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if ((new = ft_lstnew(content, content_size)) == NULL)
		return (0);
	ft_lstlink(alst, new);
	return (1);
}
