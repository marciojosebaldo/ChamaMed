int bipe = 12; // Pino exclusivo para o bipe
int led = 13;  // Pino exclusivo para o LED

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
  if (Serial.available()) {
    for (int i = 0; i < 10; i++) {
      if (portas1[i] == 1) {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);

        tone(bipe, 800);
        delay(200);
        noTone(bipe);
        delay(200);
      } else {
        digitalWrite(led, LOW);
        noTone(bipe);
      }
    }

    for (int j = 0; j < 32; j++) {
      if (portas2[j] == 1) {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);

        tone(bipe, 800);
        delay(200);
        noTone(bipe);
        delay(200);
      } else {
        digitalWrite(led, LOW);
        noTone(bipe);
      }
    }
  }
}
