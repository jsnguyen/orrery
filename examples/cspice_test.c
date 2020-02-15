#include <stdio.h>
#include "orrery/body.h"

int main(){
  LoadMetaKernel("/home/jsnguyen/repos/orrery/meta.ker");
  double earth_coords[3];

  body_t SUN,MERCURY,VENUS,EARTH,MARS,JUPITER,SATURN,URANUS,NEPTUNE,PLUTO;
  body_t planets[9];

  planets[0]=SUN;
  planets[1]=MERCURY;
  planets[2]=VENUS;
  planets[3]=EARTH;
  planets[4]=MARS;
  planets[5]=JUPITER;
  planets[6]=SATURN;
  planets[7]=URANUS;
  planets[8]=NEPTUNE;
  planets[8]=PLUTO;

  GetBodyCoordinates("2000-01-01T00:00:00", "Earth", earth_coords);

  printf("x,y,z: %f,%f,%f\n",earth_coords[0],earth_coords[1],earth_coords[2]);
  return 0;
}
