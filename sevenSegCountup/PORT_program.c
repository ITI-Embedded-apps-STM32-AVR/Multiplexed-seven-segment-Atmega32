#include "STD_TYPES.h"
#include "BIT_math.h"
#include"PORT_interface.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_register.h"
void PortInit(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	
	PORTA=PORTA_INTIALVALUE;
	PORTB=PORTB_INTIALVALUE;
	PORTC=PORTC_INTIALVALUE;
	PORTD=PORTD_INTIALVALUE;
}