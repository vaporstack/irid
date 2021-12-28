//
//  irid_sim.c
//  irid
//
//  Created by vs on 12/26/21.
//

#include "irid_sim.h"

#include <stdlib.h>

IridSim* irid_sim_create(unsigned long long seed)
{
	IridSim* sim = calloc(1, sizeof(IridSim));
	sim->seed    = seed;
	sim->frame   = 0; //silly, i know
	return sim;
}

void irid_sim_destroy(IridSim* sim)
{
	free(sim);
}

void irid_sim_next(IridSim* sim)
{
	sim->frame++;
}

unsigned long long irid_sim_frame(IridSim* sim)
{
	return sim->frame;
}
