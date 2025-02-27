#line 235 "../../../null_macros/c.m4.null.pthread"

#line 1 "particle.C"
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

#include <stdio.h>
#include "defs.h"
#include "memory.h"
#include "particle.h"

#define ONE_EV ((real) 1.6e-19)
#define MAX_FRAC 0.999
#define RANDOM_SIZE 256

/* How many particles can fit on one line */
#define PARTICLES_PER_LINE 8

int Total_Particles;

/* Used to keep track of all the particles. Array in is order of inc id. */
static particle **Particle_List;

particle *InitParticle(real charge, real mass);
void PickShell(vector *v, real radius);
real XRand(real low, real high);


void
CreateDistribution (cluster_type cluster, model_type model)
{
   particle *particle_array;
   int global_num_particles;
   particle *new_particle;
   char particle_state[RANDOM_SIZE];
   real charge;
   real r_scale;
   real v_scale;
   vector r_sum;
   vector v_sum;
   int end_limit;
   int i;
   int j;
   real temp_r;
   real radius;
   real x_vel;
   real y_vel;
   real vel;
   real offset;
   particle *twin_particle;

   particle_array = (particle *) malloc(Total_Particles * sizeof(particle));;

   Particle_List = (particle **) malloc(Total_Particles * sizeof(particle *));;
   for (i = 0; i < Total_Particles; i++)
      Particle_List[i] = &particle_array[i];

   r_scale = 3 * M_PI / 16;
   v_scale = (real) sqrt(1.0 / (double) r_scale);
   r_sum.x = (real) 0.0;
   r_sum.y = (real) 0.0;
   v_sum.x = (real) 0.0;
   v_sum.y = (real) 0.0;
   initstate(0, particle_state, RANDOM_SIZE);
  
   switch (cluster) {
    case ONE_CLUSTER:
      end_limit = Total_Particles;
      switch (model) {
       case UNIFORM:
	 printf("Creating a one cluster, uniform distribution for %d ",
		Total_Particles);
	 printf("particles\n");
	 break;
       case PLUMMER:
	 printf("Creating a one cluster, non uniform distribution for %d ",
		Total_Particles);
	 printf("particles\n");
	 break;
      }
      break;
    case TWO_CLUSTER:
      end_limit = (Total_Particles / 2) + (Total_Particles & 0x1);
      switch (model) {
       case UNIFORM:
	 printf("Creating a two cluster, uniform distribution for %d ",
		Total_Particles);
	 printf("particles\n");
	 break;
       case PLUMMER:
	 printf("Creating a two cluster, non uniform distribution for %d ",
		Total_Particles);
	 printf("particles\n");
	 break;
      }
      break;
   }
   setstate(particle_state);
   global_num_particles = 0;
   charge = 1.0 / Total_Particles;
   charge /= Total_Particles;
   for (i = 0; i < end_limit; i++) {
      new_particle = InitParticle(charge, charge);
      switch (model) {
       case UNIFORM:
	 do {
	    new_particle->pos.x = XRand(-1.0, 1.0);
	    new_particle->pos.y = XRand(-1.0, 1.0);
	    temp_r = DOT_PRODUCT((new_particle->pos), (new_particle->pos));
	 } 
	 while (temp_r > (real) 1.0);
	 radius = sqrt(temp_r);
	 break;
       case PLUMMER:
	 do
	    radius = (real) 1.0 / (real) sqrt(pow(XRand(0.0, MAX_FRAC),
						  -2.0/3.0) - 1);
	 while (radius > 9.0);
	 PickShell(&(new_particle->pos), r_scale * radius);
	 break;
      }
      VECTOR_ADD(r_sum, r_sum, (new_particle->pos));

      do {
	 x_vel = XRand(0.0, 1.0);
	 y_vel = XRand(0.0, 0.1);
      }
      while (y_vel > x_vel * x_vel * (real) pow(1.0 - (x_vel * x_vel), 3.5));
      vel = (real) sqrt(2.0) * x_vel / pow(1.0 + (radius * radius), 0.25);
      PickShell(&(new_particle->vel), v_scale * vel);
      VECTOR_ADD(v_sum, v_sum, (new_particle->vel));
   }

   if (cluster == TWO_CLUSTER) {
      switch (model) {
       case UNIFORM:
	 offset = 1.5;
	 break;
       case PLUMMER:
	 offset = 2.0;
	 break;
      }
      for (i = end_limit; i < Total_Particles; i++) {
	 new_particle = InitParticle(charge, charge);
	 twin_particle = Particle_List[i - end_limit];
	 new_particle->pos.x = twin_particle->pos.x + offset;
	 new_particle->pos.y = twin_particle->pos.y + offset;
	 VECTOR_ADD(r_sum, r_sum, (new_particle->pos));
	 new_particle->vel.x = twin_particle->vel.x;
	 new_particle->vel.y = twin_particle->vel.y;
	 VECTOR_ADD(v_sum, v_sum, (new_particle->vel));
      }
   }

   VECTOR_DIV(r_sum, r_sum, (real) Total_Particles);
   VECTOR_DIV(v_sum, v_sum, (real) Total_Particles);
   for (i = 0; i < Total_Particles; i++) {
      new_particle = Particle_List[i];
      VECTOR_SUB((new_particle->pos), (new_particle->pos), r_sum);
      VECTOR_SUB((new_particle->vel), (new_particle->vel), v_sum);
   }
}


