/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:05:48 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*s2;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(s2 = (char*)malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		s2[i] = f(s[i]);
	s2[i] = '\0';
	return (s2);
}
