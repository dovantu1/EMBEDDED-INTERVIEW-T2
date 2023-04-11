//i2c Slave Code(Nano)
#include <Wire.h>
#define i2cAdress 0x06
#define ledTestI2C 13
#define ledOff 0
#define ledOn 1
uint8_t charr='H';
void setup()
{
  Wire.begin(i2cAdress); // Khởi tạo thư viện i2c địa chỉ 6
  Wire.onReceive(receiveEvent); // khởi tạo chế độ nhận tín hiệu từ boad chủ
  Wire.onRequest(requestEvent);
  pinMode(ledTestI2C,OUTPUT);
  digitalWrite(ledTestI2C,ledOff);
}
 
void loop()
{
  ;
}

// sự kiện nhận dữ liệu từ thiết bị Slave
void receiveEvent(int hoeMny) // hàm sự kiện nhận tín hiệu từ boad chủ
{
  while(Wire.available()) // chờ cho đến khi có tín hiệu
  {
    char c = Wire.read(); // biến c để lưu dữ liệu nhận được
    
    if(c == 'H') // nếu boad chủ gửi về tín hiệu là H
    {
      digitalWrite(13,ledOn); // chân 13 ở mức High
    }
    else if(c == 'L') // nếu tín hiệu boad chủ gửi về là L
    {
      digitalWrite(13,ledOff);// chân 13 ở mức Low
    }
  }
}

// sự kiện truyền tới thiết bị Master
void requestEvent()
{
  if(charr=='H')
  {

      Wire.write('L');
      charr='L';
  }
  else 
  {
      Wire.write('H');
      charr='H';
  }
}