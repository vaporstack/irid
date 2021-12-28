//
//  wsh_log.c
//  wsh
//
//  Created by vs on 2/22/19.
//  Copyright © 2019 vaporstack. All rights reserved.
//

#include "irid_log.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define IRID_LOG_MAX 512

void irid_log(char* format, ...)
{

	char buf[IRID_LOG_MAX];
	sprintf(buf, "%s", format);
	va_list args;
	va_start(args, format);
	vsprintf(buf, format, args);
	va_end(args);

#ifdef DEBUG
	printf("[irid]: %s\n", buf);
#else
#endif
}
