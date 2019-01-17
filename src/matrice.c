#include "../includes/fdf.h"

// void		set_matrice(t_params **params, char *name, void *extra)
// {
// 	float ***m;

// 	m = &((*params)->m);
// 	(*m)[0][0] = 1;
// 	(*m)[1][1] = 1;
// 	(*m)[2][2] = 1;
// 	(*m)[3][3] = 1;
// 	if (ft_strequ("translation", name))
// 	{
// 		(*m)[0][3] = ((t_vector*)extra)->x;
// 		(*m)[1][3] = ((t_vector*)extra)->y;
// 		(*m)[2][3] = ((t_vector*)extra)->z;
// 	}
// 	else if (ft_strequ("scale", name))
// 	{
// 		(*m)[0][0] = ((t_vector*)extra)->x;
// 		(*m)[1][1] = ((t_vector*)extra)->y;
// 		(*m)[2][2] = ((t_vector*)extra)->z;
// 		(*params)->scale = ((t_vector*)extra)->x;
// 	}
// 	else if (ft_strequ("rotationX", name))
// 	{
// 		(*m)[1][1] = cos(*(int*)extra);
// 		(*m)[1][2] = sin(*(int*)extra);
// 		(*m)[2][1] = sin(*(int*)extra);
// 		(*m)[2][2] = cos(*(int*)extra);
// 		(*params)->scale = ((t_vector*)extra)->x;
// 	}
// 	else if(ft_strequ("isometric", name))
// 	{
// 		(*m)[0][0] = 0.70710678118;
// 		(*m)[0][1] = -0.70710678118;
// 		(*m)[1][0] = -0.40824829046;
// 		(*m)[1][1] = -0.40824829046;
// 		(*m)[1][2] = 0.81649658092;
// 	}
// }

// void		apply_matrice(t_params **params)
// {
// 	t_tile *tmp;
// 	float x;
// 	float y;
// 	float z;

// 	(*params)->img_infos->height = 0;
// 	(*params)->img_infos->width = 0;
// 	tmp = (*params)->tile;
// 	while (tmp)
// 	{
// 		x = (*params)->m[0][0] * tmp->x
// 			+ (*params)->m[0][1] * tmp->y
// 			+ (*params)->m[0][2] * tmp->z
// 			+ (*params)->m[0][3] * 1;
// 		y = (*params)->m[1][0] * tmp->x
// 			+ (*params)->m[1][1] * tmp->y
// 			+ (*params)->m[1][2] * tmp->z
// 			+ (*params)->m[1][3] * 1;
// 		z = (*params)->m[2][0] * tmp->x
// 			+ (*params)->m[2][1] * tmp->y
// 			+ (*params)->m[2][2] * tmp->z
// 			+ (*params)->m[2][3] * 1;
// 		tmp->x = round(x);
// 		tmp->y = round(y);
// 		tmp->z = round(z);
// 		printf("APPLY Y: %d, X: %d to Y: %f, X: %f\n", tmp->y, tmp->x, y, x);
// 		if (tmp->y * (TILE_HEIGHT + 1) > (*params)->img_infos->height)
// 			(*params)->img_infos->height = tmp->y * (TILE_HEIGHT + 1); //@TODO check this kind of operation, maybe false
// 		if (tmp->x * (TILE_WIDTH + 1) > (*params)->img_infos->width)
// 			(*params)->img_infos->width = tmp->x * (TILE_WIDTH + 1);
// 		tmp = tmp->next;
// 	}
// }