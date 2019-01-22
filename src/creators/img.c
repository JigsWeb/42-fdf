#include "fdf.h"

int		create_img(t_params **params)
{
	if (!((*params)->img = mlx_new_image(
		(*params)->mlx,
		WINDOW_WIDTH,
		WINDOW_HEIGHT)))
		return (0);
	(*params)->img_infos->data = mlx_get_data_addr(
		(*params)->img,
		&((*params)->img_infos->bpp),
		&((*params)->img_infos->sl),
		&((*params)->img_infos->endian));
	return (1);
}