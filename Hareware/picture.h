#ifndef __PICTURE_H
#define __PICTURE_H

#include "stm32f10x.h"

const unsigned char game[]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x80,0x03,0xF0,0x03,0xE0,0x07,0x30,0xE6,0x7F,0x0C,
0x18,0xE4,0x3F,0x18,0x1C,0x00,0x00,0x18,0x0C,0x00,0x00,0x33,0x0C,0x00,0x80,0x37,0x84,0x01,0x80,0x37,0x86,0x01,0x00,0x63,0xE6,0x07,0x30,0x60,0xE6,0x07,0x78,0x60,
0x86,0x01,0x78,0x60,0x86,0x01,0x30,0x60,0x06,0x00,0x00,0x60,0x06,0xF8,0x1F,0x60,0x06,0xFC,0x3F,0x60,0x06,0x0C,0x30,0x60,0x0C,0x06,0x60,0x30,0x0C,0x06,0x60,0x30,
0x18,0x03,0xC0,0x18,0xF8,0x03,0x80,0x1F,0xE0,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\game.bmp",0*/
/* (32 X 32 )*/

};//��Ϸͼ��

const unsigned char wechat[] = 

{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x01,0x00,0xC0,0xFF,0x0F,0x00,0xF0,0x00,0x3C,0x00,0x38,0x00,0x70,0x00,
0x1C,0x00,0xE0,0x00,0x0E,0x00,0xC0,0x01,0x06,0x00,0x80,0x01,0x02,0x00,0x00,0x03,0x03,0x00,0x00,0x03,0x83,0x33,0x06,0x0A,0x83,0x33,0x06,0x33,0x03,0x00,0x00,0x33,
0x02,0x00,0x00,0x63,0x06,0x00,0x80,0x41,0x0C,0x00,0xC0,0x81,0x1C,0x00,0xE0,0x80,0x78,0x00,0x70,0x80,0xF8,0x01,0x3E,0x40,0xF8,0xFF,0x0F,0x60,0x18,0xFC,0x01,0x70,
0x04,0x00,0x00,0x38,0x00,0x00,0x07,0x3E,0x00,0x00,0xFC,0x3B,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\wechat.bmp",0*/
/* (32 X 32 )*/

};//΢��ͼ��(�Ͽ�)

const unsigned char setting[] = 
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x00,0x00,0x20,0x04,0x00,0x00,0x27,0xE4,0x00,0x80,0x3D,0xBC,0x01,
0xC0,0x10,0x08,0x03,0xC0,0x00,0x00,0x03,0x80,0x00,0x00,0x01,0x80,0x01,0x80,0x01,0x80,0xE1,0x87,0x01,0xF0,0x30,0x0C,0x0F,0x10,0x10,0x08,0x08,0x10,0x10,0x08,0x08,
0x10,0x10,0x08,0x08,0x10,0x10,0x08,0x08,0xF0,0x30,0x0C,0x0F,0x80,0xE0,0x87,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x03,0xC0,0x00,0x00,0x02,0xC0,0x00,0x00,0x03,
0x80,0x3D,0xBC,0x01,0x00,0x27,0xE4,0x00,0x00,0x20,0x04,0x00,0x00,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\setting.bmp",0*/
/* (32 X 32 )*/
};//����ͼ��

const unsigned char square[] = 

{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x01,0x00,0x00,
0x00,0x00,0xE0,0xFF,0xFF,0x0F,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0xFC,0x01,0x00,0x7F,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0xFC,0x01,0x00,
0x00,0x80,0x0F,0x00,0x00,0xE0,0x03,0x00,0x00,0xC0,0x07,0x00,0x00,0xC0,0x0F,0x00,0x00,0xE0,0x03,0x00,0x00,0x00,0x0F,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x1E,0x00,
0x00,0x78,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0xF8,0x01,
0x00,0x1E,0x00,0x00,0x00,0x00,0xF0,0x01,0x00,0x0E,0x00,0x00,0x00,0x00,0xE0,0x01,0x00,0x07,0x00,0x00,0x00,0x00,0xE0,0x01,0x00,0x07,0x00,0x00,0x00,0x00,0xC0,0x03,
0x00,0x07,0x00,0x00,0x00,0x00,0xC0,0x03,0x80,0x03,0x00,0x00,0x00,0x00,0xC0,0x03,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,
0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x07,
0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,
0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x80,0x03,0x80,0x03,0x00,0x00,0x00,0x00,0xC0,0x03,0x00,0x07,0x00,0x00,0x00,0x00,0xC0,0x03,
0x00,0x07,0x00,0x00,0x00,0x00,0xC0,0x03,0x00,0x06,0x00,0x00,0x00,0x00,0xE0,0x01,0x00,0x0E,0x00,0x00,0x00,0x00,0xF0,0x01,0x00,0x0C,0x00,0x00,0x00,0x00,0xF0,0x00,
0x00,0x1C,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x1F,0x00,
0x00,0x80,0x00,0x00,0x00,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0xC0,0x01,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x07,0x00,0x00,
0x00,0x00,0x00,0xF0,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\4.bmp",0*/
/* (64 X 64 )*/
};//ѡ���ͼ��

const unsigned char arrowhead[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,
0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0xFF,0x01,0x00,0x00,0x80,0xFF,0x01,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,
0x00,0x7C,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0xE0,
0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\9.bmp",0*/
/* (40 X 40 )*/

};//��ͷͼ��

