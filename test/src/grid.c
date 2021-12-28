
#ifndef irid_test_grid_h_
#define irid_test_grid_h_

#include <irid/irid.h>

#include <stdlib.h>

#define TEST_GRID_W 16
#define TEST_GRID_H 8

static int test_map_unmap(IridGrid* g)
{

	irid_log("grid: %p\n", g);
	for (int i = 0; i < 6; i++)
	{
		long x = rand() % TEST_GRID_W;
		long y = rand() % TEST_GRID_H;
		irid_log("input: %llu, %llu\n", x, y);
		long index = irid_grid_index(g, x, y);
		irid_log("index: %llu\n", index);

		long ux, uy;
		ux = uy = 0;
		irid_grid_unindex(g, index, &ux, &uy);

		if (x != ux || y != uy)
		{
			irid_log("test failed. unmap does not match to map.\n");
			return 1;
		}
		irid_log("unindex: %llu, %llu\n", ux, uy);
	}
}

static int test_refls(IridGrid* grid)
{
}

static int test_rotations(IridGrid* grid)
{
}

static int test_grid(void)
{
	IridGrid* g = irid_grid_create(TEST_GRID_W, TEST_GRID_H);
	test_map_unmap(g);

	return 0;
}

#endif
