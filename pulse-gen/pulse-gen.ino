int outputPin = 13;

int initPrf = 100; // pulse repetition frequency [ms]; default is 100Hz

void setup() {
  pinMode(outputPin,OUTPUT);
  
  Serial.begin(115200);
  Serial.setTimeout(initPrf);
  
  while(!Serial){;}
}

void loop() {

  int newPrf = Serial.parseInt();
  if (newPrf>0) {
    Serial.setTimeout(newPrf);
    Serial.print("PRF set to: ");
    Serial.println(newPrf);
  }

  PORTB=11100000;
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  PORTB=11000000; // 8 clock cycles == 500ns

}
