int led = 13;  // Pino exclusivo para o LED

const int jgPortas1 = 10;
const int jgPortas2 = 32;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  for (int i = 0; i < jgPortas1; i++) {
    pinMode(i, INPUT);
  }

  for (int j = 0; j < jgPortas2; j++) {
    pinMode(j, INPUT);
  }
}

void loop() {
  if (Serial.available()) {
    for (int i = 0; i < jgPortas1; i++) {
      int estadoPorta = digitalRead(i);
      Serial.print("Porta 1, Pino ");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(estadoPorta);

      if (estadoPorta == HIGH) {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);
      }
    }

    for (int j = 0; j < jgPortas2; j++) {
      int estadoPorta = digitalRead(j);
      Serial.print("Porta 2, Pino ");
      Serial.print(j);
      Serial.print(": ");
      Serial.println(estadoPorta);

      if (estadoPorta == HIGH) {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);
      }
    }
  }
}
