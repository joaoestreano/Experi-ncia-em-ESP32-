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
#define REST 0

void setup() {
  ledcAttach(pino_buzzer, 1000, 8);
  tocarParabens();
}

void tocarNota(int freq, int duracao) {
  ledcWriteTone(pino_buzzer, freq);
  delay(duracao * 0.9);
  ledcWriteTone(pino_buzzer, 0);
  delay(duracao * 0.1);
}

void tocarParabens() {
  int bpm  = 120;
  int S    = 60000 / bpm;
  int E    = S / 2;
  int Q    = S / 4;
  int SP   = S * 1.5;
  int L    = S * 2;

  // "Pa-ra-béns pra vo-cê"
  tocarNota(C4, Q);
  tocarNota(C4, E);
  tocarNota(D4, S);
  tocarNota(C4, S);
  tocarNota(F4, S);
  tocarNota(E4, L);

  // "Nes-ta da-ta que-ri-da"
  tocarNota(C4, Q);
  tocarNota(C4, E);
  tocarNota(D4, S);
  tocarNota(C4, S);
  tocarNota(G4, S);
  tocarNota(F4, L);

  // "Mui-tas fe-li-ci-da-des"
  tocarNota(C4, Q);
  tocarNota(C4, E);
  tocarNota(C5, S);
  tocarNota(A4, S);
  tocarNota(F4, S);
  tocarNota(E4, S);
  tocarNota(D4, S);

  // "Pa-ra-béns pra vo-cê"
  tocarNota(A4, Q);
  tocarNota(A4, E);
  tocarNota(G4, S);
  tocarNota(F4, S);
  tocarNota(G4, S);
  tocarNota(F4, L);

  ledcWriteTone(pino_buzzer, 0);
}

void loop() {}