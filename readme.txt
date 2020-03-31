/**
  @page STemWin_HelloWorld Readme file
 
  @verbatim
  ******************************************************************************
  * @file    STemWin/STemWin_HelloWorld/readme.txt 
  * @author  MCD Application Team
  * @brief   
  ******************************************************************************
  *
  * Copyright (c) 2016 STMicroelectronics International N.V. All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
   @endverbatim

@par Application Description

This directory contains a set of source files that implement a simple "Hello
World" application based on STemWin for STM32F746xx devices.

The application allows also to run the different Segger samples that can be
downloaded from here:
http://www.segger.com/emwin-samples.html
To do this, user has only to replace the file "Basic_HelloWorld.c" into the
project workspace by the downloaded one.

Note that the following user files may need to be updated:
  LCDConf.c
  GUIConf.c
(if for example more GUI allocated memory is needed)

LED1 is toggling continuously as a background task to indicate that the application is running successfully.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@note The STM32F7xx devices can reach a maximum clock frequency of 216MHz but as this application uses SDRAM,
      the system clock is limited to 200MHz. Indeed proper functioning of the SDRAM is only guaranteed 
      at a maximum system clock frequency of 200MHz.
      

@par Keywords

Middleware, Display, STemWin, HelloWorld, LCD, GUI

@Note�If the user code size exceeds the DTCM-RAM size or starts from internal cacheable memories (SRAM1 and SRAM2),that is shared between several processors,
 �����then it is highly recommended to enable the CPU cache and maintain its coherence at application level.
      In case of constraints it is possible to configure the MPU as "Write through/not shareable" to guarantee the cache coherence at write access but the user
	  has to ensure the cache maintenance at read access though.
������The address and the size of cacheable buffers (shared between CPU and other masters)  must be properly updated to be aligned to cache line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence, but depending on the use case
����� It is also possible to configure the MPU as "Write through", to guarantee the write access coherence.
������In that case, the MPU must be configured as Cacheable/Bufferable/Not Shareable.
������Even though the user must manage the cache coherence for read accesses.
������Please refer to the AN4838 �Managing memory protection unit (MPU) in STM32 MCUs�
������Please refer to the AN4839 �Level 1 cache on STM32F7 Series�

@par Directory contents 

  - STemWin/STemWin_HelloWorld/Core/Inc/GUIConf.h                        Header for GUIConf.c
  - STemWin/STemWin_HelloWorld/STemWin/Target/LCDConf.h                  Header for LCDConf*.c
  - STemWin/STemWin_HelloWorld/Core/Inc/main.h                           Main program header file
  - STemWin/STemWin_HelloWorld/Core/Inc/stm32f7xx_hal_conf.h             Library Configuration file
  - STemWin/STemWin_HelloWorld/Core/Inc/stm32f7xx_it.h                   Interrupt handlers header file
  - STemWin/STemWin_HelloWorld/STemWin/App/BASIC_HelloWorld.c            Simple demo drawing "Hello world"
  - STemWin/STemWin_HelloWorld/STemWin/Target/GUIConf.c                  Display controller initialization
  - STemWin/STemWin_HelloWorld/STemWin/Target/LCDConf.c                  Configuration file for the GUI library
  - STemWin/STemWin_HelloWorld/Core/Src/main.c                           Main program file
  - STemWin/STemWin_HelloWorld/Core/Src/stm32f7xx_it.c                   STM32F7xx Interrupt handlers
  - STemWin/STemWin_HelloWorld/Core/Src/system_stm32f7xx.c               STM32F7xx system file
 
 
@par Hardware and Software environment  

  - This application runs on STM32F746xx devices.
    
  - This application has been tested with STMicroelectronics STM32746G-DISCOVERY
    boards RevB and can be easily tailored to any other supported device and 
    development board.


@par How to use it ? 

In order to make the program work, you must do the following :
  - Open your preferred toolchain 
  - Rebuild all files and load your image into target memory
  - Run the application
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
