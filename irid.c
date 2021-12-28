//
//  irid.c
//  irid
//
//  Created by vs on 12/25/21.
//

#include "irid.h"

#include <stdlib.h>

IridRec* irid_create(void)
{
	IridRec* rec = calloc(1, sizeof(IridRec));
	return rec;
}
void irid_destroy(IridRec* rec)
{
	free(rec);
}
