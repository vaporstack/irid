//
//  irid_color.h
//  irid
//
//  Created by vs on 12/25/21.
//

#ifndef irid_color_h
#define irid_color_h

typedef struct
{
	int r;
	int g;
	int b;
	int a;
} IColor;

typedef IColor IColor8;
typedef IColor IridColor;

typedef struct
{
	float r;
	float g;
	float b;
	float a;
} IColor16;

typedef struct
{
	double r;
	double g;
	double b;
	double a;
} IColor32;

typedef struct
{
	double r; // a fraction between 0 and 1
	double g; // a fraction between 0 and 1
	double b; // a fraction between 0 and 1
} irid_rgb;

typedef struct
{
	double h; // angle in degrees
	double s; // a fraction between 0 and 1
	double v; // a fraction between 0 and 1
} irid_hsv;

//	hue is 0-360
irid_hsv irid_rgb2hsv(irid_rgb in);
irid_rgb irid_hsv2rgb(irid_hsv in);

int  irid_color_clamp(IColor* col);
void irid_color_8_clear(IColor* col);
void irid_color_16_clear(IColor16* col);

#endif /* irid_color_h */
