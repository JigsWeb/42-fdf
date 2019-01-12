/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:27:39 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/12 03:51:11 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/includes/get_next_line.h"

# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define TILE_WIDTH 34
# define TILE_HEIGHT 34
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

typedef struct		s_pixel
{
	int		x;
	int		y;
	int		x_iso;
	int		y_iso;
	int		color;
}					t_pixel;

typedef struct		s_params
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sl;
	int		endian;
	char	*data;
}					t_params;


#endif