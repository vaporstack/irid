//
//  irid_render.h
//  irid
//
//  Created by vs on 12/26/21.
//

#ifndef irid_render_h
#define irid_render_h

#include <stdbool.h>
#include "../core/irid_tile.h"

bool irid_render_set_tile_render_cb(void);
void irid_render_tile(IridTile* tile, long x, long y);

#endif /* irid_render_h */
