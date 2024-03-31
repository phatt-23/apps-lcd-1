#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>

#include "graph_class.hpp"

int main()
{
	lcd_init();				// LCD initialization

    Pixel p1({100, 50}, {255, 255, 255}, {255, 255, 255});
    p1.draw();
    
    for(uint8_t i = 0; i < 100; ++i) {
        p1.m_pos = {i, i};
        p1.m_fg_color = {i, i, i};
        p1.draw();
    }

    Circle circle1 { {150, 150}, {100}, {255, 255, 255}, {0, 0, 0} };    
    circle1.draw();

    Line line1 { {50, 50}, {70, 80}, {255, 255, 255}, {255, 255, 255} };
    line1.draw();

    Character char1 { {90, 20}, '%', {0, 255, 0}, {0, 0, 0} };
    char1.draw(32,53);

    Character char2 { {130, 20}, '$', {0, 255, 255}, {0, 0, 0} };
    char2.draw(32,53);

    Character char3 { {120, 90}, '?', {0, 255, 100}, {0, 0, 0} };
    char3.draw(32,53);

    String string1 { {10, 10}, 
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Etiam sapien elit, consequat eget, tristique non, venenatis quis, ante. Sed ac dolor sit amet purus malesuada congue. Pellentesque pretium lectus id turpis. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos hymenaeos. Nunc tincidunt ante vitae massa.", 
        {255, 255, 0}, {0, 0, 0} 
    };
    string1.draw(8,12);

    
    DONT_DIE;                 
	return 0;
}