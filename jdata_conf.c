/**
  ******************************************************************************
  * @file    LibJPEG/LibJPEG_Encoding/Src/jdata_conf.c
  * @author  MCD Application Team
  * @brief   this file contains the libJPEG abstruction defines for the memory
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
#include "jdata_conf.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private uint8_tiables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

size_t read_file(JFILE *file, uint8_t *buf, uint32_t sizeofbuf)
{
    uint8_t *p_file = file->buffer + file->index;
    for (int i = 0; i < sizeofbuf / 3; i++)
    {
        uint8_t byte_h = p_file[(2 * i) + 1];
        uint8_t byte_l = p_file[2 * i];

        uint8_t rr = byte_h & 0xf8;
        uint8_t gg = ((byte_h << 5) & 0xff) | ((byte_l & 0xe0) >> 3);
        uint8_t bb = (byte_l << 3) & 0xff;

        //reparation
        rr = rr | ((rr & 0x38) >> 3);
        gg = gg | ((gg & 0x0c) >> 2);
        bb = bb | ((bb & 0x38) >> 3);

        buf[3 * i + 0] = rr;
        buf[3 * i + 1] = gg;
        buf[3 * i + 2] = bb;
    }
    return sizeofbuf;
}

size_t write_file(JFILE *file, uint8_t *buf, uint32_t sizeofbuf)
{
    memcpy(file->buffer + file->index, buf, sizeofbuf);
    file->index += sizeofbuf;
    return sizeofbuf;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
