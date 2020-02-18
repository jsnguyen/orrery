#include "orrery/solarSystem.h"

void SolarSystemInitialize(SolarSystem *ss, double ephemeris_time){
  BodySetName(&ss->sun, "SUN");
  BodySetName(&ss->planets[0], "MERCURY_BARYCENTER");
  BodySetName(&ss->planets[1], "VENUS_BARYCENTER");
  BodySetName(&ss->planets[2], "EARTH_BARYCENTER");
  BodySetName(&ss->planets[3], "MARS_BARYCENTER");
  BodySetName(&ss->planets[4], "JUPITER_BARYCENTER");
  BodySetName(&ss->planets[5], "SATURN_BARYCENTER");
  BodySetName(&ss->planets[6], "URANUS_BARYCENTER");
  BodySetName(&ss->planets[7], "NEPTUNE_BARYCENTER");

  SolarSystemUpdateCoordinates(ss, ephemeris_time);

}

void SolarSystemUpdateCoordinates(SolarSystem *ss, double ephemeris_time){
  BodyUpdateCoordinatesEphemerisTime(&ss->sun,ephemeris_time);
  for(int i=0;i<N_PLANETS_SOLAR_SYSTEM;i++){
    BodyUpdateCoordinatesEphemerisTime(&ss->planets[i],ephemeris_time);
  }
}

void SolarSystemPrint(SolarSystem ss){
  BodyPrint(ss.sun);
  for(int i=0;i<N_PLANETS_SOLAR_SYSTEM;i++){
    BodyPrint(ss.planets[i]);
  }
}
