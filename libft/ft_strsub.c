/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:24:01 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	a;

	if (!s || !(s1 = (char*)malloc(len * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	a = (size_t)start;
	while (s[a + i] && i < len)
	{
		s1[i] = s[a + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
