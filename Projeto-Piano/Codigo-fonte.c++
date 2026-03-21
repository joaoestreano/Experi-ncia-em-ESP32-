const int pino_botao1 = 25;
const int pino_botao2 = 26;
const int pino_botao3 = 27;
const int pino_buzzer = 32;
const int pino_led1   = 21;
const int pino_led2   = 19;
const int pino_led3   = 18;

// Frequências das notas musicais
const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi

void setup() {
  pinMode(pino_botao1, INPUT_PULLUP);
  pinMode(pino_botao2, INPUT_PULLUP);
  pinMode(pino_botao3, INPUT_PULLUP);
  pinMode(pino_led1, OUTPUT);
  pinMode(pino_led2, OUTPUT);
  pinMode(pino_led3, OUTPUT);

  // Nova API do Core v3.x — sem ledcSetup
  ledcAttach(pino_buzzer, 1000, 8);
}

void tocarNota(int frequencia) {
  ledcWriteTone(pino_buzzer, frequencia);
}

void pararNota() {
  ledcWriteTone(pino_buzzer, 0);
}

void loop() {
  bool estado_botao1 = digitalRead(pino_botao1);
  bool estado_botao2 = digitalRead(pino_botao2);
  bool estado_botao3 = digitalRead(pino_botao3);

  if (estado_botao1 == LOW) {
    tocarNota(c);
    digitalWrite(pino_led1, HIGH);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }
  else if (estado_botao2 == LOW) {
    tocarNota(d);
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, HIGH);
    digitalWrite(pino_led3, LOW);
  }
  else if (estado_botao3 == LOW) {
    tocarNota(e);
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, HIGH);
  }
  else {
    pararNota();
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }
}