
#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_Intrface.h"

void MGIE_voidEnable()
{
	SET_BIT(SREG,7);
}

void MGIE_voidDisable()
{
	CLR_BIT(SREG,7);
}
