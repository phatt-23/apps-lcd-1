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

#include <opencv2/opencv.hpp>

#include "lcd_lib.h"

// LCD Simulator

// Virtual LCD
cv::Mat g_canvas( cv::Size( LCD_WIDTH, LCD_HEIGHT ), CV_8UC3 );


// Put color pixel on LCD (canvas)
void lcd_put_pixel( int32_t t_x, int32_t t_y, uint16_t t_rgb_565 )
{
    // Transform the color from a LCD form into the OpenCV form. 
    cv::Vec3b l_rgb_888( 
            (  t_rgb_565         & 0x1F ) << 3, 
            (( t_rgb_565 >> 5 )  & 0x3F ) << 2, 
            (( t_rgb_565 >> 11 ) & 0x1F ) << 3
            );
    g_canvas.at<cv::Vec3b>( t_y, t_x ) = l_rgb_888; // put pixel
}


// LCD Initialization 
void lcd_init()
{
    cv::namedWindow( LCD_NAME, 0 );
    cv::Vec3b l_black( 0, 0, 0 );
    g_canvas.setTo( l_black );

    cv::waitKey( 1 );
}


