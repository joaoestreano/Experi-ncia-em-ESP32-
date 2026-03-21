const int pino_buzzer = 32;

#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494
#define C5  523
#define D5  587
#define E5  659
#define REST 0

void setup() {
  ledcAttach(pino_buzzer, 1000, 8);
  tocarAsaBranca();
}

void tocarNota(int freq, int duracao) {
  ledcWriteTone(pino_buzzer, freq);
  delay(duracao * 0.9);
  ledcWriteTone(pino_buzzer, 0);
  delay(duracao * 0.1);
}

void tocarAsaBranca() {
  int bpm  = 110;
  int S    = 60000 / bpm;
  int E    = S / 2;
  int Q    = S / 4;
  int SP   = S * 1.5;
  int L    = S * 2;

  // "Quando o sol da primavera"
  tocarNota(E4,  E);
  tocarNota(G4,  S);
  tocarNota(G4,  S);
  tocarNota(G4,  S);
  tocarNota(A4,  S);
  tocarNota(G4,  S);
  tocarNota(E4,  S);
  tocarNota(D4,  S);

  // "queimar a terra"
  tocarNota(E4,  SP);
  tocarNota(D4,  Q);
  tocarNota(C4,  L);

  // "Quando o nordestino"
  tocarNota(E4,  E);
  tocarNota(G4,  S);
  tocarNota(G4,  S);
  tocarNota(G4,  S);
  tocarNota(A4,  S);
  tocarNota(G4,  S);
  tocarNota(E4,  S);
  tocarNota(D4,  S);

  // "chora de dor"
  tocarNota(E4,  SP);
  tocarNota(D4,  Q);
  tocarNota(C4,  L);

  // "Eu pergunto a Deus do céu"
  tocarNota(G4,  E);
  tocarNota(A4,  S);
  tocarNota(A4,  S);
  tocarNota(A4,  S);
  tocarNota(B4,  S);
  tocarNota(A4,  S);
  tocarNota(G4,  S);
  tocarNota(E4,  S);

  // "ai por que tamanha"
  tocarNota(G4,  SP);
  tocarNota(E4,  Q);
  tocarNota(D4,  L);

  // "crueldade"
  tocarNota(A4,  E);
  tocarNota(G4,  S);
  tocarNota(E4,  S);
  tocarNota(D4,  SP);
  tocarNota(C4,  Q);
  tocarNota(C4,  L);

  ledcWriteTone(pino_buzzer, 0);
}

void loop() {}