
#ifndef irid_test_palette_h_
#define irid_test_palette_h_

#include <irid/irid.h>

// #include <irid/util/irid_log.h>
#include <stdlib.h>

int test_palette(void)
{
	irid_log("hello");
	IColor r =
	    {
		255,
		15,
		65

	    };
	IColor o =
	    {
		253,
		160,
		26

	    };

	IColor y =
	    {
		248,
		229,
		69

	    };

	IColor g =
	    {
		2,
		211,
		4

	    };

	IColor b =
	    {
		13,
		91,
		241

	    };

	IColor v =
	    {
		118,
		38,
		219

	    };

	IColor rainbow[] = {r, o, y, g, b, v};

	IridPalette* p = irid_palette_create();
	irid_palette_add(p, &r);
	irid_palette_add(p, &o);
	irid_palette_add(p, &y);

	irid_palette_destroy(p);

	return 0;
};

#endif
