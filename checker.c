#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45 || soc < 20 || soc > 80 || chargeRate > 0.8) {
    printf("Temperature out of range!\n");
    return 0;
  }
  return 1;

}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
