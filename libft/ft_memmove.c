/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:11:22 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s2 = (char *)dest;
	s1 = (char *)src;
	if (!n)
		return (dest);
	if (s2 < s1)
		return (ft_memcpy(dest, src, n));
	n--;
	while (n != (size_t)-1)
	{
		s2[n] = s1[n];
		n--;
	}
	return (dest);
}
