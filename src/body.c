#include "orrery/body.h"

#define MAXSPICEOBJ 1000

void LoadMetaKernel(char *filename){
  furnsh_c(filename);
}

void GetBodyCoordinates(char *date, char *body, double coords[3]){
  SpiceDouble ephemeris_time; // aka et
  SpiceDouble light_time;

  str2et_c(date,&ephemeris_time);

  spkpos_c(body,
           ephemeris_time,
           "J2000",
           "NONE",
           "Solar System Barycenter",
           coords,
           &light_time);

}
