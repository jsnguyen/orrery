#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "orrery/body.h"

#define N_PLANETS_SOLAR_SYSTEM 8

typedef struct{
  Body sun;
  Body planets[N_PLANETS_SOLAR_SYSTEM];
  double time; // ephemeris time
} SolarSystem;

void SolarSystemInitialize(SolarSystem *ss, double ephemeris_time);
void SolarSystemUpdateCoordinates(SolarSystem *ss, double ephemeris_time);

void SolarSystemPrint(SolarSystem ss);
#endif
