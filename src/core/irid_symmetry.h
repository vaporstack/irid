//
//  irid_symmetry.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_symmetry_h
#define irid_symmetry_h

typedef struct IridSymmetry
{
	int type_mirror;
	int type_radial;

} IridSymmetry;

typedef enum
{
	IRID_SYMMETRY_TYPE_MIRROR_X,
	IRID_SYMMETRY_TYPE_MIRROR_Y,
} IRID_SYMMETRY_TYPE_TBD;

#endif /* irid_symmetry_h */
