//
//  irid_grid.c
//  irid
//
//  Created by vs on 12/25/21.
//

#include "irid_grid.h"

#include <stdlib.h>

IridGrid* irid_grid_create(int r, int c)
{
	IridGrid* grid = calloc(1, sizeof(IridGrid));
	grid->width    = r;
	grid->height   = c;
	return grid;
}

IridGridHnd* irid_grid_hnd_create(int r, int c)
{
	IridGridHnd* hnd = calloc(1, sizeof(IridGridHnd));
	hnd->src	 = irid_grid_create(r, c);
	return hnd;
}

void irid_grid_hnd_destroy(IridGridHnd* hnd)
{
	irid_grid_destroy(hnd->src);
	free(hnd);
}

void irid_grid_destroy(IridGrid* grid)
{
	free(grid);
}
/*
void r_input_monome_uncalc_index(MonomeRec* m, int index, int* _x, int* _y, double scale)
{
	if ( scale <= 0 )
	{
		scale = 1;
	}
	int x = (index % m->width * scale) ;
	int y = (index / (m->width) * scale * 2);
	//printf("Uncalc [%d] -> %d %d\n", index, x, y);
	*_x = x;
	*_y = y;
}

int r_input_monome_calc_index(MonomeRec* m, int x, int y)
{
	return (m->width * y) + x;
}

//
//	handler definitions
//
*/

long irid_grid_index(IridGrid* grid, long x, long y)
{
	return (grid->width * y) + x;
}

void irid_grid_unindex(IridGrid* grid, long index, long* x, long* y)
{
	long lx = (index % grid->width);
	long ly = index / (grid->width);
	*x	= lx;
	*y	= ly;
}

bool irid_grid_within(IridGrid* grid, double x, double y)
{
	return false;
}

bool irid_grid_within_scaled(IridGrid* grid, double x, double y)
{
	double w = grid->width * grid->cell_size;
	double h = grid->height * grid->cell_size;
	if (x < w && y < h && x > 0 && y > 0)
		return true;

	return false;
}

long irid_grid_cell_from_coords(IridGrid* grid, double x, double y)
{
	return -1;
}

long irid_grid_cell_from_coords_scaled(IridGrid* grid, double x, double y)
{
	long mod_x = x / grid->cell_size;
	long mod_y = y / grid->cell_size;
	long lut   = irid_grid_index(grid, mod_x, mod_y);
	return lut;
}

void irid_grid_set_scale(IridGrid* grid, double x)
{
	grid->cell_size = x;
}

static bool irid_grid_tile_allocate(IridGrid* grid)
{
	long num = grid->width * grid->height;

	grid->tiles = calloc(num, sizeof(IridTile));
	if (!grid->tiles)
	{
		//	calloc failed
		return false;
	}
	return true;
}

static bool irid_grid_tile_allocate_check(IridGrid* grid)
{
	if (grid->tiles)
		return true;

	bool succ = irid_grid_tile_allocate(grid);
	return succ;
}

IridTile* irid_grid_tile_from_cell_index(IridGrid* grid, long index)
{
	if (!irid_grid_tile_allocate_check(grid))
		return NULL;

	IridTile* tile = grid->tiles[index];
	if (tile == NULL)
	{
		tile		   = irid_tile_create();
		tile->index	   = index;
		grid->tiles[index] = tile;
	}
	return tile;
}

IridTile* irid_grid_tile_from_cell_xy(IridGrid* grid, long x, long y)
{
	long index = irid_grid_index(grid, x, y);
	return irid_grid_tile_from_cell_index(grid, index);
}