void
CreateParticleList (int my_id, int length)
{
   int cluster_no;
   
   {pthread_mutex_lock(&(G_Memory->mal_lock));};
   Local[my_id].Particles = (particle **) malloc(length 
#line 181
						   * sizeof(particle *));;
#line 183

/* POSSIBLE ENHANCEMENT:  Here is where one might distribute the
   Particles data across physically distributed memories as desired.

   One way to do this is as follows:

   char *starting_address;
   char *ending_address;

   starting_address = (char *) Local[my_id].Particles;
   ending_address = (((char *) Local[my_id].Particles)
		     + (length * sizeof(particle *)) - 1);

   Place all addresses x such that (starting_address <= x < ending_address)
   on node my_id

*/

   {pthread_mutex_unlock(&(G_Memory->mal_lock));};
   Local[my_id].Max_Particles = length;
   Local[my_id].Num_Particles = 0;
}


void
InitParticleList (int my_id, int num_assigned, int starting_id)
{
   int i;
   
   for (i = 0; i < num_assigned; i++)
      Local[my_id].Particles[i] = Particle_List[i + starting_id];
   Local[my_id].Num_Particles = num_assigned;
}


/*
 *  PrintParticle (particle *p)
 *
 *  Args : the address of a particle, p.
 *
 *  Returns : nothing.
 *
 *  Side Effects : Prints to stdout the information stored for p.
 *
 */
void
PrintParticle (particle *p)
{
   if (p != NULL) {
      printf("P %6d :", p->id);
      printf("  Pos    = ");
      PrintVector(&(p->pos));
   }
   else
      printf("Particle has not been initialized yet.\n");
}


void
PrintAllParticles ()
{
   int i;

   fflush(stdout);
   printf("                                   PARTICLE POSITIONS\n\n");
   for (i = 0; i < Total_Particles; i++) {
      PrintParticle(Particle_List[i]);
      printf("\n");
   }
}


void
PrintParticleArrayIds (particle **p_array, int num_particles) 
{
   int tab_count = PARTICLES_PER_LINE;
   int i = 0;
    
   if (num_particles == 0)
      printf("NONE\n");
   else {
      for (i = 0; i < num_particles; i++) {
	 if (tab_count == 0) {
	    tab_count = PARTICLES_PER_LINE;
	    printf("\n");
	 }
	 printf("\tP%d", p_array[i]->id);
	 tab_count -= 1;
      }
      printf("\n");
   }
}


/*
 *  InitParticle (int my_id, real x_pos, real y_pos, real charge)
 *
 *  Args : the x_pos, y_pos, and charge (in eV) of the particle.
 *
 *  Returns : the address of the newly created particle.
 *
 *  Side Effects : Initializes field to 0, and sets the particle ID to a
 *    unique number. Also converts charge to coulombs from eV.
 *
 */
particle *
InitParticle (real charge, real mass)
{
   particle *p;
   static int particle_id = 0;

   p = Particle_List[particle_id];
   p->id = particle_id++;
   p->charge = charge;
   p->mass = mass;
   p->pos.x = (real) 0.0;
   p->pos.y = (real) 0.0;
   p->vel.x = (real) 0.0;
   p->vel.y = (real) 0.0;
   p->acc.x = (real) 0.0;
   p->acc.y = (real) 0.0;
   p->field.r = (real) 0.0;
   p->field.i = (real) 0.0;
   p->cost = 1;
   p->box = 0.0;
   return p;
}


void
PickShell (vector *v, real radius)
{
   real temp_r;
   real r_scale;
    
   do {
      v->x = XRand(-1.0, 1.0);
      v->y = XRand(-1.0, 1.0);
      temp_r = DOT_PRODUCT((*v), (*v));
   }
   while (temp_r >1.0);
   r_scale = radius / (real) sqrt(temp_r);
   VECTOR_MUL((*v), (*v), r_scale);
}


real
XRand (real low, real high)
{
   real ret_val;

   ret_val = low  + (high - low) * ((real) random() / 2147483647.0);
   return ret_val;
}


#undef PARTICLES_PER_LINE
#undef MAX_FRAC
#undef RANDOM_SIZE
#undef ONE_EV
