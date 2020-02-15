#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <stdio.h>
#include <math.h>

#include "orrery/threeVector.h"

typedef struct{
  ThreeVector pos,vel,acc,ang_mom;
} Spaceship;

#endif
