//
//  irid_palette.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_palette_h
#define irid_palette_h

#include "irid_color.h"

typedef struct IridPalette
{
	int    num;
	void** colors;
} IridPalette;

IridPalette* irid_palette_create(void);
int	     irid_palette_add(void* color);
int	     irid_palette_getn(IridPalette*);
void	     irid_palette_destroy(IridPalette*);

#endif /* irid_palette_h */
