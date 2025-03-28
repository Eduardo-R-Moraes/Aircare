# Controle de Umidificador com ESP32, DHT11 e Relé

Este projeto utiliza um ESP32 para monitorar a umidade ambiente por meio do sensor DHT11 e controla um umidificador conectado a um relé. Quando a umidade medida estiver abaixo do valor desejado, o ESP32 acionará o relé para ligar o umidificador; caso contrário, o relé será desligado.

## Materiais Necessários

- **ESP32**: placa de desenvolvimento principal.
- **Sensor DHT11**: para medir a umidade e temperatura do ambiente.
- **Módulo Relé**: para controlar o acionamento do umidificador.
- **Umidificador**: aparelho que será controlado pelo relé.
- **Resistor de 10kΩ**: utilizado como pull-up para o pino de dados do DHT11.
- **Protoboard e Jumpers**: para montagem dos circuitos.
- **Fonte de Alimentação**: adequada para o ESP32 e o umidificador.

## Montagem do Circuito

1. **Conexão do Sensor DHT11**:
   - **VCC**: conectar ao pino de 3.3V do ESP32.
   - **GND**: conectar ao GND do ESP32.
   - **DATA**: conectar ao pino GPIO 2 do ESP32, com um resistor de 10kΩ entre o pino DATA e o VCC para atuar como pull-up.

2. **Conexão do Módulo Relé**:
   - **VCC**: conectar ao pino de 5V do ESP32.
   - **GND**: conectar ao GND do ESP32.
   - **IN**: conectar ao pino GPIO 4 do ESP32.

3. **Ligação do Umidificador ao Relé**:
   - **Corte o fio de alimentação do umidificador** e conecte uma extremidade ao terminal **COM** (comum) do relé.
   - **Conecte a outra extremidade** ao terminal **NO** (normalmente aberto) do relé.
   - **Atenção**: Certifique-se de que o umidificador está desconectado da tomada durante esta operação e que as conexões estão devidamente isoladas para evitar riscos elétricos.

## Configuração do Ambiente de Desenvolvimento

1. **Instalação da Biblioteca do Sensor DHT**:
   - Abra a **Arduino IDE**.
   - Vá em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**.
   - No campo de busca, digite **"DHT sensor library"**.
   - Instale a biblioteca desenvolvida por Adafruit.

2. **Instalação da Biblioteca Adafruit Unified Sensor**:
   - Ainda no Gerenciador de Bibliotecas, procure por **"Adafruit Unified Sensor"**.
   - Instale esta biblioteca necessária para o funcionamento da biblioteca DHT.

3. **Configuração da Placa ESP32 na Arduino IDE**:
   - Vá em **Arquivo > Preferências**.
   - No campo **URLs adicionais para Gerenciadores de Placas**, adicione:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Vá em **Ferramentas > Placa > Gerenciador de Placas**.
   - Procure por **ESP32** e instale o pacote fornecido pela **Espressif Systems**.

## Observações Importantes

- **Segurança Elétrica**: Ao trabalhar com tensões da rede elétrica, tome todas as precauções necessárias para evitar choques elétricos. Se não tiver experiência com circuitos de alta tensão, procure auxílio de um profissional qualificado.
- **Alimentação do Relé**: Alguns módulos relé operam com 5V, enquanto o ESP32 funciona com 3.3V nos seus pinos de saída. Certifique-se de que o módulo relé escolhido é compatível com os níveis lógicos do ESP32 ou utilize um circuito de adaptação de nível lógico, se necessário.
- **Personalização**: Você pode ajustar o valor da variável `humidityGoal` para definir a umidade desejada conforme suas necessidades.
