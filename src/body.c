#include "orrery/body.h"

#define MAXSPICEOBJ 1000

void CopyString(char *dest, char *source, int dest_size){
  if (dest_size > 0){
      dest[0] = '\0';
      strncat(dest, source, dest_size - 1);
  } 
}

void CSPICELoadMetaKernel(char *filename){
  furnsh_c(filename);
}

void BodySetName(Body *b, char *name){
  CopyString(b->name,name,64);
}

void BodyUpdateCoordinatesDate(Body *b, char *date){
  SpiceDouble ephemeris_time; // aka et
  SpiceDouble light_time;

  str2et_c(date,&ephemeris_time);
  b->time = ephemeris_time;

  double coords[3];
  spkpos_c(b->name,
           ephemeris_time,
           "J2000",
           "NONE",
           "Solar System Barycenter",
           coords,
           &light_time);
  ThreeVectorSetArray(b->pos,coords);
}

void BodyUpdateCoordinatesEphemerisTime(Body *b, double ephemeris_time){
  SpiceDouble light_time;

  b->time = ephemeris_time;

  double coords[3];
  spkpos_c(b->name,
           ephemeris_time,
           "J2000",
           "NONE",
           "Solar System Barycenter",
           coords,
           &light_time);
  ThreeVectorSetArray(b->pos,coords);
}

void BodyPrint(Body b){
  printf("Name: %s\n",b.name);
  printf("Time: %f\n",b.time);
  printf("Position: ");
  ThreeVectorPrint(b.pos);
}
