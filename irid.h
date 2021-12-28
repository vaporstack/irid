//
//  irid.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_h
#define irid_h

#include "src/core/irid_grid.h"
#include "src/core/irid_layer.h"
#include "src/core/irid_tile.h"
#include "src/util/irid_log.h"

typedef struct IridRec
{
	int	   num;
	IridLayer* layers;

} IridRec;

IridRec* irid_create(void);
void	 irid_destroy(IridRec* rec);

#endif /* irid_h */
