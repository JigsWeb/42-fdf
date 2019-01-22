#include "../includes/fdf.h"

static int	add_vtx(t_params **params, int x, int y, int z)
{
	t_vtx *new;

	if(!(new = (t_vtx*)ft_memalloc(sizeof(t_vtx))))
		return (0);
	new->vctr = create_vctr(x, y, z, 1);
	new->color = 0xffffff;
	new->next = NULL;
	printf("Z (%f, %f, %f)\n", new->vctr->z, new->vctr->x, new->vctr->y);
	if (!(*params)->vtx)
		(*params)->vtx = new;
	else
	{
		new->next = (*params)->vtx;
		(*params)->vtx = new;
	}
	return (1);
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
	(*params)->img_infos->height = --y;
	return (1);
}
