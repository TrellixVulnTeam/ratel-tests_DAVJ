#line 235 "../../../null_macros/c.m4.null.pthread"

#line 1 "defs.C"
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
#include <stdarg.h>
#include <math.h>
#include "defs.h"
#include "memory.h"

int Number_Of_Processors;
double Timestep_Dur;
real Softening_Param;
int Expansion_Terms;


real
RoundReal (real val)
{
   double shifter;
   double frac;
   int exp;
   double shifted_frac;
   double new_frac;
   double temp;
   real ret_val;

   shifter = pow((double) 10, (double) REAL_DIG - 2);
   frac = frexp((double) val, &exp);
   shifted_frac = frac * shifter;
   temp = modf(shifted_frac, &new_frac);
   new_frac /= shifter;
   ret_val = (real) ldexp(new_frac, exp);
   return ret_val;
}


void
PrintComplexNum (complex *c)
{
   if (c->i >= (real) 0.0)
      printf("%e + %ei", c->r, c->i);
   else
      printf("%e - %ei", c->r, -c->i);
}


void
PrintVector (vector *v)
{
   printf("(%10.5f, %10.5f)", v->x, v->y);
}


void
LockedPrint (char *strformat, ...)
{
   va_list ap;

   va_start(ap, strformat);
   {pthread_mutex_lock(&(G_Memory->io_lock));};
   fflush(stdout);
   vfprintf(stdout, strformat, ap);
   fflush(stdout);
   {pthread_mutex_unlock(&(G_Memory->io_lock));};
   va_end(ap);
}


