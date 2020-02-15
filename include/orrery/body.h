#ifndef BODY_H
#define BODY_H 

#include <stdio.h>
#include <math.h>
#include "SpiceUsr.h"
#include "SpiceZfc.h"
#include "orrery/threeVector.h"

/*
typedef enum {
  SOLAR_SYSTEM_BARYCENTER,
  MERCURY_BARYCENTER,
  VENUS_BARYCENTER,
  EARTH_BARYCENTER,
  MARS_BARYCENTER,
  JUPITER_BARYCENTER,
  SATURN_BARYCENTER,
  URANUS_BARYCENTER,
  NEPTUNE_BARYCENTER,
  PLUTO_BARYCENTER,
  SUN_BARYCENTER 
} body_t;
*/

typedef struct{
  char name[64];
  ThreeVector pos[3],ang_mom[3];
} Body;

void LoadMetaKernel(char *filename);
void GetBodyCoordinates(char *date, char *body, double coords[3]);


#endif
