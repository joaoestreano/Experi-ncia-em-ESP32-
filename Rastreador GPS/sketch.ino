// ============================================================
//   RASTREADOR GPS - ESP32 + OLED
//   Versão Wokwi com GPS SIMULADO no próprio código
//   (O Wokwi não suporta módulo GPS real)
//
//   Simula um trajeto real se movendo automaticamente!
//   BIBLIOTECAS: Adafruit SSD1306 + Adafruit GFX
// ============================================================

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_LARGURA  128
#define OLED_ALTURA    64
#define OLED_RESET     -1
#define OLED_ENDERECO 0x3C

Adafruit_SSD1306 display(OLED_LARGURA, OLED_ALTURA, &Wire, OLED_RESET);

// ─────────────────────────────────────────
//   SIMULAÇÃO DE TRAJETO (São Paulo → Centro)
//   Coordenadas reais de um trajeto urbano
// ─────────────────────────────────────────
struct PontoGPS {
  double lat;
  double lng;
  double velocidade;
  double altitude;
};

PontoGPS trajeto[] = {
  { -23.550520, -46.633308, 0.0,  760.0 },   // Ponto 1 - Av. Paulista
  { -23.551200, -46.634100, 32.5, 758.0 },   // Ponto 2
  { -23.552000, -46.635200, 45.0, 755.0 },   // Ponto 3
  { -23.552800, -46.636000, 51.2, 752.0 },   // Ponto 4
  { -23.553500, -46.637100, 48.7, 750.0 },   // Ponto 5
  { -23.554200, -46.638300, 38.0, 748.0 },   // Ponto 6
  { -23.554900, -46.639200, 29.5, 745.0 },   // Ponto 7 - desacelerando
  { -23.555500, -46.640000, 15.0, 743.0 },   // Ponto 8
  { -23.556100, -46.640800, 8.0,  741.0 },   // Ponto 9
  { -23.556700, -46.641500, 0.0,  740.0 },   // Ponto 10 - parado
  { -23.556000, -46.640700, 12.0, 741.0 },   // Ponto 11 - voltando
  { -23.555200, -46.639800, 35.0, 743.0 },   // Ponto 12
  { -23.554400, -46.638700, 47.0, 746.0 },   // Ponto 13
  { -23.553600, -46.637500, 50.0, 749.0 },   // Ponto 14
  { -23.552700, -46.636200, 44.0, 752.0 },   // Ponto 15
  { -23.551800, -46.635000, 33.0, 756.0 },   // Ponto 16
  { -23.551000, -46.633900, 20.0, 758.0 },   // Ponto 17
  { -23.550520, -46.633308, 0.0,  760.0 },   // Ponto 18 - chegou
};

const int TOTAL_PONTOS = sizeof(trajeto) / sizeof(trajeto[0]);
int pontoAtual = 0;
int satelites  = 8;
int tela       = 0;

unsigned long ultimaAtualizacao = 0;
const int INTERVALO = 3000; // muda ponto a cada 3 segundos

// Horário simulado
int hora   = 14;
int minuto = 30;
int segundo = 0;

// ─────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(500);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ENDERECO)) {
    Serial.println("[ERRO] OLED não encontrado!");
    while (true);
  }

  // Tela de início
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(15, 5);
  display.println("Rastreador");
  display.setCursor(35, 30);
  display.println("GPS");
  display.setTextSize(1);
  display.setCursor(10, 54);
  display.println("Simulando trajeto...");
  display.display();
  delay(2500);

  Serial.println("=== Rastreador GPS ESP32 ===");
  Serial.println("Simulando trajeto em Sao Paulo...");
  Serial.println("Total de pontos: " + String(TOTAL_PONTOS));
  Serial.println("");
}

// ─────────────────────────────────────────
void loop() {
  if (millis() - ultimaAtualizacao >= INTERVALO) {
    ultimaAtualizacao = millis();

    PontoGPS p = trajeto[pontoAtual];

    // Avança o horário simulado
    segundo += 3;
    if (segundo >= 60) { segundo = 0; minuto++; }
    if (minuto  >= 60) { minuto  = 0; hora++;   }

    // Varia satélites aleatoriamente entre 7 e 12
    satelites = 7 + (pontoAtual % 5);

    exibirSerial(p);
    alternarTelas(p);

    pontoAtual = (pontoAtual + 1) % TOTAL_PONTOS;
    tela = (tela + 1) % 3;
  }
}

