#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include"Switch_interface.h"
#include"Switch_config.h"

u8 GetSwitchStatus(u8 SWITCH_NUM) {
	u8 result = 0;
	if (SWITCH_NUM == 0) {
		result = GetPinValue(Switch_Port, Switch_Pin);
#if Switch_Mode == 0
		return result;
#else
		return result ^ 0x01;

#endif
	}

	/*it's better to make this using #if than do just if condition because
	 the switch mode will never change its value during runtime	*/

	if (SWITCH_NUM == 1) {
		result = GetPinValue(Switch_Port_1, Switch_Pin_1);
#if Switch_Mode == 0
		return result;
#else
		return result ^ 0x01;

#endif
	}
return 0;
}

