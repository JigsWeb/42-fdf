/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:11:14 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/08 19:47:34 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = -1;
	while (s1[++i])
		if (s1[i] != s2[i])
			break ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
