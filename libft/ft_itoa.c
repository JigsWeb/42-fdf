/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:18:21 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	size_t		len;
	long int	tmp;
	long int	is_negativ;
	char		*s;

	is_negativ = n < 0;
	len = is_negativ;
	tmp = n;
	while (tmp && ++len)
		tmp = tmp / 10;
	if (!(s = ft_strnew(len ? len : 1)))
		return (NULL);
	if (!n)
		s[0] = '0';
	while (n)
	{
		s[--len] = (n % 10 * (is_negativ && n ? -1 : 1)) + '0';
		n = n / 10;
	}
	if (is_negativ)
		s[--len] = '-';
	return (s);
}
