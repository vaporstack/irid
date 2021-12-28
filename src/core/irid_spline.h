//
//  irid_spline.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_spline_h
#define irid_spline_h

typedef struct IridSpline
{
	int type;
} IridSpline;


typedef enum
{
	IRID_SPLINE_TYPE_LINEAR,
	IRID_SPLINE_TYPE_ARC,
	IRID_SPLINE_TYPE_BEZIER,
	IRID_SPLINE_TYPE_CUSTOM,
	IRID_SPLINE_TYPE_NONE
} IRID_SPLINE_TYPES;


#endif /* irid_spline_h */
