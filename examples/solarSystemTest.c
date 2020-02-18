#include <stdio.h>
#include "orrery/solarSystem.h"

int main(){
  CSPICELoadMetaKernel("/home/jsnguyen/repos/orrery/meta.ker");

  SolarSystem ss;

  SolarSystemInitialize(&ss, 0);
  SolarSystemPrint(ss);

  SolarSystemUpdateCoordinates(&ss,100);
  SolarSystemPrint(ss);

  return 0;
}
