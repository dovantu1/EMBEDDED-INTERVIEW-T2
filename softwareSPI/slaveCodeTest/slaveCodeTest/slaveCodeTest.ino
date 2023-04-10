/*
File: slaveSPItest
Author: Đỗ Văn Tú
Date: 7/4/2023
Description: chương trình test SPI cho slave thiết bị
*/
#include<SPI.h>
#define inputbutton 6
#define outputLED 7

/*input: 
buttonvalue: lưu giá trị của nút nhấn
x: biến trung gian lưu giá trị nút nhấn và truyền đi
received: lưu trạng thái hoạt động của ngăt,vector ngắt hoạt động biến nhận lên 1
Slavereceived: lưu dữ liệu nhận được từ master
Slavesend: lưu dữ liệu gửi đi từ slave
*/
volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;
int x;

/*
Fuction: setup
Description: chương trình khởi tạo cho thiết bị slave
*/
void setup()
{
    //khởi tạo giao tiếp nối tiếp bất đồng bộ với tốc độ baudrate 9600(baud/s)
    Serial.begin(9600);
    Serial.println("START!!!");
    // thiết lập chế độ hoạt động cho các chân SPI
    pinMode(inputbutton,INPUT); 
    pinMode(outputLED,OUTPUT);               
    pinMode(MISO,OUTPUT);                  
    SPCR |= _BV(SPE);                  
    received = false;
    SPI.attachInterrupt();                  
}

/*
Fuction: ISR
Input: số thứ tử của vector ngắt, ở đây là 17
Description: chương trình khởi tạo cho thiết bị slave
*/
ISR (SPI_STC_vect)                        
{
    Slavereceived = SPDR;    
    received = true;                        
}

/*
Fuction: loop
Description: hàm chạy chương trình chính
*/
//NOTE: giá trị gửi đi tuỳ thuộc vào 1 nút nhấn
void loop()
{  
    if(received)                           
    {
        if (Slavereceived==1) 
        {
            Serial.println("ledSlaveOn");
            digitalWrite(outputLED,HIGH);       
        }else
        {
            Serial.println("ledSlaveOff");
            digitalWrite(outputLED,LOW);          
        }
        buttonvalue = digitalRead(inputbutton);  
        if (buttonvalue == HIGH)           
        {
            x=1;
        }else
        {
            x=0;
        }
        Slavesend=x;     
        SPDR = Slavesend;                       
        delay(250);
    }
}