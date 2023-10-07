// Portas do Arduino que servirão de entrada do acionamento dos enfermeiras por parte do leito hospitalar
int porta2 = 2;
int porta3 = 3;
int porta4 = 4;
int porta5 = 5;
int porta6 = 6;

// Uso para identificação visual do nível lógico alto das portas
int led = 13;

void setup() {
  pinMode(porta2, INPUT);
  pinMode(porta3, INPUT);
  pinMode(porta4, INPUT);
  pinMode(porta5, INPUT);
  pinMode(porta6, INPUT);

  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int nivelPorta2 = digitalRead(porta2);
  int nivelPorta3 = digitalRead(porta3);
  int nivelPorta4 = digitalRead(porta4);
  int nivelPorta5 = digitalRead(porta5);
  int nivelPorta6 = digitalRead(porta6);

  if (nivelPorta2 == LOW) {
    Serial.write("porta2Des\n");
  }
  
  if (nivelPorta2 == HIGH) {
    Serial.write("porta2Lig\n");
  } 

  if (nivelPorta3 == LOW) {
    Serial.write("porta3Des\n");
  }
  
  if (nivelPorta3 == HIGH) {
    Serial.write("porta3Lig\n");
  }

  if (nivelPorta4 == LOW) {
    Serial.write("porta4Des\n");
  }
  
  if (nivelPorta4 == HIGH) {
    Serial.write("porta4Lig\n");
  }

  if (nivelPorta5 == LOW) {
    Serial.write("porta5Des\n");
  }
  
  if (nivelPorta5 == HIGH) {
    Serial.write("porta5Lig\n");
  }

  if (nivelPorta6 == LOW) {
    Serial.write("porta6Des\n");
  }
  
  if (nivelPorta6 == HIGH) {
    Serial.write("porta6Lig\n");
  }

  if (nivelPorta2 == HIGH || nivelPorta3 == HIGH || nivelPorta4 == HIGH || nivelPorta5 == HIGH || nivelPorta6 == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(500);  // Atraso de 500 milissegundo entre as leituras
}
