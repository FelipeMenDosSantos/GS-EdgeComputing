### Felipe Men dos Santos 557571

# **Projeto de Monitoramento de Umidade com Envio ao Adafruit IO**

## **Descrição do Projeto**
Este projeto implementa um sistema para monitoramento da umidade do ar utilizando um sensor **DHT22** e o envio dos dados para a plataforma **Adafruit IO** via **protocolo MQTT**. Ele foi desenvolvido para ajudar no monitoramento remoto de condições ambientais, podendo ser aplicado em contextos como agricultura, controle climático ou integração com sistemas de energia renovável.

Os dados são enviados para um feed no Adafruit IO, onde podem ser monitorados em tempo real, analisados com gráficos históricos e usados para configurar alertas ou automações.

---

## **Problema: Prevenção de Seca em Áreas de Hidrelétricas**
A geração de energia hidrelétrica depende diretamente da disponibilidade de água nos reservatórios, que é afetada por fatores climáticos e ambientais. Durante períodos de seca, a redução no nível dos reservatórios pode comprometer a geração de energia, afetando a estabilidade do sistema elétrico e a segurança energética de regiões inteiras. 

A falta de um monitoramento adequado da umidade do solo e das condições ambientais pode levar a uma gestão ineficiente dos recursos hídricos, dificultando a implementação de estratégias preventivas. Essa situação é agravada pelas mudanças climáticas, que tornam os períodos de seca mais frequentes e intensos.

### Principais consequências da seca:
1. Redução da capacidade de geração de energia.
2. Aumento da dependência de fontes não renováveis, como termelétricas, com custos maiores e impacto ambiental negativo.
3. Diminuição da disponibilidade de água para agricultura, consumo humano e outros usos essenciais.

---

## **Solução**
O projeto apresentado oferece uma solução eficiente e acessível para monitorar a umidade do ar, que pode ser complementado para medir a umidade do solo em áreas estratégicas, contribuindo para a prevenção de secas e otimização de recursos hídricos. 

### Como o projeto ajuda:
1. **Monitoramento contínuo**:
   - Dados de umidade do ar (e potencialmente do solo) são capturados em tempo real, permitindo a análise detalhada das condições ambientais.
   
2. **Identificação de tendências de seca**:
   - A partir dos dados coletados, é possível prever períodos de seca com base na redução gradual da umidade, ajudando na tomada de decisões antecipadas.

3. **Gestão proativa de recursos hídricos**:
   - As informações podem ser usadas para otimizar o uso de água nos reservatórios, garantindo que a geração de energia e outros usos essenciais sejam priorizados durante períodos críticos.

4. **Integração com sistemas IoT**:
   - Os dados enviados ao Adafruit IO podem ser analisados remotamente, permitindo a automação de ações preventivas, como alertas para irrigação ou ajustes no fluxo de geração de energia.

5. **Escalabilidade**:
   - Com sensores adicionais e ajustes no software, o sistema pode ser ampliado para monitorar múltiplos pontos críticos em uma bacia hidrográfica.

### Benefícios:
- Redução de riscos de falta de energia durante períodos de seca.
- Uso sustentável dos recursos hídricos.
- Integração com sistemas renováveis híbridos para compensar eventuais quedas na geração hidrelétrica.
- Dados históricos para análises climáticas e melhorias futuras.

---

## **Funcionalidades**
- Leitura da umidade do ar em tempo real utilizando o sensor **DHT22**.
- Envio dos dados para o Adafruit IO via MQTT.
- Reconexão automática à rede Wi-Fi e ao servidor MQTT em caso de falha.
- Monitoramento contínuo com envio de dados a cada 10 segundos.

---

## **Arquitetura**
O projeto consiste nos seguintes componentes principais:

1. **Microcontrolador ESP32**:
   - Responsável por capturar os dados do sensor DHT22.
   - Estabelece a conexão com o Wi-Fi e o Adafruit IO.
   - Publica os dados no feed MQTT.

2. **Sensor DHT22**:
   - Mede a umidade do ar.
   - Conecta-se ao ESP32 via um pino digital.

3. **Plataforma Adafruit IO**:
   - Recebe os dados publicados pelo ESP32.
   - Exibe os valores no feed **`FelipeMen/feeds/humidity`**.
   - Permite visualização gráfica, criação de alertas e integração com outros sistemas.

     
![image](https://github.com/user-attachments/assets/654b93c2-2a81-4750-b2e7-d1f8984e28fa)

---

## **Requisitos**
- **Hardware**:
  - ESP32 (ou outro microcontrolador compatível com Wi-Fi e MQTT).
  - Sensor DHT22.
  - Cabos de conexão.
  
- **Software**:
  - Arduino IDE com as seguintes bibliotecas instaladas:
    - `WiFi` (inclusa na ESP32 Core).
    - `Adafruit MQTT Library`.
    - `DHT Sensor Library`.

---

## **Configuração e Instalação**

### 1. **Configuração do Adafruit IO**
- Crie uma conta no [Adafruit IO](https://io.adafruit.com/).
- Gere uma **chave de API** (AIO Key) na seção **Settings**.
- Crie um feed chamado **`humidity`**.

### 2. **Configuração do Código**
- Faça o download do código e abra-o na Arduino IDE.
- Atualize as seguintes variáveis com suas credenciais:
  ```cpp
  #define REDE_WIFI "SEU_SSID"
  #define SENHA_WIFI "SUA_SENHA"
  #define USUARIO_AIO "SEU_USUARIO_AIO"
  #define CHAVE_AIO "SUA_CHAVE_AIO"
  ```
- Certifique-se de que o pino do sensor corresponde ao valor da constante `#define PINO_DHT`.

### 3. **Upload para o ESP32**
- Conecte o ESP32 ao computador.
- Na Arduino IDE, selecione a porta correta e o modelo do ESP32.
- Faça o upload do código.

---

## **Uso**
1. **Inicialização**:
   - Ao ser ligado, o ESP32 tentará se conectar ao Wi-Fi e ao Adafruit IO.
   - O sensor será inicializado para começar a capturar dados.

2. **Monitoramento**:
   - Verifique os dados no feed `humidity` na [interface do Adafruit IO](https://io.adafruit.com/).
   - Os dados são enviados a cada 10 segundos.

---

## **Dependências**
Certifique-se de que as seguintes bibliotecas estão instaladas na Arduino IDE:
- [Adafruit MQTT Library](https://github.com/adafruit/Adafruit_MQTT_Library)
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)

---

## Vídeo Demonstrativo:
[Link do Vídeo Demonstrativo no Youtube.](https://youtu.be/kiDGf_GEPrg)
