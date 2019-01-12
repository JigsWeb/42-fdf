/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:05:02 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/10 23:47:32 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	l->content = NULL;
	if (content)
		l->content = ft_memcpy(ft_memalloc(content_size), content, content_size);
	l->content_size = content ? content_size : 0;
	l->next = NULL;
	return (l);
}
