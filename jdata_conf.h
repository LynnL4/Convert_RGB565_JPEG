/**
  ******************************************************************************
  * @file    LibJPEG/LibJPEG_Encoding/Inc/jdata_conf.h
  * @author  MCD Application Team
  * @brief    this file contains the libJPEG abstruction defines for the memory
  *          management routines and IO File operations
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/* Private typedef -----------------------------------------------------------*/  
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

typedef struct{
   uint8_t * buffer;
   uint32_t index;
}jfile_t;

#define JFILE            jfile_t

#define JMALLOC   malloc    
#define JFREE     free  

size_t read_file (JFILE  *file, uint8_t *buf, uint32_t sizeofbuf);
size_t write_file (JFILE  *file, uint8_t *buf, uint32_t sizeofbuf);

#define JFREAD(file,buf,sizeofbuf)  \
   read_file (file,buf,sizeofbuf)

#define JFWRITE(file,buf,sizeofbuf)  \
   write_file (file,buf,sizeofbuf)

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
