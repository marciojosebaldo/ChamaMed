void setup() {

  Serial.begin(9600);
  
  bipe = 12; // pino exclusivo para o bipe
  led = 13; // pino exclusivo para o LED
  
  pinMode(led, OUTPUT);
  pinode(bipe, OUTPUT);
  
  digitalWrite(led, low);
  digitalWrite(bipe, low);

  for (int i = 2; i <= 11; i++) {
    pinMode(porta[i], INPUT);
  }

  for (int j = 22; j <= 53; j++) {
    pinMode(porta[j], INPUT);
  }

}

void loop() {

  if(Serial.available()) {
    for (int i = 2; i <= 12; i++) {
      if(porta[i] == HIGH) {
        
      }
  }

  for (int j = 22; j <= 53; j++) {
    if(porta[j] == HIGH) {

    }
  }

}