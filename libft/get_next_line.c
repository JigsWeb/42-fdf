/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:27:58 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/10 23:53:44 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

t_gnl	**find_or_create_fd(int fd, t_list **lst)
{
	t_gnl	*gnl;
	t_list	*lst_tmp;

	if (*lst && ((t_gnl *)(*lst)->content)->fd == fd)
		return ((t_gnl **)&(*lst)->content);
	if (*lst && (*lst)->next)
		return (find_or_create_fd(fd, &(*lst)->next));
	if (!(gnl = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	gnl->fd = fd;
	gnl->ret = -1;
	gnl->str = NULL;
	if (!(lst_tmp = ft_lstnew(gnl, sizeof(t_gnl))))
		return (NULL);
	if (!*lst)
	{
		if (!(*lst = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		*lst = (t_list *)ft_memcpy(*lst, lst_tmp, sizeof(t_list));
		free(lst_tmp);
	}
	else
		ft_lstadd(lst, lst_tmp);
	free(gnl);
	return ((t_gnl **)&(*lst)->content);
}

int		read_fd(t_gnl **gnl)
{
	char buff[BUFF_SIZE + 1];
	char *tmp;

	if (!(*gnl)->str && !((*gnl)->str = ft_strnew(0)))
		return (0);
	while (!(ft_strchr((*gnl)->str, NEW_LINE_CHAR))
		&& ((*gnl)->ret = read((*gnl)->fd, buff, BUFF_SIZE)))
	{
		if ((*gnl)->ret < 0 || !(tmp = ft_strdup((*gnl)->str)))
			return (0);
		buff[(*gnl)->ret] = '\0';
		free((*gnl)->str);
		if (!((*gnl)->str = ft_strjoin(tmp, buff)))
			return (0);
		free(tmp);
	}
	return (1);
}

int		read_line(t_gnl **gnl, char **line)
{
	char *new_line_pos;
	char *tmp;

	(*gnl)->ret = *((*gnl)->str) ? 1 : 0;
	new_line_pos = ft_strchr((*gnl)->str, NEW_LINE_CHAR);
	if (new_line_pos)
	{
		*line = ft_strnew(new_line_pos - (*gnl)->str);
		if (!*line || !(tmp = ft_strdup(new_line_pos + 1)))
			return (0);
		*line = ft_strncpy(*line, (*gnl)->str, new_line_pos - (*gnl)->str);
		free((*gnl)->str);
		(*gnl)->str = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		if (!(*line = ft_strdup((*gnl)->str)))
			return (0);
		(*gnl)->str[0] = '\0';
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_gnl			**gnl;

	if (!line || BUFF_SIZE <= 0 || !(gnl = find_or_create_fd(fd, &lst)))
		return (GNL_ERROR_CODE);
	if (!read_fd(gnl) || !read_line(gnl, line))
		return (GNL_ERROR_CODE);
	if (!(*gnl)->ret)
		return (GNL_EOF_CODE);
	return (GNL_SUCCESS_CODE);
}
