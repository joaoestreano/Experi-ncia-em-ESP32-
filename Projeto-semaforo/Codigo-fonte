// Definição dos pinos
const int pedestreVerde = 26;
const int pedestreVermelho = 25;
const int carroVerde = 14;
const int carroAmarelo = 12;
const int carroVermelho = 13;

void setup() {
  pinMode(pedestreVerde, OUTPUT);
  pinMode(pedestreVermelho, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);
}

void loop() {

  // 🚗 Carros ABERTO | 🚶 Pedestres FECHADO
  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);

  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);

  delay(3000);

  // 🚗 Carros ATENÇÃO
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);

  delay(2000);

  // 🚗 Carros FECHADO | 🚶 Pedestres ABERTO
  digitalWrite(pedestreVerde, HIGH);
  digitalWrite(pedestreVermelho, LOW);

  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, HIGH);

  delay(3000);

  // 🚶 Pedestre piscando (atenção)
  digitalWrite(pedestreVerde, LOW);

  for (int i = 0; i < 5; i++) {
    digitalWrite(pedestreVermelho, HIGH);
    delay(500);
    digitalWrite(pedestreVermelho, LOW);
    delay(500);
  }
}
