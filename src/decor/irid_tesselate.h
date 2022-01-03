//
//  irid_tesselate.h
//  irid
//
//  Created by vs on 12/26/21.
//

#ifndef irid_tesselate_h
#define irid_tesselate_h

#include <irid/src/core/irid_point.h>

typedef struct IridTessTile
{
	int	  num;
	int	  axes;
	IridPoint anchor;

} IridTessTile;

/*
	cheat sheet from : https://en.wikipedia.org/wiki/Wallpaper_group
	p: primitive
	c: face-centered
	N: highest order of rotation symmetry
	m: mirror
	g: glide
	1: none
*/

typedef enum
{
	IRID_SYM_P1,
	IRID_SYM_P2,
	IRID_SYM_PM,
	IRID_SYM_PG,
	IRID_SYM_CM,
	IRID_SYM_PMM,
	IRID_SYM_PMG,
	IRID_SYM_PGG,
	IRID_SYM_CMM,
	IRID_SYM_P4,
	IRID_SYM_P4M,
	IRID_SYM_P4G,
	IRID_SYM_P3,
	IRID_SYM_P3M1,
	IRID_SYM_P31M,
	IRID_SYM_P6,
	IRID_SYM_P6M
} IRID_SYMMETRY_TYPES;

typedef enum
{
	IRID_CELL_OBLIQUE,
	IRID_CELL_HEXAGONAL,
	IRID_CELL_RECTANGULAR,
	IRID_CELL_RHOMBIC,
	IRID_CELL_SQUARE
} IRID_CELL_TYPES;

IridTessTile* irid_tess_tile_create(int type);
void	      irid_tess_tile_destroy(IridTessTile* tile);

#endif /* irid_tesselate_h */
