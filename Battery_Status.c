#include <stdio.h>
#include <assert.h>
#include "Battery_Status.h"

BattStatus_SoC_Chk_t socIsOk(float soc)
{
	BattStatus_SoC_Chk_t  SoC_status_t; 
	if (soc < 20 || soc > 80)
	{
		SoC_status_t = OUT_OF_RANGE_SOC;
	}
	else if(soc==24)
	{
		SoC_status_t = APPROACH_DISCHARGE;
	}
	else if(soc==76)
	{
		SoC_status_t = APPROACH_CHARGE;
	}
	else
	{
		SoC_status_t = NORMAL_SOC_STATUS;
	}

 return SoC_status_t;
}

BattStatus_Temp_Chk_t TemperatureIsOk(float temperature )
{
	BattStatus_Temp_Chk_t Temp_status_t;
	Temp_status_t = OUT_OF_RANGE_TEMP;
	
	if(0<=temperature<=45)
    {
      Temp_status_t = NORMAL_TEMP_STATUS;
    }
    
	
    return Temp_status_t;
    
}

BattStatus_ChargeRate_Chk_t chargeRateIsOk(float chargeRate)
{
	BattStatus_ChargeRate_Chk_t ChargeRatestatus_t;
	ChargeRatestatus_t =  OUT_OF_RANGE_CHARGERATE;
	if(0.1 <= chargeRate <=0.8)
    {
        ChargeRatestatus_t = NORMAL_CHARGERATE;
    }
    return ChargeRatestatus_t;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
	BattStatus_Temp_Chk_t Temp_status_t=TemperatureIsOk(temperature);
	BattStatus_SoC_Chk_t  SoC_status_t=socIsOk(soc);
	BattStatus_ChargeRate_Chk_t ChargeRatestatus_t=chargeRateIsOk(chargeRate);
	
	return Temp_status_t&&SoC_status_t&&ChargeRatestatus_t;
}


int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    
    return 0;
}
