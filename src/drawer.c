#include "../includes/fdf.h"

static void		fill_data(t_params **params, t_tile *tile)
{
	*((int*)((*params)->img_infos->data) + tile->x + tile->y * (*params)->img_infos->width)
		^= 0xffffff;
}

static void		draw_line(
	t_params		**params,
	t_tile			tile0,
	t_tile			tile1
)
{
	int dx;
	int dy;
	int err;

	printf("DRAW Y: %d, X: %d --> Y: %d, X: %d\n", tile0.y, tile0.x, tile1.y, tile1.x);
	tile0.x = tile0.x * TILE_WIDTH + (tile0.x ? -1 : 0);
	tile0.y = (tile0.y * TILE_HEIGHT + (tile0.y ? -1 : 0));
	tile1.x = tile1.x * TILE_WIDTH + (tile1.x ? -1 : 0);
	tile1.y = (tile1.y * TILE_HEIGHT + (tile1.y ? -1 : 0));
	dx = abs(tile1.x - tile0.x);
	dy = -abs(tile1.y - tile0.y);
	err = dx + dy;
	while (1)
	{
		fill_data(params, &tile0);
		if (tile0.x == tile1.x && tile0.y == tile1.y)
			break ;
		if (2 * err >= dy
			&& (tile0.x += tile0.x < tile1.x ? 1 : -1))
			err += dy;
		if (2 * err <= dx
			&& (tile0.y += tile0.y < tile1.y ? 1 : -1))
			err += dx;
	}
}

void		draw(t_params **params)
{
	t_tile *tmp;
	t_tile *tmp_find;

	tmp = (*params)->tile;
	while (tmp)
	{
		*((int*)((*params)->img_infos->data)
			+ tmp->x * TILE_WIDTH + (tmp->x ? -1 : 0)
			+ ((tmp->y * TILE_HEIGHT + (tmp->y ? -1 : 0))
			* (*params)->img_infos->width))
			^= 0xffffff;
		if (tmp->x && tmp->next && tmp->next->x < tmp->x)
			draw_line(params, *tmp, *(tmp->next));
		printf("FIND Y %d - %d\n", tmp->y, (*params)->scale);
		if (tmp->y && (tmp_find = find_tile(params, tmp->x, tmp->y - (*params)->scale)))
			draw_line(params, *tmp, *tmp_find);
		tmp = tmp->next;
	}
}