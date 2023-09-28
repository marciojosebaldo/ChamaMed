  int led = 13;  // Pino exclusivo para o LED

  int jogoPortas1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int jogoPortas2[] = {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
  int leituraPortas1[11];
  int leituraPortas2[40];

  void setup() {

  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  for (int i = 2; i <= 12; i++) {
    pinMode(jogoPortas1[i], INPUT);
  }

  for (int i = 14; i <= 53; i++) {
    pinMode(jogoPortas2[i], INPUT);
  }
}

void loop() {

if(Serial.available()) {
    for (int i = 2; i < 12; i++) {
      if (digitalRead(jogoPortas1[i]) == HIGH) {
        leituraPortas1[i] = Serial.read();
        digitalWrite(led, HIGH);
      } else {
        digitalWrite(led, LOW);
      }
    }
    
    for (int i = 14; i < 53; i++) {
      if (digitalRead(jogoPortas2[i] == HIGH)) {
        leituraPortas2[i] = Serial.read();
        digitalWrite(led, HIGH);
      } else {
        digitalWrite(led, LOW);
      }
    }
  }
}