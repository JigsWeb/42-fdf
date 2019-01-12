/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:23:37 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				negativ_factor;
	long long int	res;

	i = 0;
	res = 0;
	negativ_factor = 1;
	while (str[i] && str[i] != '+' && str[i] != '-'
		&& (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		negativ_factor = str[i++] == '-' ? -1 : 1;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * negativ_factor);
}
