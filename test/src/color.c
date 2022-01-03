
#ifndef irid_test_color_h_
#define irid_test_color_h_

#include <irid/irid.h>

#include <stdlib.h>

int test_color(void)
{
	IridColor c;
	for (int i = 0; i < 32; i++)
	{
		c.r = rand() % 255;
		c.g = rand() % 1024;
		c.b = rand() % 2048;

		irid_color_clamp(&c);
		irid_log("random color: %d %d %d", c.r, c.g, c.b);
	}
	return 0;
}

#endif
