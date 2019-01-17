#include "../includes/fdf.h"

// t_tile	*find_tile(t_params **params, int x, int y)
// {
// 	t_tile *tmp;

// 	tmp = (*params)->tile;
// 	while (tmp && (tmp->x != x || tmp->y != y))
// 		tmp = tmp->next;
// 	return (tmp);
// }

void		apply_mat(t_vctr **v, t_mat *m)
{
	float x;
	float y;
	float z;

	x = m->x_axis->x * (*v)->x + m->y_axis->x * (*v)->y + m->z_axis->x * (*v)->z + m->ts->x * (*v)->w;
	y = m->x_axis->y * (*v)->x + m->y_axis->y * (*v)->y + m->z_axis->y * (*v)->z + m->ts->y * (*v)->w;
	z = m->x_axis->z * (*v)->x + m->y_axis->z * (*v)->y + m->z_axis->z * (*v)->z + m->ts->z * (*v)->w;
	(*v)->x = x;
	(*v)->y = y;
	(*v)->z = z;
}
