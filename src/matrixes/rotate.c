#include "fdf.h"

t_mat	*rot_x_mat(float d)
{
	t_mat *m;
	float c;
	float s;

	c = cos(d);
	s = sin(d);
	m = create_mat();
	m->arr[1][1] = c;
	m->arr[1][2] = -s;
	m->arr[2][1] = s;
	m->arr[2][2] = c;
	return (m);
}

t_mat	*rot_z_mat(float d)
{
	t_mat *m;
	float c;
	float s;

	c = cos(d);
	s = sin(d);
	m = create_mat();
	m->arr[0][0] = c;
	m->arr[0][1] = -s;
	m->arr[1][0] = s;
	m->arr[1][1] = c;
	return (m);
}

t_mat	*rot_y_mat(float d)
{
	t_mat *m;
	float c;
	float s;

	c = cos(d);
	s = sin(d);
	m = create_mat();
	m->arr[0][0] = c;
	m->arr[0][2] = s;
	m->arr[2][0] = -s;
	m->arr[2][2] = c;
	return (m);
}