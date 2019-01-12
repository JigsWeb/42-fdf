/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:09:57 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_count_needle(char const *s, char c)
{
	size_t i;
	size_t count;

	i = -1;
	count = 0;
	while (s[++i])
		if (((s[i - 1] && s[i - 1] == c) || !i) && s[i] != c)
			count++;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	int		s_len;
	char	**t;

	if (!s || !c)
		return (NULL);
	count = ft_count_needle(s, c);
	if (!(t = (char**)malloc((count + 1) * sizeof(char*))))
		return (0);
	t[count] = 0;
	i = ft_strlen(s) - 1;
	while (--count > -1)
	{
		while (s[i] == c)
			i--;
		s_len = 0;
		while (i - s_len > -1 && s[i - s_len] && s[i - s_len] != c)
			s_len++;
		t[count] = ft_strnew(s_len);
		t[count] = ft_memcpy(t[count], s + i - s_len + 1, s_len);
		t[count][s_len] = '\0';
		i -= s_len;
	}
	return (t);
}
