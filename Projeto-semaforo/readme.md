# 🚦 Projeto: Semáforo Inteligente com ESP32

## 📌 Descrição
Este projeto simula um sistema de semáforo utilizando um ESP32, controlando LEDs para representar o fluxo de veículos e pedestres. Ele alterna automaticamente entre os estados de **carros liberados**, **atenção (amarelo)** e **pedestres liberados**, incluindo um efeito de piscar para sinalização de atenção.

---

## 🔧 Componentes Utilizados

- 1x ESP32  
- 5x LEDs:
  - 2 para pedestres (verde e vermelho)
  - 3 para carros (verde, amarelo e vermelho)
- 5x resistores (220Ω ou 330Ω)
- Protoboard
- Jumpers (fios)

---

## 🔌 Montagem do Circuito (Parte Física)

### 📍 Organização dos LEDs

- **Pedestres:**
  - LED Verde → pino 26  
  - LED Vermelho → pino 25  

- **Carros:**
  - LED Verde → pino 14  
  - LED Amarelo → pino 12  
  - LED Vermelho → pino 13  

### ⚡ Ligações

Cada LED deve ser ligado da seguinte forma:

- **Perna longa (ânodo)** → conectada ao pino do ESP32  
- **Perna curta (cátodo)** → conectada ao resistor → GND  

💡 O resistor é essencial para evitar queimar o LED.

### 🧠 Observações importantes

- Todos os GNDs devem estar conectados ao GND do ESP32.
- Os LEDs estão organizados em duas “linhas”:
  - Uma para pedestres
  - Outra para veículos

---

## 🔁 Lógica do Funcionamento

### 1️⃣ Carros liberados | Pedestres parados
- 🚗 Verde: ON  
- 🚶 Vermelho: ON  
- ⏱️ Duração: 3 segundos  

---

### 2️⃣ Atenção (Carros - Amarelo)
- 🚗 Amarelo: ON  
- ⏱️ Duração: 2 segundos  

---

### 3️⃣ Carros parados | Pedestres liberados
- 🚗 Vermelho: ON  
- 🚶 Verde: ON  
- ⏱️ Duração: 3 segundos  

---

### 4️⃣ Atenção para pedestres (piscando)
- 🚶 Vermelho pisca 5 vezes  
- ⏱️ Intervalo: 500ms  

---

## ⚙️ Estrutura do Código

### 🔹 `setup()`
Configura todos os pinos como saída.

### 🔹 `loop()`
Executa continuamente a sequência do semáforo.

---

## 🚀 Possíveis Melhorias

- Adicionar botão para pedestres solicitarem travessia  
- Utilizar buzzer para acessibilidade  
- Implementar temporização com `millis()` (sem delay)  
- Criar interface web usando Wi-Fi do ESP32  
- Adicionar display com contagem regressiva  

---

## 📚 Conclusão

Este projeto é excelente para aprender:

- Controle de GPIO no ESP32  
- Lógica de temporização  
- Montagem em protoboard  
- Simulação de sistemas reais  
