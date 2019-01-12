/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 10:10:32 by antho             #+#    #+#             */
/*   Updated: 2019/01/10 21:48:28 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft.h"

# define BUFF_SIZE 5
# define GNL_SUCCESS_CODE 1
# define GNL_EOF_CODE 0
# define GNL_ERROR_CODE -1
# define NEW_LINE_CHAR '\n'

typedef struct	s_gnl
{
	int		fd;
	int		ret;
	char	*str;
}				t_gnl;

int				get_next_line(int fd, char **line);

#endif
