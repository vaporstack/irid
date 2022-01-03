//
//  irid_tesselate.c
//  irid
//
//  Created by vs on 12/26/21.
//

#include "irid_tesselate.h"

#include <irid/irid.h>
#include <stdlib.h>

IridTessTile* irid_tess_tile_create(int type)
{
	switch (type)
	{
	case IRID_SYM_P1:
		irid_log("yay\n");
		break;
	case IRID_SYM_P2:
		irid_log("yay12\n");
		break;
	default:
		break;
	}

	return NULL;
}

void irid_tess_tile_destroy(IridTessTile* tile)
{
	free(tile);
}
