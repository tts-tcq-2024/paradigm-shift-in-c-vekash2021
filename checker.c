
#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  int x = (temperature >= 0 && temperature <= 45);
  int y = (soc >= 20 && soc <= 80);
  int z = (chargeRate <= 0.8);

  if (!x) {
    printf("Temperature out of range!\n");
  }
  if (!y) {
    printf("State of Charge out of range!\n");
  }
  if (!z) {
    printf("Charge Rate out of range!\n");
  }

  return x && y && z;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
