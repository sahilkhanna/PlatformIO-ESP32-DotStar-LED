#ifndef DOTSTAR_H
#define DOTSTAR_H
#include <stdint.h>
enum COLOR_MODE{
    DOTSTAR_RGB=0,
    DOTSTAR_GRB,
    DOTSTAR_BGR,
};
class DotStar{
public:
    DotStar(uint8_t num_of_leds, uint8_t color_mode);
    ~DotStar();
    void begin();
    int8_t setColor(uint8_t led_index,uint8_t r,uint8_t g,uint8_t b);
    void print();
private:
    uint8_t TotalLeds;
    uint8_t colorMode;
    uint8_t *data_buf;
};
#endif