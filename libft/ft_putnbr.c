/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:41:52 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_pow(int n, int i)
{
	return (i > 1 ? n * ft_pow(n, --i) : n);
}

void		ft_putnbr(int n)
{
	int tmp;
	int len;
	int current_factor;
	int negativ_factor;

	tmp = n;
	len = 0;
	negativ_factor = n < 0 ? -1 : 1;
	if (n < 0)
		ft_putchar('-');
	while (tmp && ++len)
		tmp = (tmp - (tmp % 10)) / 10;
	while (len && --len)
	{
		current_factor = ft_pow(10, len);
		ft_putchar((n / current_factor) * negativ_factor + '0');
		n = n % current_factor;
	}
	ft_putchar(n * negativ_factor + '0');
}
