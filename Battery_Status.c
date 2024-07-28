#include <stdio.h>
#include <stdbool.h>
#include "Battery_Status.h"

ParameterConfig SoC = {20, 80, 0.05, true};
ParameterConfig Temperature = {0, 45, 0.05, true};
ParameterConfig Charge_rate = {0, 0.8, 0.05, true};

void check_parameter(const char* param_name, float value, ParameterConfig config) {
    float warning_min = config.min + (config.max * config.warning_tolerance);
    float warning_max = config.max - (config.max * config.warning_tolerance);

    int message_index = 0;  // Default to "Normal"

    if (value < config.min) {
        message_index = 3;  // Alarm: Low limit breached
    } else if (value > config.max) {
        message_index = 4;  // Alarm: High limit breached
    } else if (config.enable_warning) {
        if (value < warning_min) {
            message_index = 1;  // Warning: Approaching discharge
        } else if (value > warning_max) {
            message_index = 2;  // Warning: Approaching charge-peak
        }
    }

    printf("%s: %s\n", param_name, messages[language][message_index]);
}

int main() {
    // Example current values for parameters
    float current_SoC = 86;
    float current_Temperature = 43;
    float current_Charge_rate = 0.7;

    // Check each parameter
    printf("Checking parameters with current values:\n");
    
    check_parameter("SoC", current_SoC, SoC);
    check_parameter("Temperature", current_Temperature, Temperature);
    check_parameter("Charge_rate", current_Charge_rate, Charge_rate);

    return 0;
}
