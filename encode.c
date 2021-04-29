/**
  ******************************************************************************
  * @file    LibJPEG/LibJPEG_Encoding/Src/encode.c
  * @author  MCD Application Team
  * @brief   This file contain the compress method.
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
#include "encode.h"

/* Private typedef -----------------------------------------------------------*/
   /* This struct contains the JPEG compression parameters */
   static struct jpeg_compress_struct cinfo; 
   /* This struct represents a JPEG error handler */
   static struct jpeg_error_mgr jerr; 
  
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Jpeg Encode
  * @param  file:          pointer to the bmp file
  * @param  file1:         pointer to the jpg file  
  * @param  width:         image width
  * @param  height:        image height
  * @param  image_quality: image quality
  * @param  buff:          pointer to the image line
  * @retval None
  */
void jpeg_encode(JFILE *file, JFILE *file1, uint32_t width, uint32_t height, uint32_t image_quality, uint8_t * buff)
{

  /* Encode BMP Image to JPEG */  
  JSAMPROW row_pointer;    /* Pointer to a single row */
  uint32_t bytesread;

  file->index = 0;
  file1->index = 0;
  
  /* Step 1: allocate and initialize JPEG compression object */
  /* Set up the error handler */

  cinfo.err = jpeg_std_error(&jerr);
  
  /* Initialize the JPEG compression object */  
  jpeg_create_compress(&cinfo);
  
  /* Step 2: specify data destination */

  jpeg_stdio_dest(&cinfo, file1);
  
  /* Step 3: set parameters for compression */
  cinfo.image_width = width;
  cinfo.image_height = height;
  cinfo.input_components = 3;
  cinfo.in_color_space = JCS_RGB;
  
  /* Set default compression parameters */

  jpeg_set_defaults(&cinfo);
  
  cinfo.dct_method  = JDCT_FLOAT;    
  
  jpeg_set_quality(&cinfo, image_quality, TRUE);
  
  /* Step 4: start compressor */
  jpeg_start_compress(&cinfo, TRUE);

 /* Get bitmap data address offset */

  while (cinfo.next_scanline < cinfo.image_height)
  {          
    /* In this application, the input file is a BMP, which first encodes the bottom of the picture */
    /* JPEG encodes the highest part of the picture first. We need to read the lines upside down   */
    /* Move the read pointer to 'last line of the picture - next_scanline'    */
    file->index = (cinfo.next_scanline*width*2);
    if(JFREAD(file, buff, width*3) == width*3)
    {
      row_pointer = (JSAMPROW)buff;
      jpeg_write_scanlines(&cinfo, &row_pointer, 1);          
    }
  }
  /* Step 5: finish compression */
  jpeg_finish_compress(&cinfo);
  
  /* Step 6: release JPEG compression object */
  jpeg_destroy_compress(&cinfo);
    
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
