//
//  irid_sim.h
//  irid
//
//  Created by vs on 12/26/21.
//

#ifndef irid_sim_h
#define irid_sim_h

typedef struct IridSim
{
	unsigned long long frame;
	unsigned long long max;
	unsigned long long seed;

} IridSim;

IridSim* irid_sim_create(unsigned long long seed);
void	 irid_sim_destroy(IridSim* sim);

void		   irid_sim_next(IridSim* sim);
unsigned long long irid_sim_frame(IridSim* sim);

#endif /* irid_sim_h */
