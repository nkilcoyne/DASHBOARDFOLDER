#include "main.h"

uint8_t GUI_Initialized = 0;
TIM_HandleTypeDef TimHandle;
CAN_HandleTypeDef     CanHandle;
CAN_TxHeaderTypeDef   TxHeader;
CAN_RxHeaderTypeDef   RxHeader;
uint8_t               TxData[8];
uint8_t               RxData[8];
uint32_t              TxMailbox;
uint32_t uwPrescalerValue = 0;

uint16_t T1,T2,B1,B2,DIR1,DIR2,SUSP1,SUSP2;
uint16_t SOC,VPack,Vcellmax,Vcellmin,Tcellmax,Tcellmin;

#include "WM.h"
#include "funcions.c"

extern void MainTask(void);
static void CPU_CACHE_Enable(void);

int main(void){
  
  CPU_CACHE_Enable();

  HAL_Init();  
  
  SystemClock_Config();
  
  HAL_CAN_MspIniut();
  
  BSP_SDRAM_Init();
  __HAL_RCC_CRC_CLK_ENABLE();
  GUI_Init();
  
  GUI_DispStringAt("Starting...", 0, 0);
  GUI_Initialized = 1;
  
  TIMER2_Config();
  
  TxHeader.StdId = 0x321;
  TxHeader.DLC = 2;
  TxData[0] = 0x12;
  TxData[1] = 0xA4;
        
  /* Start the Transmission process */
  HAL_CAN_AddTxMessage(&CanHandle, &TxHeader, TxData, &TxMailbox);
  
  WM_SetCreateFlags(WM_CF_MEMDEV);
    
  MainTask();

  for(;;);
}