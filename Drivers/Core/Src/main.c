/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Special_Functions.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "SysTick_interface.h"
#include "Led_Interface.h"
#include "Switch_Interface.h"
#include "Lcd_Interface.h"

void led (void)
{
	static u32 state=0;
	static u32 counter=0;
	if (counter%3000==0)
	{
		if (state==0)
		{
			GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , HIGH );
			state=1;
		}
		else if (state==1)
		{
			GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , LOW );
			state=0;
		}

	}

	counter++;
}

int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_APP2_IOPA_EN);
	RCC_voidEnableClock(RCC_APB2,RCC_APP2_IOPB_EN);
	STK_Init();
	LCD_voidInit();
	LCD_voidSendData('a');

  while (1)
  {

  }

}
