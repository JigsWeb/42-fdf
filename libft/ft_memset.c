/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:15:43 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/10 22:02:49 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;
	size_t			i;

	i = -1;
	b1 = b;
	while (++i < len)
		b1[i] = (unsigned char)c;
	return (b);
}
