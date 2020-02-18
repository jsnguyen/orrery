#ifndef BODY_H
#define BODY_H 

#include <stdio.h>
#include <math.h>
#include <string.h>
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
  double time;
  ThreeVector pos[3],ang_mom[3];
} Body;

void CopyString(char *dest, char *source, int dest_size);
void CSPICELoadMetaKernel(char *filename);

void BodySetName(Body *b, char *name);
void BodyUpdateCoordinatesDate(Body *b, char *date);
void BodyUpdateCoordinatesEphemerisTime(Body *b, double ephemeris_time);

void BodyPrint(Body b);

#endif
