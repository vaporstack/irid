//
//  irid_palette.c
//  irid
//
//  Created by vs on 12/25/21.
//

#include "irid_palette.h"

#include <stdlib.h>

IridPalette* irid_palette_create(void)
{
	IridPalette* pal = calloc(1, sizeof(IridPalette));

	return pal;
}

int irid_palette_add(IridPalette* pal, IridColor* color)
{
	pal->num++;
	if (!pal->data)
	{
		pal->data = calloc(1, sizeof(IridColor));
	}
	else
	{

		pal->data = realloc(pal->data, sizeof(IColor) * pal->num);
	}
	pal->data[pal->num - 1] = color;
	return pal->num;
}

int irid_palette_getn(IridPalette* pal)
{
	return pal->num;
}

void irid_palette_destroy(IridPalette* pal)
{
	if (pal->data)
		free(pal->data);
	free(pal);
}
