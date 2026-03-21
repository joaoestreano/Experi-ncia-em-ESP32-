const int pino_buzzer = 32;

// Frequências das notas
#define E4  330
#define E5  659
#define A3  220
#define A4  440
#define B3  247
#define B4  494
#define C4  262
#define C5  523
#define C6  1047
#define D4  294
#define D5  587
#define F4  349
#define F5  698
#define G4  392
#define G5  784
#define Fs5 740  // F#5
#define Gs4 415  // G#4
#define As3 233  // A#3
#define As4 466  // A#4
#define Ds5 622  // D#5
#define Cs5 554  // C#5
#define REST 0

void setup() {
  ledcAttach(pino_buzzer, 1000, 8);
  tocarMario();
}

void tocarNota(int freq, int duracao) {
  ledcWriteTone(pino_buzzer, freq);
  delay(duracao * 0.9);
  ledcWriteTone(pino_buzzer, 0);
  delay(duracao * 0.1);
}

void tocarMario() {
  int bpm     = 200;
  int S       = 60000 / bpm;       // seminima
  int E       = S / 2;             // colcheia
  int Q       = S / 4;             // semicolcheia
  int L       = S * 2;             // minima
  int SP      = S * 1.5;           // seminima pontada

  // Intro
  tocarNota(E5,  E);
  tocarNota(E5,  E);
  tocarNota(REST,E);
  tocarNota(E5,  E);
  tocarNota(REST,E);
  tocarNota(C5,  E);
  tocarNota(E5,  S);
  tocarNota(G5,  S);
  tocarNota(REST,S);
  tocarNota(G4,  S);
  tocarNota(REST,S);

  // Tema principal
  tocarNota(C5,  S);
  tocarNota(REST,E);
  tocarNota(G4,  S);
  tocarNota(REST,E);
  tocarNota(E4,  S);
  tocarNota(REST,E);
  tocarNota(A4,  S);
  tocarNota(REST,E);
  tocarNota(B4,  S);
  tocarNota(REST,E);
  tocarNota(As4, S);
  tocarNota(A4,  S);
  tocarNota(REST,E);

  tocarNota(G4,  E);
  tocarNota(E5,  E);
  tocarNota(G5,  E);
  tocarNota(A5,  S);
  tocarNota(REST,E);
  tocarNota(F5,  S);
  tocarNota(G5,  S);
  tocarNota(REST,E);
  tocarNota(E5,  S);
  tocarNota(REST,E);
  tocarNota(C5,  S);
  tocarNota(D5,  S);
  tocarNota(B4,  S);
  tocarNota(REST,S);

  // Repetição do tema
  tocarNota(C5,  S);
  tocarNota(REST,E);
  tocarNota(G4,  S);
  tocarNota(REST,E);
  tocarNota(E4,  S);
  tocarNota(REST,E);
  tocarNota(A4,  S);
  tocarNota(REST,E);
  tocarNota(B4,  S);
  tocarNota(REST,E);
  tocarNota(As4, S);
  tocarNota(A4,  S);
  tocarNota(REST,E);

  tocarNota(G4,  E);
  tocarNota(E5,  E);
  tocarNota(G5,  E);
  tocarNota(A5,  S);
  tocarNota(REST,E);
  tocarNota(F5,  S);
  tocarNota(G5,  S);
  tocarNota(REST,E);
  tocarNota(E5,  S);
  tocarNota(REST,E);
  tocarNota(C5,  S);
  tocarNota(D5,  S);
  tocarNota(B4,  S);
  tocarNota(REST,S);

  // Parte dos canos (underworld-style)
  tocarNota(REST,E);
  tocarNota(G5,  Q);
  tocarNota(Fs5, Q);
  tocarNota(F5,  Q);
  tocarNota(Ds5, E);
  tocarNota(E5,  E);
  tocarNota(REST,E);
  tocarNota(Gs4, E);
  tocarNota(A4,  E);
  tocarNota(C5,  E);
  tocarNota(REST,E);
  tocarNota(A4,  E);
  tocarNota(C5,  E);
  tocarNota(D5,  E);

  tocarNota(REST,E);
  tocarNota(G5,  Q);
  tocarNota(Fs5, Q);
  tocarNota(F5,  Q);
  tocarNota(Ds5, E);
  tocarNota(E5,  E);
  tocarNota(REST,E);
  tocarNota(C6,  E);
  tocarNota(REST,E);
  tocarNota(C6,  E);
  tocarNota(C6,  S);
  tocarNota(REST,S);

  // Fim
  ledcWriteTone(pino_buzzer, 0);
}

void loop() {
  // Toca uma vez e para
  // Para repetir, chame tocarMario() aqui
}