#include "fdf.h"

t_params		*create_params()
{
	t_params *params;

	if (!(params = (t_params*)ft_memalloc(sizeof(t_params)))
		|| !(params->camr = create_camr())
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