const unsigned char dinosaur[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x1F,0x00,0x00,0xFC,0x3F,0x00,0x00,0xCC,0x3F,0x00,0x00,0xFC,0x3F,0x00,0x00,0xFC,0x3F,
0x00,0x00,0xFC,0x3F,0x00,0x00,0xFC,0x3F,0x00,0x00,0xFC,0x00,0x00,0x00,0xFC,0x0F,0x00,0x00,0xFC,0x0F,0x20,0x00,0x3F,0x00,0x20,0x80,0x3F,0x00,0x20,0xC0,0xFF,0x01,
0x60,0xF0,0xFF,0x01,0xE0,0xF8,0xBF,0x01,0xE0,0xFF,0x3F,0x00,0xE0,0xFF,0x3F,0x00,0xC0,0xFF,0x1F,0x00,0x80,0xFF,0x1F,0x00,0x00,0xFF,0x1F,0x00,0x00,0xFE,0x0F,0x00,
0x00,0xFC,0x07,0x00,0x00,0x78,0x07,0x00,0x00,0x78,0x06,0x00,0x00,0x38,0x06,0x00,0x00,0x18,0x06,0x00,0x00,0x38,0x0E,0x00,0x00,0x38,0x0E,0x00,0x00,0x00,0x00,0x00,
/*"C:\Users\chang\Desktop\picture\10.bmp",0*/

};

const unsigned char dinosaur_run_1[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x0F,0x00,0x00,0xFE,0x1F,0x00,0x00,0xE6,0x1F,0x00,0x00,0xFE,0x1F,0x00,0x00,0xFE,0x1F,0x00,0x00,0xFE,0x3F,
0x00,0x00,0xFE,0x3F,0x00,0x00,0xFE,0x00,0x00,0x00,0xFE,0x07,0x00,0x00,0xFE,0x07,0x08,0x80,0x3F,0x00,0x08,0xC0,0x1F,0x00,0x08,0xE0,0xFF,0x00,0x18,0xF8,0xFF,0x01,
0x38,0xFC,0xFF,0x01,0x78,0xFE,0xDF,0x00,0xF8,0xFF,0x1F,0x00,0xF8,0xFF,0x1F,0x00,0xF0,0xFF,0x0F,0x00,0xE0,0xFF,0x0F,0x00,0xC0,0xFF,0x07,0x00,0x80,0xFF,0x07,0x00,
0x00,0xFF,0x03,0x00,0x00,0xBE,0x03,0x00,0x00,0x9C,0x03,0x00,0x00,0x1E,0x03,0x00,0x00,0x0E,0x03,0x00,0x00,0x1E,0x02,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\1_RUN.bmp",0*/

};

const unsigned char dinosaur_run_2[] ={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x1F,0x00,0x00,0xFC,0x3F,0x00,0x00,0xEC,0x3F,0x00,0x00,0xEC,0x3F,0x00,0x00,0xFC,0x3F,0x00,0x00,0xFC,0x3F,
0x00,0x00,0xFC,0x7F,0x00,0x00,0xFC,0x3F,0x00,0x00,0xFC,0x03,0x00,0x00,0xFC,0x0F,0x00,0x00,0xFE,0x0F,0x00,0x00,0x3F,0x00,0x00,0x80,0x7F,0x00,0x20,0xE0,0xFF,0x03,
0x60,0xF0,0xFF,0x03,0xE0,0xF8,0xBF,0x03,0xE0,0xFF,0x3F,0x00,0xE0,0xFF,0x3F,0x00,0xC0,0xFF,0x1F,0x00,0x80,0xFF,0x1F,0x00,0x00,0xFF,0x1F,0x00,0x00,0xFE,0x0F,0x00,
0x00,0xFC,0x07,0x00,0x00,0x78,0x07,0x00,0x00,0x78,0x06,0x00,0x00,0x38,0x04,0x00,0x00,0x08,0x06,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
/*"C:\Users\chang\Desktop\picture\20.bmp",0*/

};

const unsigned char dinosaur_map[] = 
{
0x0C,0x00,0x80,0x01,0x00,0x18,0x00,0x00,0x03,0x00,0x20,0x00,0x00,0x06,0x00,0x40,0x0C,0x00,0x80,0x01,0x00,0x18,0x00,0x00,0x03,0x00,0x20,0x00,0x00,0x06,0x00,0x60,
0x0C,0x00,0x80,0x01,0x00,0x18,0x00,0x00,0x03,0x00,0x30,0x00,0x00,0x06,0x00,0x60,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
0x0C,0x84,0x80,0x81,0x10,0x18,0x10,0x02,0x03,0x21,0x20,0x20,0x04,0x06,0x42,0x60,0x0C,0xFF,0x87,0xE0,0x7F,0x18,0xFE,0x0F,0xC3,0xFF,0x21,0xFC,0x1F,0x86,0xFF,0x63,
0xFC,0x01,0xFC,0x1F,0xE0,0xFF,0x03,0xF8,0x7F,0x00,0xFF,0x07,0xF0,0xFF,0x00,0x7E,0x0C,0x01,0x84,0x10,0xC0,0x18,0x02,0x08,0x43,0x00,0x21,0x04,0x10,0x06,0x00,0x62,
0xFC,0x01,0xFC,0x1F,0x80,0xFF,0x03,0xF8,0x7F,0x00,0xFF,0x07,0xF0,0xFF,0x00,0x7E,0x0C,0xFF,0x87,0xF1,0xFF,0x18,0xFE,0x0F,0xC3,0xFF,0x21,0xFC,0x1F,0x86,0xFF,0x63,
0x0C,0x8C,0x81,0x80,0x10,0x18,0x10,0x02,0x03,0x63,0x20,0x20,0x04,0x06,0x42,0x60,0x0C,0x8C,0x81,0x81,0x10,0x18,0x10,0x03,0x03,0x63,0x30,0x20,0x04,0x06,0xC6,0x60,
0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\chang\Desktop\picture\111.bmp",0*/

}
;

#endif