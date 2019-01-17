/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:27:39 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/17 04:16:45 by amoynet          ###   ########.fr       */
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
# define MATRICE_SIZE 4
# define TILE_WIDTH 34
# define TILE_HEIGHT 34
# define WINDOW_WIDTH 1720
# define WINDOW_HEIGHT 1280

/**
 * VCTR = VeCToR
 * VTX = VerTeX
 * MAT = MATrix
 * TF = TransFormation
 * TS = TranSlation
 * BPP = Bits Per Pixels
 * SL = Size Line
 * C = Color
**/

typedef struct		s_vctr
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vctr;

typedef struct		s_mat
{
	struct s_vctr	*x_axis;
	struct s_vctr	*y_axis;
	struct s_vctr	*z_axis;
	struct s_vctr	*ts;
}					t_mat;

typedef struct		s_tf
{
	struct s_vctr	*ts;
	struct s_vctr	*scale;
	struct s_vctr	*rotation;
}					t_tf;

typedef struct		s_img_infos
{
	char						*data;
	int							bpp;
	int							sl;
	int							endian;
	int							height;
	int							width;
	struct s_tf					*tf;
}					t_img_infos;

typedef struct		s_vtx
{
	int					color;
	struct s_vctr		*vctr;
	struct s_vtx		*next;
}					t_vtx;

typedef struct		s_params
{
	void				*mlx;
	void				*win;
	void				*img;
	struct s_vtx		*vtx;
	struct s_img_infos	*img_infos;
}					t_params;

t_params			*create_params();
int					create_img(t_params **params);
t_vctr				*create_vctr(float x, float y, float z, float w);
int					read_file(t_params **params, int fd);
t_vtx				*find_vtx(t_params **params, int x, int y);
void				draw(t_params **params);
void				set_matrice(t_params **params, char *name, void *extra);
void				apply_mat(t_vctr **v, t_mat *m);
t_mat				*create_mat(t_vctr *x_axis, t_vctr *y_axis, t_vctr *z_axis, t_vctr *ts);

#endif