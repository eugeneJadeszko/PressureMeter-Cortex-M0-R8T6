#include "gpio.h"
#include "Timer.h"
#include "hd44780.h"
#include "display.h"
#include "buttons.h"
#include "adc.h"
#include "status.h"
#include "calc.h"

int main(void) {
	GPIOInit();
	Tim17_pwm_init();
	TIM2_Init();
	DisplayInit();
//	AdcInit();
//	CalcInit();
//	TIM3_Init();

	while (1) {
		Display();
	}
}

//void TIM3_IRQHandler(void) {
//	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) {
//		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
//		GPIOC->ODR ^= LED_GREEN_PC9; //toggling
//		ShowBatteryStatus();
//	}
//}

void TIM2_IRQHandler(void) {
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		buttonUser();
	}
}