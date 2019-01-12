/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:37:10 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	size_t	slen;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	start = 0;
	end = slen - 1;
	while (s[start]
		&& (s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		start++;
	if (start == slen)
		return ((s1 = ft_strnew(0)) ? s1 : NULL);
	while (s[end]
		&& (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if (!(s1 = ft_strnew(end - start + 1)))
		return (NULL);
	s1 = ft_strncpy(s1, s + start, end - start + 1);
	return (s1);
}
