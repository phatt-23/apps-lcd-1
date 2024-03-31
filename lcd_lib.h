// **************************************************************************
//
//               Demo program for labs
//
// Subject:      Computer Architectures and Parallel systems
// Author:       Petr Olivka, petr.olivka@vsb.cz, 09/2019
// Organization: Department of Computer Science, FEECS,
//               VSB-Technical University of Ostrava, CZ
//
// File:         OpenCV simulator of LCD
//
// **************************************************************************
#ifndef __LCD_LIB_H
#define __LCD_LIB_H

#include <opencv2/opencv.hpp>

#define LCD_WIDTH       320
#define LCD_HEIGHT      240
#define LCD_NAME        "Virtual LCD"

// LCD Simulator

// Virtual LCD
extern cv::Mat g_canvas;

// Put color pixel on LCD (canvas)
void lcd_put_pixel( int32_t t_x, int32_t t_y, uint16_t t_rgb_565 );

// LCD Initialization 
void lcd_init();

#endif // __LCD_LIB_H

