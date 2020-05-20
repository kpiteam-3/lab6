#include "STM32F10x.h"
#include <cmsis_os.h>
#include "STM32F10x_gpio.h"
#include "STM32F10x_rcc.h"

void delay (unsigned int count)
{
unsigned int index;

	for(index =0;index<count;index++)
	{;}
	
}

void led_thread1 (void const *argument) // Flash LED 1
{
	for (;;){GPIO_SetBits(GPIOA, (GPIO_Pin_0 )); }                       
}

void led_thread2 (void const *argument) // Flash LED 2

{
	for (;;) 	{   GPIO_SetBits(GPIOA, (GPIO_Pin_1  ));  }                      
}

void led_thread3 (void const *argument) // Flash LED 2
{
	for (;;) 	{   GPIO_SetBits(GPIOA, (GPIO_Pin_2)); }                       
	}

osThreadId main_ID,led_ID1,led_ID2,led_ID3 ;	
osThreadDef(led_thread2, osPriorityNormal, 1, 0);
osThreadDef(led_thread1, osPriorityNormal, 1, 0);
osThreadDef(led_thread3, osPriorityNormal, 1, 0);

int main (void) 
{
    GPIO_InitTypeDef   LAB_2_GPIO_A; 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  	GPIO_StructInit(&LAB_2_GPIO_A);
            LAB_2_GPIO_A.GPIO_Pin =
            GPIO_Pin_0 |
            GPIO_Pin_1 |
            GPIO_Pin_2 |
            GPIO_Pin_3 |
            GPIO_Pin_4 |
            GPIO_Pin_5 |
            GPIO_Pin_6 |
            GPIO_Pin_7;
	
		LAB_2_GPIO_A.GPIO_Mode = GPIO_Mode_Out_PP;
          LAB_2_GPIO_A.GPIO_Speed = GPIO_Speed_50MHz;
          GPIO_Init(GPIOA, &LAB_2_GPIO_A);
              osKernelInitialize ();  
	// initialize CMSIS-RTOS
	led_ID2 = osThreadCreate(osThread(led_thread2), NULL);
	led_ID1 = osThreadCreate(osThread(led_thread1), NULL);
              led_ID3 = osThreadCreate(osThread(led_thread3), NULL);
	osKernelStart ();
	while(1)
	{;}
} 
