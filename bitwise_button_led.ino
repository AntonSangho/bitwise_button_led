const int btn_pin = 7;
const int led_pin = 5;

void setup() {
  Serial.begin(9600);
  DDRD = B00010000;  
  PORTD = B0000100;
}

void loop() {
  
  int btn = (PIND & (1 << btn_pin)) >> btn_pin;
  Serial.println(PIND, BIN);
  if (btn == HIGH){
    PORTD = (1 << led_pin) | PORTD;
    delay(1000);
  } else {
    PORTD = ~(1 << led_pin) & PORTD;
    delay(1000);
  }
}
