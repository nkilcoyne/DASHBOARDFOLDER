/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "main.h"
#include "stm32f7xx_it.h"
#include "GUI.h"

void TIM2_IRQHandler(void);
void CAN1_RX0_IRQHandler(void);

extern volatile GUI_TIMER_TIME OS_TimeMS;
extern LTDC_HandleTypeDef hltdc;
extern TIM_HandleTypeDef TimHandle;
extern CAN_HandleTypeDef CanHandle;

void NMI_Handler(void){
}

void HardFault_Handler(void){

  while (1)
  {
  }
}

void MemManage_Handler(void){

  while (1)
  {
  }
}

void BusFault_Handler(void){

  while (1)
  {
  }
}

void UsageFault_Handler(void){
  
  while (1)
  {
  }
}


void DebugMon_Handler(void){
}


void SysTick_Handler(void){
  
  HAL_IncTick();
  OS_TimeMS++;
}

void CAN1_RX0_IRQHandler(void){
  
  HAL_CAN_IRQHandler(&CanHandle);
  
}

void TIM2_IRQHandler(void){
  
  HAL_TIM_IRQHandler(&TimHandle);
}

void TIM3_IRQHandler(void){
  
  HAL_TIM_IRQHandler(&TimHandle);
}


void LTDC_IRQHandler(void){
  
  HAL_LTDC_IRQHandler(&hltdc);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
