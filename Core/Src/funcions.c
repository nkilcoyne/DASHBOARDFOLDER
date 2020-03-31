/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
void HAL_CAN_MspIniut(void);
void TIMER2_Config(void);

void HAL_CAN_MspIniut(void){
  
  GPIO_InitTypeDef   GPIO_InitStruct;
  CAN_FilterTypeDef  sFilterConfig;

  __HAL_RCC_CAN1_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
  
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Alternate = GPIO_AF9_CAN1 ;
  
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
  
  /*##-1- Configure the CAN peripheral #######################################*/
  CanHandle.Instance = CAN1;

  CanHandle.Init.TimeTriggeredMode = DISABLE;
  CanHandle.Init.AutoBusOff = DISABLE;
  CanHandle.Init.AutoWakeUp = DISABLE;
  CanHandle.Init.AutoRetransmission = DISABLE;
  CanHandle.Init.ReceiveFifoLocked = DISABLE;
  CanHandle.Init.TransmitFifoPriority = DISABLE;
  CanHandle.Init.Mode = CAN_MODE_NORMAL;
  CanHandle.Init.SyncJumpWidth = CAN_SJW_3TQ;
  CanHandle.Init.TimeSeg1 = CAN_BS1_12TQ;
  CanHandle.Init.TimeSeg2 = CAN_BS2_3TQ;
  CanHandle.Init.Prescaler = 3;

  if (HAL_CAN_Init(&CanHandle) != HAL_OK)
  {
  }

  /*##-2- Configure the CAN Filter ###########################################*/
  sFilterConfig.FilterBank = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;
  sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  sFilterConfig.FilterActivation = ENABLE;
  sFilterConfig.SlaveStartFilterBank = 14;

  if (HAL_CAN_ConfigFilter(&CanHandle, &sFilterConfig) != HAL_OK)
  {
  }

  /*##-3- Start the CAN peripheral ###########################################*/
  if (HAL_CAN_Start(&CanHandle) != HAL_OK)
  {
  }
  
  /*##-4- Activate CAN RX notification #######################################*/
  if (HAL_CAN_ActivateNotification(&CanHandle, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK){
  }

  /*##-5- Configure Transmission process #####################################*/
  TxHeader.StdId = 0x321;
  TxHeader.ExtId = 0x01;
  TxHeader.RTR = CAN_RTR_DATA;
  TxHeader.IDE = CAN_ID_STD;
  TxHeader.DLC = 2;
  TxHeader.TransmitGlobalTime = DISABLE;
}

static void SystemClock_Config(void){
  
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  //96MHz
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;

  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
}


static void CPU_CACHE_Enable(void){
  
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  
  HAL_CAN_AddTxMessage(&CanHandle, &TxHeader, TxData, &TxMailbox);

  GUI_SetFont(&GUI_Font10_1);
  GUI_DispDecAt(T1,375,150,5);
  GUI_DispDecAt(T2,375,160,5);
  GUI_DispDecAt(B1,375,170,5);
  GUI_DispDecAt(B2,375,180,5);
  GUI_DispDecAt(DIR1,375,190,5);
  GUI_DispDecAt(DIR2,375,200,5);
  GUI_DispDecAt(SUSP1,375,210,5);
  GUI_DispDecAt(SUSP2,375,220,5);
  
  GUI_SetFont(&GUI_Font16B_1);
  GUI_DispDecAt(VPack,410,20,3);
  GUI_DispDecAt(Vcellmax,410,35,3);
  GUI_DispDecAt(Vcellmin,410,50,3);
  GUI_DispDecAt(Tcellmax,410,65,2);
  GUI_DispDecAt(Tcellmin,410,80,2);
  
  GUI_SetFont(&GUI_Font32B_1);
  GUI_DispDecAt(SOC,115,180,2);
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
  
  /* Get RX message */
  if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK){
  }

  if(RxHeader.StdId == 0x25){
    T1=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x26){
    T2=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x27){
    B1=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x28){
    B2=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x35){
    DIR1=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x36){
    DIR2=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x37){
    SUSP1=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x38){
    SUSP2=RxData[1]*256+RxData[0];
  }
  
  else if(RxHeader.StdId == 0x213){
    Tcellmin=RxData[0];
    Tcellmax=RxData[1];
    Vcellmin=RxData[2];
    Vcellmax=RxData[3];
  }
}

void TIMER2_Config(void){
  
  __HAL_RCC_TIM2_CLK_ENABLE();


  HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
  
  TimHandle.Instance = TIM2;
  TimHandle.Init.Period            = 9600 - 1;
  TimHandle.Init.Prescaler         = 100-1;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;
  TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  
  if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK){
  }

  if (HAL_TIM_Base_Start_IT(&TimHandle) != HAL_OK){
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif