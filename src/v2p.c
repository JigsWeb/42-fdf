#include "../includes/fdf.h"

t_mat	*pp_mat(t_params **params)
{
	t_mat *m;

	m = create_mat();
	m->arr[0][0] = 1 / tan((*params)->camr->fov_x / 2);
	m->arr[1][1] = 1 / tan((*params)->camr->fov_y / 2);
	m->arr[2][2] = - (((*params)->camr->z_far + (*params)->camr->z_near)
		/ ((*params)->camr->z_far - (*params)->camr->z_near));
	m->arr[2][3] = -(2 * ((*params)->camr->z_near * (*params)->camr->z_far))
		/ ((*params)->camr->z_far - (*params)->camr->z_near);
	m->arr[3][2] = -1;
	return (m);
}

t_mat	*op_mat(t_params **params)
{
	t_mat *m;
	(void)params;
	m = create_mat();
	// m->arr[0][0] = 1.00 / WINDOW_WIDTH;
	// m->arr[1][1] = 1.00 / WINDOW_HEIGHT;
	// m->arr[2][2] = 2.00 / ((*params)->camr->z_far - (*params)->camr->z_near);
	// m->arr[2][3] = ((*params)->camr->z_far + (*params)->camr->z_near)
	// 	/ ((*params)->camr->z_far - (*params)->camr->z_near);
	m->arr[2][2] = -1.00;
	return (m);
}

void	v2p(t_params **params)
{
	t_mat *m;

	if ((*params)->camr->tp == OP_TYPE)
		m = op_mat(params);
	else if ((*params)->camr->tp == PP_TYPE)
		m = op_mat(params);
	else if ((*params)->camr->tp == CP_TYPE)
		m = op_mat(params);
}