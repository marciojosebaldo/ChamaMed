void setup() {

  Serial.begin(9600);
  
  led = 13; // pino exclusivo para o LED
  digitalWrite(led, low);

  for (int i = 2; i <= 12; i++) {
    pinMode(i, INPUT);
  }

  for (int j = 22; j <= 53; j++) {
    pinMode(j, INPUT);
  }

  pinMode(led, OUTPUT);
}

void loop() {

  if(Serial.available()) {
    for (int i = 2; i <= 12; i++) {
    // Portas com booleano
  }

  for (int j = 22; j <= 53; j++) {
    // Portas com booleano
  }
}