int get_message_index(float value, ParameterConfig config) {
    float warning_min = config.min + (config.max * config.warning_tolerance);
    float warning_max = config.max - (config.max * config.warning_tolerance);

    if (value < config.min) {
        return 3;  // Alarm: Low limit breached
    } else if (value > config.max) {
        return 4;  // Alarm: High limit breached
    } else if (config.enable_warning) {
        if (value < warning_min) {
            return 1;  // Warning: Approaching discharge
        } else if (value > warning_max) {
            return 2;  // Warning: Approaching charge-peak
        }
    }
    return 0;  // Default to "Normal"
}

void check_parameter(const char* param_name, float value, ParameterConfig config) {
    int message_index = get_message_index(value, config);
    printf("%s: %s\n", param_name, messages[language][message_index]);
}
