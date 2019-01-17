#include "fdf.h"

t_vctr		*create_vctr(float x, float y, float z, float w)
{
	t_vctr *v;

	v = (t_vctr*)ft_memalloc(sizeof(t_vctr));
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
	return (v);
}

t_mat		*create_mat(
	t_vctr *x_axis,
	t_vctr *y_axis,
	t_vctr *z_axis,
	t_vctr *ts
)
{
	t_mat *m;

	m = (t_mat*)ft_memalloc(sizeof(t_mat));
	m->x_axis = x_axis;
	m->y_axis = y_axis;
	m->z_axis = z_axis;
	m->ts = ts;
	return (m);
}

int		create_img(t_params **params)
{
	if (!((*params)->img = mlx_new_image(
		(*params)->mlx,
		(*params)->img_infos->width,
		(*params)->img_infos->height)))
		return (0);
	(*params)->img_infos->data = mlx_get_data_addr(
		(*params)->img,
		&((*params)->img_infos->bpp),
		&((*params)->img_infos->sl),
		&((*params)->img_infos->endian));
	return (1);
}

t_params		*create_params()
{
	t_params *params;

	if (!(params = (t_params*)ft_memalloc(sizeof(t_params)))
		|| !(params->img_infos = (t_img_infos*)ft_memalloc(sizeof(t_img_infos)))
		|| !(params->mlx = mlx_init())
		|| !(params->win = mlx_new_window(
			params->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"mlx 42")))
		return (NULL);
	return (params);
}