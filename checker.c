#include <stdio.h>
#include <assert.h>


int TemperatureIsOk(float temperature)
{
    if(temperature < 0 || temperature > 45)
    {
        return 0;
    }
    return 1;
    
}

int  socIsOk(float soc)
{
    if(soc < 20 || soc > 80) 
    {
        return 0;
    }
    return 1;
    
}
int chargeRateIsOk(float chargeRate)
{
    if(chargeRate > 0.8)
    {
        return 0;
    }
    return 1;
    
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
    int x,y,z;
    x=TemperatureIsOk(temperature);
    y=socIsOk(soc);
    z=chargeRateIsOk(chargeRate);
    if (x==0) {
    printf("Temperature out of range!\n");
  }
  if (y==0) {
    printf("State of Charge out of range!\n");
  }
  if (z==0) {
    printf("Charge Rate out of range!\n");
  }
  
  return x && y && z;
   }


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
