#include "../includes/fdf.h"

static int	add_vtx(t_params **params, int x, int y, int z)
{
	t_vtx *new;

	if(!(new = (t_vtx*)ft_memalloc(sizeof(t_vtx))))
		return (0);
	new->vctr = create_vctr(x, y, z, 1);
	new->color = 0xffffff;
	new->next = NULL;
	if (!(*params)->vtx)
		(*params)->vtx = new;
	else
	{
		new->next = (*params)->vtx;
		(*params)->vtx = new;
	}
	return (1);
}

static void	recenter_vtx(t_params **params)
{
	t_vtx *vtx;
	t_mat *mat;

	mat = create_mat(
		create_vctr(1, 0, 0, 0),
		create_vctr(0, 1, 0, 0),
		create_vctr(0, 0, 1, 0), // @TODO
		create_vctr(-0.5, -0.5, 0, 1)
	);
	vtx = (*params)->vtx;
	while (vtx)
	{
		apply_mat(&(vtx->vctr), mat);
		printf("REC Y: %f X: %f\n", vtx->vctr->y, vtx->vctr->x);
		vtx = vtx->next;
	}
}

int			read_file(t_params **params, int fd)
{
	char *line;
	char **values;
	int x;
	int y;

	y = 0;
	while (get_next_line(fd, &line) && (x = -1))
	{
		values = ft_strsplit(line, ' ');
		while (values[++x])
			if(!(add_vtx(params, x, y, ft_atoi(values[x]))))
				return (0);
		if (--x > (*params)->img_infos->width)
			(*params)->img_infos->width = x;
		y++;
	}
	(*params)->img_infos->height = --y ? y * TILE_HEIGHT : 1;
	(*params)->img_infos->width = (*params)->img_infos->width ? (*params)->img_infos->width * TILE_WIDTH : 1;
	recenter_vtx(params);
	return (1);
}
