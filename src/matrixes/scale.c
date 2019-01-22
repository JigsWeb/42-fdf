#include "fdf.h"

t_mat *scale_mat(t_vctr *v)
{
	t_mat *m;

	m = create_mat();
	m->arr[0][0] = v->x;
	m->arr[1][1] = v->y;
	m->arr[2][2] = v->z;
	return (m);
}