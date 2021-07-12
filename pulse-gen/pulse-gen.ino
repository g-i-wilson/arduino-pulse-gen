int initDuration = 1000; // pulse duration [ms]

void setup() {
  pinMode(12,OUTPUT); // pulse (PB4)
  pinMode(13,OUTPUT); // LED (PB5)

  PORTB=0b11000000;
  
  Serial.begin(115200);
  Serial.setTimeout(initDuration);
  
  while(!Serial){;}
}

void loop() {

  int newDuration = Serial.parseInt();
  if (newDuration>10) {
    Serial.setTimeout(newDuration-10);
    Serial.print("Duration [ms]: ");
    Serial.println(newDuration);
  }

  PORTB=0b11100000;
  delay(10); // 1/100 second blink on
  PORTB=0b11010000;
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  PORTB=0b11000000; // 8 clock cycles == 500ns

}
