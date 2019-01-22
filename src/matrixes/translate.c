#include "fdf.h"

t_mat	*ts_mat(t_vctr *v)
{
	t_mat *m;

	m = create_mat();
	m->arr[0][3] = v->x;
	m->arr[1][3] = -v->y;
	m->arr[2][3] = v->z;
	m->arr[3][3] = v->w;
	return (m);
}