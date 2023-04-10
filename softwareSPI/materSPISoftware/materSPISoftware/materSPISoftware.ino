/*
File: masterSPISofware
Author: Đỗ Văn Tú
Date: 7/4/2023
Description: chương trình test software SPI cho master thiết bị
*/
#define SCK_Pin SCK    // chân SCK
#define MOSI_Pin MOSI  // Chân MOSI
#define SS_Pin SS      // Chân SS
#define MISO_Pin MISO  // chân MISO
#define LED 6
#define ipbutton 5

/*input: 
buttonvalue: lưu giá trị của nút nhấn
x: biến trung gian lưu giá trị nút nhấn và truyền đi
*/
int buttonvalue;
int x;

/*
Fuction: setup
Description: chương trình khởi tạo cho thiết bị master 
*/
void setup(void)
{
    //khởi tạo giao tiếp nối tiếp bất đồng bộ với tốc độ baudrate 9600(baud/s)
    Serial.begin(9600);        
    Serial.println("START!!!");
    // thiết lập chế độ hoạt động cho các chân SPI
    pinMode(SCK_Pin, OUTPUT);   
    pinMode(MOSI_Pin, OUTPUT);  
    pinMode(SS_Pin, OUTPUT);   
    pinMode(MISO_Pin, INPUT);  
    pinMode(ipbutton, INPUT);  
    pinMode(LED, OUTPUT);  
    digitalWrite(SS_Pin, LOW);  
}

/*
Fuction: wait
Input: 
        del: số lần thực hiện lệnh nop-asm
Description: chương trình chờ sử với lệnh nop-asm
*/
void wait(uint_fast8_t del) 
{
    for (uint_fast8_t i = 0; i < del; i++) {
        asm volatile("nop");
    }
}

/*
Fuction: transfer
Input: 
        val: dữ liệu để gửi đi
Output:
        byte: dữ liệu trả về 
Description: chương trình truyền và nhận sử dủng giao thức spi(software)
*/
byte transfer(byte val) 
{
    //out: biến trả về sau khi thực hiện hàm 
    byte out = 0;
    //v2: biến đảo giá trị của val ở chế độ MSB
    byte v2 = 
    ((val & 0x01) << 7) |
    ((val & 0x02) << 5) |
    ((val & 0x04) << 3) |
    ((val & 0x08) << 1) |
    ((val & 0x10) >> 1) |
    ((val & 0x20) >> 3) |
    ((val & 0x40) >> 5) |
    ((val & 0x80) >> 7);
    val = v2;
    //bval: biến đọc giá trị gửi về từ MISO_Pin
    byte bval = 0;
    //sck: biến lưu giá trị điều khiển chân SCK_Pin
    int sck = 0;
    for (uint8_t bit = 0u; bit < 8u; bit++)
    {
        /* ... Write bit */
        digitalWrite(MOSI_Pin, ((val & (1<<bit)) ? HIGH : LOW));
        wait(16);
        sck ^= 1u; 
        digitalWrite(SCK_Pin, sck);
        /* ... Read bit */
        {
            bval = digitalRead(MISO_Pin);
            out <<= 1;
            out |= bval;
        }
        wait(16);
        sck ^= 1u;
        digitalWrite(SCK_Pin, sck);
    }
    return out;
}
/*
Fuction: loop
Description: hàm chạy chương trình chính
*/
//NOTE: giá trị gửi đi tuỳ thuộc vào 1 nút nhấn
void loop(void)
{
    /*
    Mastersend: biến lưu dữ liệu tới Slave
    Mastereceive: biến lưu dữ liệu nhận về từ Slave
    */
    byte Mastersend = 0, Mastereceive = 0;
    buttonvalue = digitalRead(ipbutton);
    if (buttonvalue == HIGH)
    {
        x = 1;
    }
    else
    {
        x = 0;
    }
    Mastersend = x;
    Mastereceive=transfer(Mastersend);
    if (Mastereceive == 1)
    {
        digitalWrite(LED, HIGH);
        Serial.println("ledMasterOn");
    }
    else
    {
        digitalWrite(LED, LOW);
        Serial.println("ledMasterOff");
    }
    delay(250);
}