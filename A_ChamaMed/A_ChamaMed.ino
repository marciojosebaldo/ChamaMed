void setup() {

  led = 13; // pino exclusivo para o LED

  for (int i = 2; i <= 12; i++) {
    pinMode(i, INPUT);
  }

  for (int j = 22; j <= 53; j++) {
    pinMode(j, INPUT);
  }

  pinMode(led, OUTPUT);
  digitalWrite(led, low);


}

void loop() {
  // put your main code here, to run repeatedly:

}
