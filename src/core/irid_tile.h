//
//  irid_tile.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_tile_h
#define irid_tile_h

#include <stdbool.h>

typedef enum
{
	IRID_TILE_ACTION_FLIP_X,
	IRID_TILE_ACTION_FLIP_Y,
	IRID_TILE_ACTION_ROTATE_RIGHT_ONCE,
	IRID_TILE_ACTION_ROTATE_LEFT_ONCE,
	IRID_TILE_ACTION_ROTATE_ARB,
} IRID_GRID_TILE_ACTION_TYPES;

typedef struct IridTile
{
	long x;
	long y;
	bool flip_x;
	bool flip_y;
	int  rotation;
	long index;
} IridTile;

IridTile* irid_tile_create(void);
IridTile* irid_tile_create_xy(long x, long y);
void	  irid_tile_destroy(IridTile* tile);

void irid_tile_action(IridTile* tile, long action, void* data);

#endif /* irid_tile_h */
