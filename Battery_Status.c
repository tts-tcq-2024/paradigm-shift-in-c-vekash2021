#include <stdio.h>
#include <stdbool.h>
#include "Battery_Status.h"

ParameterConfig SoC = {20, 80, 0.05, true};
ParameterConfig Temperature = {0, 45, 0.05, true};
ParameterConfig Charge_rate = {0, 0.8, 0.05, true};

int check_low_limit(float value, ParameterConfig config) {
    return (value < config.min) ? 3 : 0;
}

 
int check_high_limit(float value, ParameterConfig config) {
    return (value > config.max) ? 4 : 0;
}


int check_warning(float value, ParameterConfig config) {
    
    float warning_min = config.min + (config.max * config.warning_tolerance);
    float warning_max = config.max - (config.max * config.warning_tolerance);
    if (value < warning_min) {
        return 1;  // Warning: Approaching discharge
    }
    if (value > warning_max) {
        return 2;  // Warning: Approaching charge-peak
    }
    return 0;  // Default to "Normal"
}

int get_message_index(float value, ParameterConfig config) {
    int message_index = 0;
    message_index = check_low_limit(value, config);
    if (message_index != 0) {
        return message_index;
    }
    message_index = check_high_limit(value, config);
    if (message_index != 0) {
        return message_index;
    }
    return check_warning(value, config);
}

void check_parameter(const char* param_name, float value, ParameterConfig config) {
    int message_index = get_message_index(value, config);
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
