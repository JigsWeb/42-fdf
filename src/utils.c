#include "../includes/fdf.h"

// t_tile	*find_tile(t_params **params, int x, int y)
// {
// 	t_tile *tmp;

// 	tmp = (*params)->tile;
// 	while (tmp && (tmp->x != x || tmp->y != y))
// 		tmp = tmp->next;
// 	return (tmp);
// }

t_mat			*mult_mat(t_mat *m0, t_mat *m1)
{
	t_mat	*res;
	int a;
	int b;
	int c;

	res = (t_mat*)ft_memalloc(sizeof(t_mat));
	res->len = m0->len;
	res->arr = (float**)ft_memalloc(sizeof(float*) * m0->len);
	a = -1;
	while (++a < res->len && (b = -1))
	{
		if (!res->arr[a] && !(res->arr[a] = (float*)ft_memalloc(sizeof(float) * m0->len)))
			return (NULL);
		while (++b < res->len && (c = -1))
			while (++c < res->len)
				res->arr[a][b] += m0->arr[a][c] * m1->arr[c][b];
	}
	return (res);
}

void		apply_mat(t_mat *m, t_vctr *v)
{
	float x;
	float y;
	float z;
	float w;

	x = m->arr[0][0] * v->x + m->arr[0][1] * v->y + m->arr[0][2] * v->z + m->arr[0][3] * v->w;
	y = m->arr[1][0] * v->x + m->arr[1][1] * v->y + m->arr[1][2] * v->z + m->arr[1][3] * v->w;
	z = m->arr[2][0] * v->x + m->arr[2][1] * v->y + m->arr[2][2] * v->z + m->arr[2][3] * v->w;
	w = m->arr[3][0] * v->x + m->arr[3][1] * v->y + m->arr[3][2] * v->z + m->arr[3][3] * v->w;
	v->x = x;
	v->y = y;
	v->z = z;
}