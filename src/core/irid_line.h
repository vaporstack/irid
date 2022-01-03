//
//  irid_line.h
//  irid
//
//  Created by vs on 1/4/22.
//

#ifndef irid_line_h
#define irid_line_h

#include "irid_point.h"

typedef struct IridLineSeg
{
	IridPoint a;
	IridPoint b;

} IridLineSeg;

typedef struct IridLine
{
	IridPoint a;
	IridPoint b;
} IridLine;

typedef struct IridPolyLine
{
	unsigned long long num;
	IridPoint*	   data;
} IridPolyLine;

typedef struct IridPoly
{
	unsigned long long num;
	IridPoint*	   data;
	bool		   closed;
} IridPoly;

#endif /* irid_line_h */
