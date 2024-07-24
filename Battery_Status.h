#ifndef BATTERY_STATUS_H
#define BATTERY_STATUS_H

typedef enum
{
  NORMAL_SOC_STATUS,
  APPROACH_CHARGE,
  APPROACH_DISCHARGE,
  OUT_OF_RANGE_SOC
}BattStatus_SoC_Chk_t;

typedef enum
{
  NORMAL_TEMP_STATUS,
  OUT_OF_RANGE_TEMP
}BattStatus_Temp_Chk_t;

typedef enum
{
  NORMAL_CHARGERATE,
  OUT_OF_RANGE_CHARGERATE
}BattStatus_ChargeRate_Chk_t;

BattStatus_SoC_Chk_t socIsOk(float soc);
BattStatus_Temp_Chk_t TemperatureIsOk(float temperature);
BattStatus_ChargeRate_Chk_t chargeRateIsOk(float chargeRate);


#endif /*BATTERY_STATUS_H */
