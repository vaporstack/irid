//
//  irid_stroke.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_stroke_h
#define irid_stroke_h

#include "irid_color.h"

typedef struct IridStroke
{
	double	  width;
	int	  cap_style;
	IColor16* color;

} IridStroke;

typedef struct IridComplexStroke
{
	int num;
	//	tbd...
} IridComplexStroke;

#endif /* irid_stroke_h */
