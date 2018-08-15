
#include "dotstar.h"
#include <SPI.h>

/*
 * Initialise Dot star leds
 */
DotStar::DotStar(uint8_t num_of_leds, uint8_t color_mode)
{
	this->TotalLeds = num_of_leds;
  this->colorMode = color_mode;
}


/*
 * 
 */
DotStar::~DotStar()
{

}

void DotStar::begin(){
	data_buf=new uint8_t[(this->TotalLeds)*3];
  SPI.begin(14,-1,16,-1);
}

int8_t DotStar::setColor(uint8_t led_index,uint8_t r,uint8_t g,uint8_t b){
  if(led_index>this->TotalLeds) return -1;
    uint8_t v0, v1, v2;
    if (this->colorMode == DOTSTAR_RGB) {
      v0 = r; v1 = g; v2 = b;
    } else if (this->colorMode == DOTSTAR_GRB) {
      v0 = g; v1 = r; v2 = b;
    } else if (this->colorMode == DOTSTAR_BGR) {
      v0 = b; v1 = g; v2 = r;
    } 
    this->data_buf[led_index * 3] = v0;
    this->data_buf[(led_index * 3) + 1] = v1;
    this->data_buf[(led_index * 3) + 2] = v2;
    
    return 0;
}

void DotStar::print(){
  uint8_t *tempBuf = new uint8_t(4);
  for(uint8_t i =0;i<this->TotalLeds;i+=3){
    tempBuf[0] = 0;
    tempBuf[1] = 0;
    tempBuf[2] = 0;
    tempBuf[3] = 0;
  }
  //SPI transfer
  SPI.beginTransaction(SPISettings(8000000, 1, SPI_MODE0));
  SPI.transferBytes(tempBuf,NULL,4);
  for(uint8_t i =0;i<(this->TotalLeds*3);i+=3){
    tempBuf[0] = 255;
    tempBuf[1] = this->data_buf[i];
    tempBuf[2] = this->data_buf[i + 1];
    tempBuf[3] = this->data_buf[i + 2];
    
  //SPI transfer
  SPI.transferBytes(tempBuf,NULL,4);
  }
  for(uint8_t i =0;i<this->TotalLeds;i+=3){
    tempBuf[0] = 255;
    tempBuf[1] = 255;
    tempBuf[2] = 255;
    tempBuf[3] = 255;
  }
  SPI.transferBytes(tempBuf,NULL,4);
  SPI.endTransaction();
}