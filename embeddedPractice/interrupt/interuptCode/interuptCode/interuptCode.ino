/*File: interruptCode
Author: DoVanTu
Fuction: kiểm tra thực thi ngắt trong vi điều khiển, boar sử dụng arduino NaNo
*/
#include <avr/interrupt.h>
const int D2_pin = 2;
const int D_pin = 13;

volatile boolean timerFlag = false;

void setup() {
  cli();
  Serial.begin(9600);
  pinMode(D_pin, OUTPUT);
  digitalWrite(D_pin,  1);
  pinMode(D2_pin, INPUT_PULLUP);
  attachInterrupt(0, D2_interrupt, LOW);
  // Khởi tạo timer1 để tạo ra ngắt sau mỗi 1s
  TCCR1A = 0; // Thiết lập TCCR1A để sử dụng chế độ đếm bình thường
  TCCR1B = 0; // Xóa TCCR1B
  TCNT1  = 0; // Khởi tạo giá trị đếm về 0
  OCR1A = 15624; // Tính toán giá trị OCR1A dựa trên tần số 16MHz của Arduino Nano
  TCCR1B |= (1 << WGM12); // Thiết lập chế độ đếm trong OCR1A
  TCCR1B |= (1 << CS12) | (1 << CS10); // Thiết lập bộ chia tần 1024
  TIMSK1 |= (1 << OCIE1A); // Cho phép ngắt khi đếm đến OCR1A
  sei();
}

void loop() {
  digitalWrite(D_pin,timerFlag);
  Serial.println(timerFlag);
}

void D2_interrupt() {
  digitalWrite(D_pin,0);
}

// Hàm xử lý ngắt timer1
ISR(TIMER1_COMPA_vect) {
  // Xử lý ngắt tại đây
  if(timerFlag==0)
  timerFlag=1;
  else
  timerFlag=0;
}





