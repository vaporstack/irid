//
//  test_irid.c
//  irid_dev
//
//  Created by vs on 12/25/21.
//

#include "grid.c"
#include <stdio.h>

#include <irid/irid.h>

extern int test_grid(void);
extern int test_palette(void);
extern int test_color(void);

int main(int argc, char** argv)
{

	IridRec* rec = irid_create();
	irid_destroy(rec);

	test_grid();
	test_palette();
	test_color();
	return 0;
}
