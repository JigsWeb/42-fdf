#include "../includes/fdf.h"

int				init(t_params **params)
{
	if (!(create_img(params)))
		return (0);
	// draw(params);
	t_vtx *tmp = (*params)->vtx;
	// t_mat *op_m = op_mat(params);
	while (tmp)
	{
		// apply_mat(ts_mat(create_vctr(15, 15, 0, 1)), tmp->vctr);
		apply_mat(rot_x_mat(10), tmp->vctr);
		// apply_mat(op_m, tmp->vctr);
		printf("(%f, %f, %f)\n", tmp->vctr->z, tmp->vctr->x, tmp->vctr->y);
		if ((int)tmp->vctr->x < (WINDOW_WIDTH / TILE_WIDTH)
			&& (int)tmp->vctr->x >= 0
			&& (int)tmp->vctr->y < WINDOW_HEIGHT / TILE_HEIGHT
			&& (int)tmp->vctr->y >= 0)
		{
			*((int*)((*params)->img_infos->data)
				+ (int)round(tmp->vctr->x * TILE_WIDTH)
				+ ((int)round(tmp->vctr->y * TILE_HEIGHT) * WINDOW_WIDTH))
				^= 0xffffff;
		}
		// *((int*)((*params)->img_infos->data) + 1) ^= 0xffffff;
		// printf("CUBOID\n");
		// printf("NEW VTX AT Y: %f X: %f Z: %f\n", tmp->vctr->y, tmp->vctr->x, tmp->vctr->z);
		// printf("APPLY RES / Y: %f X: %f Z: %f W: %f\n"
		// 	, round(tmp->vctr->y *  45.00 * WINDOW_HEIGHT / 2 / 45.00 + WINDOW_HEIGHT / 2)
		// 	, round(tmp->vctr->x * 45.00 * WINDOW_WIDTH / 2 / 45 + WINDOW_WIDTH / 2)
		// 	, tmp->vctr->z
		// 	, tmp->vctr->w);
		// *((int*)((*params)->img_infos->data)
		// 	+ (int)round(tmp->vctr->x *  45.00 * WINDOW_HEIGHT / 2 / 45.00 + WINDOW_HEIGHT / 2)
		// 	+ ((int)round(tmp->vctr->y * 45.00 * WINDOW_WIDTH / 2 / 45 + WINDOW_WIDTH / 2) * WINDOW_WIDTH))
		// 	^= 0xffffff;
		// printf("WRITE ON %d\n", (int)round(tmp->vctr->y *  45.00 * WINDOW_HEIGHT / 2 / 45.00 + WINDOW_HEIGHT / 2)
		// 	+ ((int)round(tmp->vctr->x * 45.00 * WINDOW_WIDTH / 2 / 45 + WINDOW_WIDTH / 2) * WINDOW_WIDTH));
		tmp = tmp->next;
	}
	mlx_put_image_to_window((*params)->mlx, (*params)->win, (*params)->img, 0, 0);
	return (1);
}

int				main(int argc, char const *argv[])
{
	int			fd;
	t_params	*params;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1
		|| !(params = create_params())
		|| !read_file(&params, fd)
		|| !init(&params))
			exit(EXIT_FAILURE);
	mlx_loop(params->mlx);
	exit(EXIT_SUCCESS);
}