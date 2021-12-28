//
//  irid_tile.c
//  irid
//
//  Created by vs on 12/25/21.
//

#include "irid_tile.h"

#include <stdlib.h>

IridTile* irid_tile_create(void)
{
	return calloc(1, sizeof(IridTile));
}

IridTile* irid_tile_create_xy(long x, long y)
{
	IridTile* tile = irid_tile_create();
	tile->x	       = x;
	tile->y	       = y;
	return tile;
}

void irid_tile_destroy(IridTile* tile)
{
	free(tile);
}

void irid_tile_action(IridTile* tile, long action, void* data)
{
	switch (action)
	{
		case IRID_TILE_ACTION_FLIP_X:
			tile->flip_x = !tile->flip_x;
			break;
		
		default:
			break;
			
	}
}
