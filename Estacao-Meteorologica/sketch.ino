// ============================================================
//   ESTAÇÃO METEOROLÓGICA - VERSÃO SIMPLES (DHT22 + OLED)
//   Sem BMP280 — funciona 100% no Wokwi
// ============================================================

#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHT_PINO  4
#define DHT_TIPO  DHT22

#define OLED_LARGURA  128
#define OLED_ALTURA    64
#define OLED_RESET     -1
#define OLED_ENDERECO 0x3C

DHT              dht(DHT_PINO, DHT_TIPO);
Adafruit_SSD1306 display(OLED_LARGURA, OLED_ALTURA, &Wire, OLED_RESET);

float temperatura = 0;
float umidade     = 0;
float indiceCalor = 0;
int   tela        = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ENDERECO)) {
    Serial.println("[ERRO] OLED não encontrado!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("Estacao");
  display.setCursor(10, 42);
  display.println("Meteo!");
  display.display();
  delay(2000);

  Serial.println("Sistema pronto!");
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (!isnan(t) && !isnan(h)) {
    temperatura = t;
    umidade     = h;
    indiceCalor = dht.computeHeatIndex(t, h, false);
  }

  // Exibe no Serial
  Serial.println("─────────────────────");
  Serial.print("Temp     : "); Serial.print(temperatura, 1); Serial.println(" C");
  Serial.print("Umidade  : "); Serial.print(umidade, 1);     Serial.println(" %");
  Serial.print("Ind.Calor: "); Serial.print(indiceCalor, 1); Serial.println(" C");
  Serial.println("─────────────────────");

  // Alterna telas no OLED
  display.clearDisplay();

  if (tela == 0) {
    // Tela 1: Temperatura grande
    display.setTextSize(1);
    display.setCursor(15, 0);
    display.println("= TEMPERATURA =");

    display.setTextSize(3);
    display.setCursor(5, 16);
    display.print(temperatura, 1);
    display.print((char)247);
    display.println("C");

    display.setTextSize(1);
    display.setCursor(0, 56);
    display.print("Umidade: ");
    display.print(umidade, 1);
    display.print("%");

  } else {
    // Tela 2: Umidade e Índice de Calor
    display.setTextSize(1);
    display.setCursor(20, 0);
    display.println("= UMIDADE =");

    display.setTextSize(3);
    display.setCursor(5, 16);
    display.print(umidade, 1);
    display.println("%");

    display.setTextSize(1);
    display.setCursor(0, 56);
    display.print("Ind.Calor: ");
    display.print(indiceCalor, 1);
    display.print("C");
  }

  display.display();
  tela = (tela + 1) % 2;
  delay(3000);
}
