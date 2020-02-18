#include <stdio.h>
#include "orrery/body.h"

int main(){
  CSPICELoadMetaKernel("/home/jsnguyen/repos/orrery/meta.ker");

  Body earth;
  BodySetName(&earth, "EARTH");

  char date1[]="2000-01-01T00:00:00";
  BodyUpdateCoordinatesDate(&earth,date1);
  BodyPrint(earth);

  char date2[]="2000-01-02T00:00:00";
  BodyUpdateCoordinatesDate(&earth,date2);
  BodyPrint(earth);

  return 0;
}
