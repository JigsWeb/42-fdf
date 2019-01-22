/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:27:39 by amoynet           #+#    #+#             */
/*   Updated: 2019/01/22 01:35:36 by amoynet          ###   ########.fr       */
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
# define TILE_WIDTH 40
# define TILE_HEIGHT 40
# define TILE_DEPTH 40
# define WINDOW_WIDTH 1760
# define WINDOW_HEIGHT 1280

# define PP_TYPE 0
# define OP_TYPE 1
# define CP_TYPE 2
# define CUSTOM_TYPE 3

/**
 * VCTR = VeCToR
 * VTX = VerTeX
 * MAT = MATrix
 * TF = TransFormation
 * TS = TranSlation
 * BPP = Bits Per Pixels
 * SL = Size Line
 * C = Color
 * TP = TyPe
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
	int		len;
	float	**arr;
}					t_mat;

typedef struct		s_tf
{
	struct s_vctr	*ts;
	struct s_vctr	*scale;
	struct s_vctr	*rot_x;
	struct s_vctr	*rot_y;
	struct s_vctr	*rot_z;
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

typedef struct		s_camr
{
	int					tp;
	float				z_near;
	float				z_far;
	float				fov_x;
	float				fov_y;
}					t_camr;

typedef struct		s_params
{
	void				*mlx;
	void				*win;
	void				*img;
	struct s_vtx		*vtx;
	struct s_img_infos	*img_infos;
	struct s_camr		*camr;
}					t_params;

t_params			*create_params();
t_camr				*create_camr();
int					create_img(t_params **params);
t_vctr				*create_vctr(float x, float y, float z, float w);
int					read_file(t_params **params, int fd);
t_vtx				*find_vtx(t_params **params, int x, int y);
void				draw(t_params **params);
void				set_matrice(t_params **params, char *name, void *extra);
void				apply_mat(t_mat *m, t_vctr *v);
t_mat				*create_mat();
t_mat				*mult_mat(t_mat *m0, t_mat *m1);
t_mat				*op_mat(t_params **params);
t_mat				*ts_mat(t_vctr *v);
t_mat				*scale_mat(t_vctr *v);
t_mat				*rot_x_mat(float d);
t_mat				*rot_y_mat(float d);
t_mat				*rot_z_mat(float d);

#endif