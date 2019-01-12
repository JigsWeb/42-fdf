/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:18:28 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/11 22:59:50 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/fdf.h"

void	draw_line(
	t_params **params,
	int x0,
	int y0,
	int x1,
	int y1
)
{
	int dx;
	int dy;
	int err;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put((*params)->mlx, (*params)->win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		if (2 * err >= dy && (x0 += x0 < x1 ? 1 : -1))
			err += dy;
		if (2 * err <= dx && (y0 += y0 < y1 ? 1 : -1))
			err += dx;
	}
}

// void	fill(t_params **params, int x, int y)
// {
// 	mlx_pixel_put((*params)->mlx, (*params)->win,
// 		(x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
// 		(x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x]),
// 		0xFFFFFF);
// 	if (x)
// 		draw_line(
// 			params,
// 			((x - 1) - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
// 			((x - 1) + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x - 1]),
// 			(x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
// 			(x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x]));
// 	if (y)
// 		draw_line(
// 			params,
// 			(x - (y - 1)) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
// 			(x + (y - 1)) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split_old[x]),
// 			(x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
// 			(x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x]));
// }

int		read_map(int fd, t_params **params)
{
	char	*line;
	char	**split;
	char	**split_old;
	int		y;
	int		x;

	y = 0;
	split_old = NULL;
	while (get_next_line(fd, &line) && (x = -1))
	{
		split = ft_strsplit(line, ' ');
		while (split[++x])
		{
			mlx_pixel_put((*params)->mlx, (*params)->win,
				(x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
				(x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x]),
				0xFFFFFF);
			if (x)
				draw_line(
					params,
					((x - 1) - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
					((x - 1) + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x - 1]),
					(x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
					(x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x]));
			if (y)
				draw_line(
					params,
					(x - (y - 1)) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
					(x + (y - 1)) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split_old[x]),
					(x - y) * (TILE_WIDTH / 2) + WINDOW_WIDTH / 4,
					(x + y) * (TILE_HEIGHT / 2) + WINDOW_WIDTH / 4 - ft_atoi(split[x]));
		}
		free(line);
		if (split_old)
			free(split_old);
		split_old = split;
		y++;
	}
	free(split);
	return (1);
}

int		mouse_handler(int button, int x, int y, void *params)
{
	mlx_pixel_put(
		((t_params*)params)->mlx, ((t_params*)params)->win,
		((x - 250) / (TILE_WIDTH / 2) + (y - 250) / (TILE_HEIGHT / 2)) /2,
		((y - 250) / (TILE_HEIGHT / 2) - ((x - 250) / (TILE_WIDTH / 2))) /2,
		0xFFF
	);
	printf("Event fired: %d, %d, %d", button, x, y);
	return (1);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_params *params;

	params = (t_params*)ft_memalloc(sizeof(t_params));
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1
		|| !(params->mlx = mlx_init())
		|| !(params->win = mlx_new_window(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42"))
		|| !read_map(fd, &params))
		exit(EXIT_FAILURE);
	mlx_mouse_hook (params->win, mouse_handler, (void*)params);
	mlx_loop(params->mlx);
	exit(EXIT_SUCCESS);
}
