#line 235 "../../../null_macros/c.m4.null.pthread"

#line 1 "cost_zones.C"
/*************************************************************************/
/*                                                                       */
/*  Copyright (c) 1994 Stanford University                               */
/*                                                                       */
/*  All rights reserved.                                                 */
/*                                                                       */
/*  Permission is given to use, copy, and modify this software for any   */
/*  non-commercial purpose as long as this copyright notice is not       */
/*  removed.  All other uses, including redistribution in whole or in    */
/*  part, are forbidden without prior written permission.                */
/*                                                                       */
/*  This software is provided with absolutely no warranty and no         */
/*  support.                                                             */
/*                                                                       */
/*************************************************************************/

#include "defs.h"
#include "memory.h"
#include "box.h"
#include "partition_grid.h"
#include "cost_zones.h"

#define NUM_DIRECTIONS 4

typedef enum { RIGHT, LEFT, UP, DOWN } direction;

static int Child_Sequence[NUM_DIRECTIONS][NUM_OFFSPRING] = 
{
   { 0, 1, 2, 3 },
   { 2, 3, 0, 1 },
   { 0, 3, 2, 1 },
   { 2, 1, 0, 3 },
};
static int Direction_Sequence[NUM_DIRECTIONS][NUM_OFFSPRING] =
{
   { UP, RIGHT, RIGHT, DOWN },
   { DOWN, LEFT, LEFT, UP },
   { RIGHT, UP, UP, LEFT },
   { LEFT, DOWN, DOWN, RIGHT },
};

void ComputeSubTreeCosts(int my_id, box *b);
void CostZonesHelper(int my_id, box *b, int work, direction dir);


void
CostZones (int my_id)
{
   int i;
   box *b;
  
   PartitionIterate(my_id, ComputeSubTreeCosts, BOTTOM);
   {
#line 53
	unsigned long	Error, Cycle;
#line 53
	int		Cancel, Temp;
#line 53

#line 53
	Error = pthread_mutex_lock(&(G_Memory->synch).mutex);
#line 53
	if (Error != 0) {
#line 53
		printf("Error while trying to get lock in barrier.\n");
#line 53
		exit(-1);
#line 53
	}
#line 53

#line 53
	Cycle = (G_Memory->synch).cycle;
#line 53
	if (++(G_Memory->synch).counter != (Number_Of_Processors)) {
#line 53
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &Cancel);
#line 53
		while (Cycle == (G_Memory->synch).cycle) {
#line 53
			Error = pthread_cond_wait(&(G_Memory->synch).cv, &(G_Memory->synch).mutex);
#line 53
			if (Error != 0) {
#line 53
				break;
#line 53
			}
#line 53
		}
#line 53
		pthread_setcancelstate(Cancel, &Temp);
#line 53
	} else {
#line 53
		(G_Memory->synch).cycle = !(G_Memory->synch).cycle;
#line 53
		(G_Memory->synch).counter = 0;
#line 53
		Error = pthread_cond_broadcast(&(G_Memory->synch).cv);
#line 53
	}
#line 53
	pthread_mutex_unlock(&(G_Memory->synch).mutex);
#line 53
};
   Local[my_id].Total_Work = Grid->subtree_cost;
   Local[my_id].Min_Work = ((Local[my_id].Total_Work / Number_Of_Processors)
			   * my_id);
   if (my_id == (Number_Of_Processors - 1))
      Local[my_id].Max_Work = Local[my_id].Total_Work;
   else
      Local[my_id].Max_Work = (Local[my_id].Min_Work
			      + (Local[my_id].Total_Work
				 / Number_Of_Processors));
   InitPartition(my_id);
   CostZonesHelper(my_id, Grid, 0, RIGHT);
   {
#line 65
	unsigned long	Error, Cycle;
#line 65
	int		Cancel, Temp;
#line 65

#line 65
	Error = pthread_mutex_lock(&(G_Memory->synch).mutex);
#line 65
	if (Error != 0) {
#line 65
		printf("Error while trying to get lock in barrier.\n");
#line 65
		exit(-1);
#line 65
	}
#line 65

#line 65
	Cycle = (G_Memory->synch).cycle;
#line 65
	if (++(G_Memory->synch).counter != (Number_Of_Processors)) {
#line 65
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &Cancel);
#line 65
		while (Cycle == (G_Memory->synch).cycle) {
#line 65
			Error = pthread_cond_wait(&(G_Memory->synch).cv, &(G_Memory->synch).mutex);
#line 65
			if (Error != 0) {
#line 65
				break;
#line 65
			}
#line 65
		}
#line 65
		pthread_setcancelstate(Cancel, &Temp);
#line 65
	} else {
#line 65
		(G_Memory->synch).cycle = !(G_Memory->synch).cycle;
#line 65
		(G_Memory->synch).counter = 0;
#line 65
		Error = pthread_cond_broadcast(&(G_Memory->synch).cv);
#line 65
	}
#line 65
	pthread_mutex_unlock(&(G_Memory->synch).mutex);
#line 65
};
}


void
ComputeSubTreeCosts (int my_id, box *b)
{
   box *pb;
   box *sb;
   int i;
   box *cb;

   if (b->type == PARENT) {
      while (b->interaction_synch != b->num_children) {
      }
   }
   b->interaction_synch = 0;
   ComputeCostOfBox(my_id, b);
   b->subtree_cost += b->cost;
   pb = b->parent;
   if (pb != NULL) {
      {pthread_mutex_lock(&G_Memory->lock_array[pb->exp_lock_index]);};
      pb->subtree_cost += b->subtree_cost;
      pb->interaction_synch += 1;
      {pthread_mutex_unlock(&G_Memory->lock_array[pb->exp_lock_index]);};
   }
}


void
CostZonesHelper (int my_id, box *b, int work, direction dir)
{
   box *cb;
   int i;
   int parent_cost;
   int *next_child;
   int *child_dir;

   if (b->type == CHILDLESS) {
      if (work >= Local[my_id].Min_Work)
	 InsertBoxInPartition(my_id, b);
   }
   else {
      next_child = Child_Sequence[dir];
      child_dir = Direction_Sequence[dir];
      for (i = 0; (i < NUM_OFFSPRING) && (work < Local[my_id].Max_Work);
	   i++) {
	 cb = b->children[next_child[i]];
	 if (cb != NULL) {
	    if ((work + cb->subtree_cost) >= Local[my_id].Min_Work)
	       CostZonesHelper(my_id, cb, work, child_dir[i]);
	    work += cb->subtree_cost;
	 }
	 if (i == 2) {
	    if ((work >= Local[my_id].Min_Work)
		&& (work < Local[my_id].Max_Work))
	       InsertBoxInPartition(my_id, b);
	    work += b->cost;
	 }
      }
   }

}


#undef DOWN
#undef UP
#undef LEFT
#undef RIGHT
#undef NUM_DIRECTIONS

