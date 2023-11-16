// Biblioteca para RFID e protocolo de comunicação
#include <MFRC522.h>
#include <SPI.h>

// Pinos Reset e SDA
#define SS_PIN 53 // Define o pino CS (Chip Selected)
#define RST_PIN 49 // Define o pino Reset
MFRC522 mfrc522(SS_PIN, RST_PIN); // Criada uma instância do objeto MRFC522 e utiliza os pinos definidos anteriormente como parâmetros

// Pinos do Arduino para aviso visual da leitura das tags RFID
int ledVerdePermissao = 40;
int ledVermelhoProibido = 41;

// Pino para baixar o nível lógico da placa quando o enfermeiro(a)/médico(a) atender o paciente
int pinoNivelAltoRFID = 42;

// Portas do Arduino que servirão de entrada do acionamento dos enfermeiras por parte do leito hospitalar
int porta2 = 2;
int porta3 = 3;
int porta4 = 4;
int porta5 = 5;
int porta6 = 6;
int porta7 = 23;

// Identificação visual do nível lógico alto das portas
int led = 13;

// Aviso sonoro com bipe de placas-mães de PC
int bipe = 22;

void setup() {
  Serial.begin(9600);

  // Parte dos botões para acionar os chamados da enfermaria
  pinMode(porta2, INPUT);
  pinMode(porta3, INPUT);
  pinMode(porta4, INPUT);
  pinMode(porta5, INPUT);
  pinMode(porta6, INPUT);
  pinMode(porta7, INPUT);

  pinMode(led, OUTPUT);

  pinMode(bipe, OUTPUT);

  pinMode(pinoNivelAltoRFID, OUTPUT);

  // Parte de leitura das tags RFID
  pinMode(ledVerdePermissao, OUTPUT);
  pinMode(ledVermelhoProibido, OUTPUT);

  // Por padrão, permanece em nível lógico alto para permitir que o botão de chamada do leito esteja ativo
  digitalWrite(pinoNivelAltoRFID, HIGH);

  // Inicia a comunicação SPI no Arduino. SPI é Serial Peripheral Interface que é um protocolo utilizado para comunicação entre dispositivos microcontroladores
  SPI.begin();
  // É invocado o método PCD_Init que inicializa o leitor RFID para operação. Configura os registros internos do leitor RFID
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
  int nivelPorta7 = digitalRead(porta7);

  // Este código induz o programa a mandar os caracteres apenas quando haver mudança de estado das portas
  static int estadoPortaAnterior2 = LOW;
  static int estadoPortaAnterior3 = LOW;
  static int estadoPortaAnterior4 = LOW;
  static int estadoPortaAnterior5 = LOW;
  static int estadoPortaAnterior6 = LOW;
  static int estadoPortaAnterior7 = LOW;

  if (nivelPorta2 != estadoPortaAnterior2) {
    Serial.write(nivelPorta2 == HIGH ? "porta2Lig\n" : "porta2Des\n");
    estadoPortaAnterior2 = nivelPorta2;
  }

  if (nivelPorta3 != estadoPortaAnterior3) {
    Serial.write(nivelPorta3 == HIGH ? "porta3Lig\n" : "porta3Des\n");
    estadoPortaAnterior3 = nivelPorta3;
  }

  if (nivelPorta4 != estadoPortaAnterior4) {
    Serial.write(nivelPorta4 == HIGH ? "porta4Lig\n" : "porta4Des\n");
    estadoPortaAnterior4 = nivelPorta4;
  }

  if (nivelPorta5 != estadoPortaAnterior5) {
    Serial.write(nivelPorta5 == HIGH ? "porta5Lig\n" : "porta5Des\n");
    estadoPortaAnterior5 = nivelPorta5;
  }

  if (nivelPorta6 != estadoPortaAnterior6) {
    Serial.write(nivelPorta6 == HIGH ? "porta6Lig\n" : "porta6Des\n");
    estadoPortaAnterior6 = nivelPorta6;
  }

  if (nivelPorta7 != estadoPortaAnterior7) {
    Serial.write(nivelPorta7 == HIGH ? "porta7Lig\n" : "porta7Des\n");
    estadoPortaAnterior7 = nivelPorta7;
  }

  if (nivelPorta2 == HIGH || nivelPorta3 == HIGH || nivelPorta4 == HIGH || nivelPorta5 == HIGH || nivelPorta6 == HIGH || nivelPorta7 == HIGH) {
    digitalWrite(led, HIGH);
    tone(bipe, 293);
    delay(200);
    noTone(bipe);
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, LOW);
    noTone(bipe);
  }

  // Código de leitura das tags. Se uma nova tag não for incluída, o código não será executado. Assim, evita operações desnecessárias
  // Nesta linha, a função abaixo confere se há uma nova tag inserida. Retorna verdadeiro se nova tag for identificada
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  // Aqui, a função tenta ler os códigos inseridos na tag. Sua execução depende da função anterior acima
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  // Trecho do código que lida com a impressão da tag lida
  Serial.print("Identificador da tag: ");
  String conteudo = "";
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  conteudo.toUpperCase();

  if (conteudo.substring(1) == "23 2D C1 04") {
    Serial.println();
    Serial.println("TAG identificada!");
    digitalWrite(ledVerdePermissao, HIGH);
    digitalWrite(ledVermelhoProibido, LOW);
    digitalWrite(pinoNivelAltoRFID, LOW);
    Serial.println();
    delay(3000);
    digitalWrite(ledVerdePermissao, LOW);
    digitalWrite(pinoNivelAltoRFID, HIGH);
  } else {
    Serial.println();
    Serial.println("TAG NÃO identificada!");
    digitalWrite(ledVerdePermissao, LOW);
    digitalWrite(ledVermelhoProibido, HIGH);
    delay(3000);
    digitalWrite(ledVermelhoProibido, LOW);
  }

   // Atraso de 500 milissegundos entre cada ciclo
  delay(500);
  
}
