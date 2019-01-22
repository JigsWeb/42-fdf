#include "fdf.h"

t_vctr		*create_vctr(float x, float y, float z, float w)
{
	t_vctr *v;

	v = (t_vctr*)ft_memalloc(sizeof(t_vctr));
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
	return (v);
}