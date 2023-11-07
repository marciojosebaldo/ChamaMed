// Biblioteca para RFID e protocolo de comunicação
#include <MFRC522.h>
#include <SPI.h>

// Pinos Reset e SDA
#define SS_PIN 53
#define RST_PIN 49
MFRC522 mfrc522(SS_PIN, RST_PIN);
char st[20];

int ledVerdePermissao = 40;
int ledVermelhoProibido = 41;

// Portas do Arduino que servirão de entrada do acionamento dos enfermeiras por parte do leito hospitalar
int porta2 = 2;
int porta3 = 3;
int porta4 = 4;
int porta5 = 5;
int porta6 = 6;

// Identificação visual do nível lógico alto das portas
int led = 13;

// Aviso sonoro com bipe de placas-mães de PC
int bipe = 22;

void setup() {
  Serial.begin(9600);

  // Parte dos botões para acionar os chamados das enfermeiras
  pinMode(porta2, INPUT);
  pinMode(porta3, INPUT);
  pinMode(porta4, INPUT);
  pinMode(porta5, INPUT);
  pinMode(porta6, INPUT);

  pinMode(led, OUTPUT);

  pinMode(bipe, OUTPUT);

  // Parte de leitura das tags RFID
  pinMode(ledVerdePermissao, OUTPUT);
  pinMode(ledVermelhoProibido, OUTPUT);

  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("Aproxime o cartão para leitura: ");
  Serial.println();  
}

void loop() {
  // Parte do acionamento de botões por parte dos pacientes
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
    if(true) {
      tone(bipe, 293);
      delay(200);
      noTone(bipe);
    }
  } else {
    digitalWrite(led, LOW);
    noTone(bipe);
  }

  // Atraso de 500 milissegundos entre cada ciclo
  delay(500);

  // Código de leitura das tags
  if (! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  Serial.print("Identificador da tag: ");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();

  if (conteudo.substring(1) == "23 2D C1 04") {
    digitalWrite(ledVerdePermissao, HIGH);
    digitalWrite(ledVermelhoProibido, LOW);
    Serial.println("TAG identificada!");
    Serial.println();
    delay(3000);
    digitalWrite(ledVerdePermissao, LOW);
  } else {
    digitalWrite(ledVerdePermissao, LOW);
    digitalWrite(ledVermelhoProibido, HIGH);
    delay(3000);
    digitalWrite(ledVermelhoProibido, LOW);
  }
}