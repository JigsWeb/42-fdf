#include "fdf.h"

t_mat		*create_mat()
{
	t_mat *m;
	int i;

	m = (t_mat*)ft_memalloc(sizeof(t_mat));
	m->len = 4;
	m->arr = (float**)ft_memalloc(sizeof(float*) * 4);
	i = -1;
	while (++i < 4)
	{
		m->arr[i] = (float*)ft_memalloc(sizeof(float) * 4);
		ft_bzero(m->arr[i], sizeof(float) * 4);
		m->arr[i][i] = 1.00;
	}
	return (m);
}