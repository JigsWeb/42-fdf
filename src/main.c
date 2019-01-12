/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 02:08:47 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/12 03:39:39 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_data(t_params **params, t_pixel **px)
{
	*((int*)((*params)->data)
		+ (*px)->x_iso + ((*px)->y_iso * WINDOW_WIDTH)) ^= (*px)->color;
}

void	update_pixel(t_pixel **px, int x, int y, int z)
{
	if (!(*px))
		(*px) = (t_pixel*)ft_memalloc(sizeof(t_pixel));
	(*px)->x = x;
	(*px)->y = y;
	(*px)->x_iso = (x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4;
	(*px)->y_iso = (x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - z;
	(*px)->color = 0xffffff;
}

void	draw_line(
	t_params **params,
	t_pixel **px0,
	t_pixel **px1
)
{
	int dx;
	int dy;
	int err;

	dx = abs((*px1)->x_iso - (*px0)->x_iso);
	dy = -abs((*px1)->y_iso - (*px0)->y_iso);
	err = dx + dy;
	while (1)
	{
		fill_data(params, px0);
		if ((*px0)->x_iso == (*px1)->x_iso && (*px0)->y_iso == (*px1)->y_iso)
			break ;
		if (2 * err >= dy
			&& ((*px0)->x_iso += (*px0)->x_iso < (*px1)->x_iso ? 1 : -1))
			err += dy;
		if (2 * err <= dx
			&& ((*px0)->y_iso += (*px0)->y_iso < (*px1)->y_iso ? 1 : -1))
			err += dx;
	}
}

void	draw(t_params **params, t_pixel **px, char **split, char **split_old)
{
	t_pixel *tmp;

	tmp = NULL;
	fill_data(params, px);
	if ((*px)->x)
	{
		update_pixel(
			&tmp,
			(*px)->x - 1,
			(*px)->y,
			ft_atoi(split[(*px)->x - 1]));
		draw_line(params, &tmp, px);
	}
	if ((*px)->y)
	{
		update_pixel(
			&tmp,
			(*px)->x,
			(*px)->y - 1,
			ft_atoi(split_old[(*px)->x]));
		draw_line(params, &tmp, px);
	}
	if (tmp)
		free(tmp);
}

void	read_file(t_params **params, int fd)
{
	char	*line;
	char	**split;
	char	**split_old;
	t_pixel *px;

	px = NULL;
	split_old = NULL;
	update_pixel(&px, -1, 0, 0);
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		while (split[++px->x])
		{
			update_pixel(&px, px->x, px->y, ft_atoi(split[px->x]));
			draw(params, &px, split, split_old);
		}
		free(line);
		if (split_old)
			free(split_old);
		split_old = split;
		update_pixel(&px, -1, ++px->y, 0);
	}
	free(split);
	free(px);
}

int		main(int argc, char const *argv[])
{
	int			fd;
	t_params	*params;

	params = (t_params*)ft_memalloc(sizeof(t_params));
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1
		|| !(params->mlx = mlx_init())
		|| !(params->win =
			mlx_new_window(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42"))
		|| !(params->img =
			mlx_new_image(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT)))
		exit(EXIT_FAILURE);
	params->data = mlx_get_data_addr(
		params->img,
		&(params->bpp),
		&(params->sl),
		&(params->endian));
	read_file(&params, fd);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	mlx_loop(params->mlx);
	exit(EXIT_SUCCESS);
}
