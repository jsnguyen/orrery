#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  Body planets[8];
  double time; // ephemeris time
} SolarSystem;


SolarSystem* SolarSystemCreate();
void SolarSystemDestroy();

#endif
