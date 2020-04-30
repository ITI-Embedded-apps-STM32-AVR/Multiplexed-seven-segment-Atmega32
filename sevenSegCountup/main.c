#include "STD_TYPES.h"
#include"DIO_interface.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "SevenSeg_interface.h"
#include "Switch_interface.h"
#include <avr/delay.h>
#define F_CPU 8000000
#define left_Switch 0
#define right_Switch 1
#define sevenleft 0
#define sevenright 1

void main() {
	PortInit();
	u8 switchnum1 = 1;
	u8 switchnum = 0;
	u8 i = 0;
	u8 j = 0;
	u16 count_delay = 0;
	u16 count_delay_fslow = 0;
	u8 isanybtnpress = 0;
	while (1) {

		if (count_delay_fslow == 0) {
			if (GetSwitchStatus(switchnum) == 1
					&& GetSwitchStatus(switchnum1) == 1) {
				isanybtnpress = 1;
				if (i == 0) {

					i = 9;
				} else {
					i--;
				}
				if (j == 0) {
					j = 9;
				} else {
					j--;
				}

			} else if (GetSwitchStatus(switchnum) == 1) {
				isanybtnpress = 1;
				i++;

				if (i > 9) {
					i = 0;
				}

				// to do delay

				/*SEVENSEG_Disable(sevenright);
				 SEVENSEG_Enable(sevenleft);

				 SEVENSEG_SetNumber(i);*/

			} else if (GetSwitchStatus(switchnum1) == 1) {
				isanybtnpress = 1;
				j++;
				if (j > 9) {
					j = 0;
				}
				/*SEVENSEG_Disable(sevenleft);
				 SEVENSEG_Enable(sevenright);

				 SEVENSEG_SetNumber(j);*/
			}

			else {
				isanybtnpress = 0;
			}

			if (isanybtnpress == 1) {
				if (count_delay >= 3000) {
					count_delay_fslow = 100;
				} else {
					count_delay_fslow = 500;
				}
			} else {

				count_delay = 0;
			}

		} else {
			count_delay_fslow -= 10;
		}

		SEVENSEG_Disable(sevenright);
		SEVENSEG_SetNumber(i);
		SEVENSEG_Enable(sevenleft);

		_delay_ms(5);
		SEVENSEG_Disable(sevenleft);
		SEVENSEG_SetNumber(j);
		SEVENSEG_Enable(sevenright);

		_delay_ms(5);
		count_delay += 10;
	}
}