// ─────────────────────────────────────────
//   MONITOR SERIAL
// ─────────────────────────────────────────
void exibirSerial(PontoGPS p) {
  Serial.println("─────────────────────────────────────");
  Serial.print("Ponto     : "); Serial.print(pontoAtual + 1); Serial.print("/"); Serial.println(TOTAL_PONTOS);
  Serial.print("Latitude  : "); Serial.println(p.lat, 6);
  Serial.print("Longitude : "); Serial.println(p.lng, 6);
  Serial.print("Altitude  : "); Serial.print(p.altitude, 1); Serial.println(" m");
  Serial.print("Velocidade: "); Serial.print(p.velocidade, 1); Serial.println(" km/h");
  Serial.print("Satelites : "); Serial.println(satelites);
  Serial.print("Hora UTC  : ");
  if (hora < 10) Serial.print("0"); Serial.print(hora); Serial.print(":");
  if (minuto < 10) Serial.print("0"); Serial.print(minuto); Serial.print(":");
  if (segundo < 10) Serial.print("0"); Serial.println(segundo);
  Serial.print("Google Maps: https://maps.google.com/?q=");
  Serial.print(p.lat, 6); Serial.print(","); Serial.println(p.lng, 6);
  Serial.println("─────────────────────────────────────");
}

// ─────────────────────────────────────────
//   ALTERNA TELAS OLED
// ─────────────────────────────────────────
void alternarTelas(PontoGPS p) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  if (tela == 0) telaCoordenadas(p);
  else if (tela == 1) telaVelocidade(p);
  else telaHora(p);

  display.display();
}

// ─────────────────────────────────────────
//   TELA 1 — Coordenadas
// ─────────────────────────────────────────
void telaCoordenadas(PontoGPS p) {
  display.setTextSize(1);
  display.setCursor(18, 0);
  display.println("== POSICAO GPS ==");

  display.setCursor(0, 13);
  display.print("Lat: "); display.println(p.lat, 5);

  display.setCursor(0, 25);
  display.print("Lng: "); display.println(p.lng, 5);

  display.setCursor(0, 37);
  display.print("Alt: "); display.print(p.altitude, 0); display.println(" m");

  display.setCursor(0, 52);
  display.print("Sat: "); display.print(satelites);
  display.print("  Pt:");
  display.print(pontoAtual + 1); display.print("/"); display.print(TOTAL_PONTOS);
}

// ─────────────────────────────────────────
//   TELA 2 — Velocidade
// ─────────────────────────────────────────
void telaVelocidade(PontoGPS p) {
  display.setTextSize(1);
  display.setCursor(15, 0);
  display.println("== VELOCIDADE ==");

  display.setTextSize(3);
  display.setCursor(10, 16);
  display.print((int)p.velocidade);

  display.setTextSize(2);
  display.setCursor(75, 22);
  display.println("km/h");

  display.setTextSize(1);
  display.setCursor(0, 52);

  if (p.velocidade == 0) {
    display.println("*** VEICULO PARADO ***");
  } else if (p.velocidade < 20) {
    display.println("Trafego lento");
  } else if (p.velocidade < 60) {
    display.println("Velocidade normal");
  } else {
    display.println("Via rapida");
  }
}

// ─────────────────────────────────────────
//   TELA 3 — Hora e Status
// ─────────────────────────────────────────
void telaHora(PontoGPS p) {
  display.setTextSize(1);
  display.setCursor(25, 0);
  display.println("== HORA GPS ==");

  display.setTextSize(3);
  display.setCursor(5, 16);
  if (hora < 10) display.print("0");
  display.print(hora); display.print(":");
  if (minuto < 10) display.print("0");
  display.println(minuto);

  display.setTextSize(1);
  display.setCursor(45, 48);
  if (segundo < 10) display.print("0");
  display.print(segundo);
  display.println(" seg (UTC)");
}