  int bipe = 12; // pino exclusivo para o bipe
  int led = 13; // pino exclusivo para o LED

  const int jgPortas1 = 10;
  const int jgPortas2 = 32;

  bool portas1[10];
  bool portas2[32];

  void setup() {

  Serial.begin(9600);
  
  pinMode(led, OUTPUT);

  for (int i = 0; i < sizeof(jgPortas1); i++) {
    pinMode(portas1[i], INPUT);
  }  

  for (int j = 0; j < sizeof(jgPortas2); j++) {
    pinMode(portas2[j], INPUT);
  }
}

void loop() {

  if(Serial.available()) {
    for (int i = 0; i <= sizeof(jgPortas1); i++) {
      if(portas1[i] == 1) {
        portas1[i] = Serial.read() == 1;
        digitalWrite(led, high);
        delay(200);
        digitalWrite(led, low);
        delay(200);

        tone(bipe, 800);
        delay(200);
        noTone(bipe);
        delay(200);
      } else {
        digitalWrite(led, low);
        noTone(bipe);
      }
    }

    for (int j = 0; j <= sizeof(jgPortas2); j++) {
      if(portas2[j] == 1) {
        portas2[i] = Serial.read() == 1;
        digitalWrite(led, high);
        delay(200);
        digitalWrite(led, low);
        delay(200);

        tone(bipe, 800);
        delay(200);
        noTone(bipe);
        delay(200);
    } else {
        digitalWrite(led, low);
        noTone(bipe);
    }
  }
}