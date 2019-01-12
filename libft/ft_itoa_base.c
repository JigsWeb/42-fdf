/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:21:18 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_base(int value, int base)
{
	int		size;
	int		tmp;
	char	*res;
	char	*base_chars;

	base_chars = ft_strcpy(ft_strnew(16), "0123456789ABCDEF");
	value = value < 0 ? -value : value;
	size = 0;
	tmp = 1;
	while (value > tmp * base && (tmp *= base))
		size++;
	res = ft_strnew(size);
	size = value < 0 && base == 10;
	if (value < 0 && base == 10)
		res[0] = '-';
	while (tmp)
	{
		res[size++] = base_chars[value / tmp];
		value = value % tmp;
		tmp = tmp / base;
	}
	free(base_chars);
	return (res);
}
