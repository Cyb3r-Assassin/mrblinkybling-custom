void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  digitalWrite(8, LOW);
  for (int i = 8; i; i--) {
    //delay(1);
    digitalWrite(9, LOW);
    //delay(1);
    digitalWrite(9, HIGH);
  }
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
}

void load_line(uint8_t a, uint8_t b) {
  uint8_t p, x, i;
  for (p = 0, i = 8, x = a; i; p++, i--, x >>= 1) {
    digitalWrite(p, (x & 1) ? HIGH : LOW);
  }
  for (p = 14, i = 8, x = b; i; p++, i--, x >>= 1) {
    digitalWrite(p, (x & 1) ? HIGH : LOW);
  }
}

void flash() {
  load_line(0xff, 0x3f);
  for (int j = 20; j; j--) {
    digitalWrite(8, HIGH);
    //delay(1);
    for (int i = 6; i; i--) {
      digitalWrite(9, LOW);
      //delay(1);
      digitalWrite(9, HIGH);
      //delay(1);
      digitalWrite(8, LOW);
      delay(1);
      //delay(500);
    }
  }
  load_line(0, 0);
  delay(100);
}

void loop() {
  flash();
  flash();
  flash();
  flash();
  //delay(1000);
  delay(10000);
}

