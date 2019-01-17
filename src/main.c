#include "../includes/fdf.h"

// int				init(t_params **params)
// {
// 	// set_matrice(params, "isometric", NULL);
// 	// apply_matrice(params);
// 	if (!(create_image(params)))
// 		return (0);
// 	draw(params);
// 	mlx_put_image_to_window(
// 		(*params)->mlx,
// 		(*params)->win,
// 		(*params)->img,
// 		WINDOW_WIDTH / 2 - (*params)->img_infos->width / 2,
// 		WINDOW_HEIGHT / 2 - (*params)->img_infos->height / 2);
// 	return (1);
// }

int				main(int argc, char const *argv[])
{
	int			fd;
	t_params	*params;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1
		|| !(params = create_params())
		|| !read_file(&params, fd))
			exit(EXIT_FAILURE);
	// mlx_loop(params->mlx);
	exit(EXIT_SUCCESS);
}