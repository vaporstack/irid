//
//  irid_grid.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_grid_h
#define irid_grid_h

#include <stdbool.h>
// #include <stdio.h>

#include "irid_tile.h"

typedef struct IridMovementConstraints
{
	int restrict_x;
	int restrict_y;
} IridMovementConstraints;

typedef struct IridGrid
{
	int	   width;
	int	   height;
	double	   cell_size;
	bool	   mirror_x;
	bool	   mirror_y;
	IridTile** tiles;
	void*	   constraints;

} IridGrid;

typedef struct IridGridHnd
{
	IridGrid* src;
} IridGridHnd;

//	basics

IridGrid* irid_grid_create(int r, int c);
void	  irid_grid_destroy(IridGrid* grid);

IridGridHnd* irid_grid_hnd_create(int r, int c);
void	     irid_grid_hnd_destroy(IridGridHnd* hnd);

//	utility

long irid_grid_index(IridGrid* grid, long x, long y);
void irid_grid_unindex(IridGrid* grid, long index, long* x, long* y);
long irid_grid_flip_x(IridGrid* grid, long x, long y, long* ox, long* oy);
long irid_grid_flip_y(IridGrid* grid, long x, long y, long* ox, long* oy);

bool irid_grid_within(IridGrid* grid, double x, double y);
bool irid_grid_within_scaled(IridGrid* grid, double x, double y);

long irid_grid_cell_from_coords(IridGrid* grid, double x, double y);
long irid_grid_cell_from_coords_scaled(IridGrid* grid, double x, double y);

//	ui
void irid_grid_set_scale(IridGrid* grid, double x);

//	tile ops
// void irid_grid_reflect(Irid)
//	simulation
void irid_grid_move(IridGrid* grid, long ax, long ay, long bx, long by, long* rx, long* ry);
// void irid_grid_tile_action(IridGrid* grid, long x, long y, long action, void* user);

//	tile manipulation

IridTile* irid_grid_tile_from_cell_index(IridGrid* grid, long index);
IridTile* irid_grid_tile_from_cell_xy(IridGrid* grid, long x, long y);

#endif /* irid_grid_h */
