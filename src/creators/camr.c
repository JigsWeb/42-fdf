#include "../includes/fdf.h"

t_camr	*create_camr()
{
	t_camr *c;

	if(!(c = (t_camr*)ft_memalloc(sizeof(t_camr))))
		return (NULL);
	c->tp = OP_TYPE;
	c->z_near = 0.00;
	c->z_far = 100;
	c->fov_x = 30.00;
	c->fov_y = 30.00;
	return (c);
}