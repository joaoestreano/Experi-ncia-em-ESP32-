# 🎹 Projeto: Piano Interativo com ESP32

## 📌 Descrição
Este projeto simula um mini piano interativo utilizando um ESP32, botões, LEDs e um buzzer passivo. Ao pressionar cada botão, uma nota musical é tocada e o LED correspondente acende. O projeto também inclui músicas pré-programadas: **Super Mario Bros**, **Parabéns pra Você** e **Asa Branca**.

---

## 🔧 Componentes Utilizados

- 1x ESP32 WROOM-32
- 3x Botões (push button)
- 3x LEDs (cores diferentes recomendadas)
- 3x Resistores (220Ω ou 330Ω)
- 1x Buzzer passivo
- Protoboard
- Jumpers (fios)

---

## 🔌 Montagem do Circuito (Parte Física)

### 📍 Organização dos pinos

- **Botões:**
  - Botão 1 (Dó) → pino 25
  - Botão 2 (Ré) → pino 26
  - Botão 3 (Mi) → pino 27

- **LEDs:**
  - LED 1 → pino 21
  - LED 2 → pino 19
  - LED 3 → pino 18

- **Buzzer:**
  - Buzzer passivo → pino 32

### ⚡ Ligações

Cada LED deve ser ligado da seguinte forma:

- **Perna longa (ânodo)** → conectada ao pino do ESP32
- **Perna curta (cátodo)** → conectada ao resistor → GND

Cada botão deve ser ligado da seguinte forma:

- **Um terminal** → conectado ao pino do ESP32
- **Outro terminal** → conectado ao GND

💡 Os botões usam `INPUT_PULLUP` interno do ESP32, portanto **não é necessário** resistor externo de pull-down.

### 🧠 Observações importantes

- Todos os GNDs devem estar conectados ao GND do ESP32.
- O buzzer utilizado deve ser do tipo **passivo** (controlado por frequência PWM).
- Este projeto é compatível com simulação no **Wokwi**.

---

## 🔁 Lógica do Funcionamento

### 1️⃣ Botão 1 pressionado
- 🎵 Nota **Dó** (261 Hz): tocando
- 💡 LED 1: ON
- ⏱️ Duração: enquanto o botão estiver pressionado

---

### 2️⃣ Botão 2 pressionado
- 🎵 Nota **Ré** (293 Hz): tocando
- 💡 LED 2: ON
- ⏱️ Duração: enquanto o botão estiver pressionado

---

### 3️⃣ Botão 3 pressionado
- 🎵 Nota **Mi** (329 Hz): tocando
- 💡 LED 3: ON
- ⏱️ Duração: enquanto o botão estiver pressionado

---

### 4️⃣ Nenhum botão pressionado
- 🔇 Buzzer: OFF
- 💡 Todos os LEDs: OFF

---

## ⚙️ Estrutura do Código

### 🔹 `setup()`
Configura os pinos dos botões como entrada (`INPUT_PULLUP`), os LEDs como saída, e inicializa o canal PWM do buzzer com `ledcAttach()`.

### 🔹 `loop()`
Lê continuamente o estado dos botões e aciona a nota e o LED correspondente.

### 🔹 `tocarNota(frequencia)`
Aciona o buzzer na frequência informada usando `ledcWriteTone()`.

### 🔹 `pararNota()`
Para o buzzer passando frequência 0 para `ledcWriteTone()`.

### 🔹 `tocarMario()`
Executa a sequência completa do tema do Super Mario Bros.

### 🔹 `tocarParabens()`
Executa a sequência completa de Parabéns pra Você.

### 🔹 `tocarAsaBranca()`
Executa a sequência completa de Asa Branca.

---

## 🎵 Músicas Disponíveis

| Música | Função | BPM |
|--------|--------|-----|
| 🍄 Super Mario Bros Theme | `tocarMario()` | 200 |
| 🎂 Parabéns pra Você | `tocarParabens()` | 120 |
| 🌵 Asa Branca | `tocarAsaBranca()` | 110 |

---

## ⚠️ Atenção: versão do ESP32 Arduino Core

Este projeto utiliza a **API LEDC do Core 3.x**:

```cpp
ledcAttach(pino, frequencia, resolucao);
ledcWriteTone(pino, frequencia);
```

> Se você usar o Core 2.x, substitua por `ledcSetup()` + `ledcAttachPin()`.

---

## 🚀 Possíveis Melhorias

- Adicionar mais botões para completar a escala musical (Fá, Sol, Lá, Si)
- Implementar modo de gravação e reprodução de melodias
- Adicionar display OLED mostrando a nota tocada
- Criar um modo de jogo estilo "Simon Says"
- Utilizar Wi-Fi do ESP32 para controle via interface web

---

## 📚 Conclusão

Este projeto é excelente para aprender:

- Controle de GPIO no ESP32
- Geração de som com PWM (buzzer passivo)
- Leitura de botões com `INPUT_PULLUP`
- Temporização e estrutura de melodias
- Simulação de circuitos no Wokwi
