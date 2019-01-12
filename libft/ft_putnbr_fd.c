/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:20:48 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_pow(int n, int i)
{
	return (i > 1 ? n * ft_pow(n, --i) : n);
}

void		ft_putnbr_fd(int n, int fd)
{
	int tmp;
	int len;
	int current_factor;
	int negativ_factor;

	tmp = n;
	len = 0;
	negativ_factor = n < 0 ? -1 : 1;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (tmp && ++len)
		tmp = (tmp - (tmp % 10)) / 10;
	while (len && --len)
	{
		current_factor = ft_pow(10, len);
		ft_putchar_fd((n / current_factor) * negativ_factor + '0', fd);
		n = n % current_factor;
	}
	ft_putchar_fd(n * negativ_factor + '0', fd);
}
