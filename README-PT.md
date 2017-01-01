#7-Segments-Clock

##A Proposta

Esse é um projeto de um display de 7 segmentos, desenvolvido do zero, usando hardware e software autorais. :) </br>
O relógio marca **horas, minutos e segundos, usando um microcontrolador ATMEGA328P, desenvolvido pela ATMEL. </br>
O 7 Segments Clock foi desenvolvido como um projeto pessoal e foi construído em uma placa universal, de acordo com os esquemas da pasta Proteus, dentro deste projeto. Durante este README vou explicar como desenvolver o seu próprio Relógio de 7 segmentos. :)
	
*Aqui está uma imagem sobre o resultado final do projeto:*

![Imgur](http://i.imgur.com/BjCu3v1.jpg) 

##Utilidade

O código foi desenvolvido especificamente para o microcontrolador ATMEGA328P, usando a IDE ATMEL Studio. No entanto, se algumas alterações forem feitas, principalmente na inicialização, configuração e alguns registradores, o projeto pode ser adaptado para outras famílias de microcontroladores, de outros fabricantes** e IDEs. A ideia de construir um Relógio 7 Segmentos é a mesma, mas algumas coisas vão mudar, como registradores, timer, I/Os e ADCs.

##Como funciona?

O relógio começa a marcar o tempo a partir das 00:00, no momento em que está ligado. **Para ajustar o tempo até a hora e o minuto desejados, é necessário usar os push buttons do circuito (no lado direito do microcontrolador)**. Temos dois botões, um para incrementar horas e outro para incrementar minutos.

**O algoritmo desenvolvido marca horas, minutos e segundos, mas foi construído apenas com 4 Displays, configurado para marcar horas e minutos. No entanto, se você quiser construir um relógio completo (usando marcadores de segundos também), é necessário apenas adicionar mais dois displays 7 segmentos e conectá-lo em 2 portas do microcontrolador não utilizadas.**

**O código foi desenvolvido com a lógica do relógio completa, mas quando eu gravo no microcontrolador, comento um dos marcadores (segundos, por exemplo - função "CalculateSeconds") e assim, marca horas + minutos. Por outro lado, se eu quiser ver Minutos + Segundos você precisa comentar a função "CalculateHours" e exibirá Minutos + Segundos.**

No momento em que o circuito é **desenergizado**, o relógio **perde sua referência** e o tempo atual porque ele não tem um hardware de memória implementado no circuito.

No entanto, se você precisar armazenar o **último tempo marcado, mesmo com o circuito desenergizado, você pode usar um hardware RTC e só ler suas variáveis ​​de tempo, e exibí-los no display de 7 Segmentos**. De outra forma, de acordo com o que eu disse durante o projeto Binary Clock (aqui em github.com/hollweg/binary-clock), eu acho que esse tipo de "upgrade" não é interessante para este tipo de projeto, justamente porque faz **você perder o essência de construir um relógio real, pensar na lógica do relógio, contadores, temporizadores, até otimização de software e implementação.**

Tipos de arquivos encontrados no projeto:

*- O arquivo .c contém o código desenvolvido, em C.* </br>
*- O arquivo .asm contém o código traduzido para Assembly.* </br>
*- O arquivo .hex é o arquivo pronto para ser gravado, contendo o código em linguagem hexadecimal.* </br>
*- Os outros arquivos são arquivos de configuração, criados pelo compilador.* </br>
*- Dentro da pasta /Proteus está o esquemático do projeto.* </br>

*Abaixo, está a imagem do hardware do projeto

![Imgur](http://i.imgur.com/T5LGVun.png)

Você pode acessar os arquivos de hardware na pasta /Proteus.

##Usando 4 displays de 7 Segmentos

Você pode ver no resultado final do projeto que foi usado um **array de 7 Segmentos** (modelo CAI5461AH), **já multiplexado e fácil de ser usado.**

No entanto, você pode usar o mesmo código **através de 4 Displays de 7 Segmentos.** </br>
Antes de usar o Array de 7 Segmentos, hardware e software foram testados em uma protobard com quatro displays de 7 segmentos. </br>
A única diferença é que **você precisa multiplexar os pinos manualmente e conectar um resistor entre a porta do microcontrolador e o pino de controle em cada display** (há 2 pinos de controle (compartilhados) por display). </br>
**Por outro lado, usando o array não é necessário conectar os resistores porque eles já são considerados no circuito do array.**

*Abaixo, está uma imagem do esquemático de um único display de 7 Segmentos:*

![Imgur](http://i.imgur.com/6OF4lW5.gif)

![Imgur](http://i.imgur.com/uOHj8T3.gif)

*Aqui você pode ver quatro Displays de 7 Segmentos multiplexados em um .gif:*

[Imgur](http://i.imgur.com/3Io3QAH.gifv)

**Na imagem se pode notar que foram usados transistores para habilitar cada pino de controle do display, mas isso não é necessário.** </br>
Eu desenvolvi o **sistema de chaveamento do controle de displays por software.** Cada vez que um display é habilitado (5V - catodo comum), o microcontrolador manda para os outros sinais de controle dos displays 0V, garantindo que nós teremos apenas um display ativo a cada momento. </br>
Esse sinal de controle é habilitado por um curto período de tempo, muito rápido, então habilita-se outro display, compartilhando o barramento entre os 4 displays de 7 segmentos. Então, como os displays são habilitados centenas de vezes por segundo, nossos olhos tem a impressão que todos os 4 displays estão ativos simultaneamente, o que não é verdade.

*Aqui está uma imagem do circuito usando quatro Displays de 7 Segmentos (o código usando para o array e para os displays separados é exatamente o mesmo):**

![Imgur](http://i.imgur.com/Zn7HhOp.jpg)

Não é necessário montar o hardware em uma plaquinha para ver seu projeto funcionando. </br>
**Se você quer fazer o projeto rodar usando uma placa do Arduino UNO** (ou alguma outra placa da Arduino que use o microcontrolador ATMEGA328P) **você precisa gravaro código no ATMEGA328P via ATMEL Studio** (você pode ver <a href="https://www.embarcados.com.br/atmel-studio/">nesse link aqui</a> como configurar o Atmel Studio para gravar os códigos em plataformas Arduino) **e conectar o display e os botões diretamente nas I/Os da placa do Arduino.**
	
**Abaixo, eu descrevi as conexões de hardware para facilitar a construlão do projeto. Dê uma olhada :)**

**7 Segments LEDs:**

Segmento a - ATMEGA328P PD2 - Arduino Uno pino Digital 2 </br>
Segmento b - ATMEGA328P PD3 - Arduino Uno pino Digital 3 </br>
Segmento c - ATMEGA328P PD4 - Arduino Uno pino Digital 4 </br>
Segmento d - ATMEGA328P PD5 - Arduino Uno pino Digital 5 </br>
Segmento e - ATMEGA328P PD6 - Arduino Uno pino Digital 6 </br>
Segmento f - ATMEGA328P PD7 - Arduino Uno pino Digital 7 </br>
Segmento g - ATMEGA328P PB0 - Arduino Uno pino Digital 8 </br>
Sinal de Controle do display de Minutos (direita) - ATMEGA328P PB2 - Arduino Uno pino Digital 10 </br>
Sinal de Controle do display de Minutos (esquerda) - ATMEGA328P PB3 - Arduino Uno pino Digital 11 </br>
Sinal de Controle do display de Horas (direita) - ATMEGA328P PB4 - Arduino Uno pino Digital 12 </br>
Sinal de Controle do display de Horas (esquerda) - ATMEGA328P PB5 - Arduino Uno pino Digital 13 </br>

**Push Buttons:**

Reset - ATMEGA328P PC6 - Arduino UNO pino Reset  </br>
Incremento de minutos - ATMEGA328P PC1 - Arduino UNO Entrada Analógica 1 (cuidado: Pino de entrada 1, não pino 0) </br>
Incremento de horas - ATMEGA328P PC2 - Arduino UNO Entrada Analógica 2 </br>

**Obs.1**: Se você usar quatro Displays de 7 segmentos, todos os 7 LEDs devem ser multiplexados. </br>
**Obs.2**: Se você usar quatro Displays de 7 segmentos, cada display precisa de seu próprio resistor de entrada (~~270 ohms --- ~~1k ohms). </br>
Além disso, os pinos de controle devem ser conectados em seus dois pinos COM. </br>
**Obs.3**: Cuidado com o tipo de displays de 7 Segments que você estiver usando! </br>
Existem dois tipos diferentes: Anodo Comum e Catodo Comum </br>
Catodo Comum tem seus pinos de controle ON usando nível lógico alto (5V). </br>
Anodo Comum tem seus pinos de controle ON usando nível lógico baixo (0V). </br>

##O que foi usado neste projeto?

**Lista de materiais**:

1. 1 x microcontrolador ATMEGA328P <br>
2. 1 x header de 28 pinos </br>
3. 3 x Push button </br>
4. 3 x Resistor 1k ohm (+4 if you use four 7 Segments Display) </br>
5. 1 x Cristal de 16MHz  </br>
6. 2 x Capacitores de 22pF </br>
7. 1 x Capacitores de 100nF </br>
8. 1 x Array 7 Segments Display </br>
9. 1 x Jack P4 fêmea </br>
10. 1 x Placa universal 10x5cm </br>

##Tensão de alimentação do circuito

O circuito desenvolvido é energizado com 5V. </br>
Você pode adaptar uma simples bateria de 9V + regulador de tensão 7805, ou então conectá-lo diretamente a uma fonte de alimentação de um smartphone, com um jack P4.

**Como fazer?**

**Passo 1:** Pegue uma fonte de alimentação de 5V e corte o cabo USB (assumindo que ele não tenha na extremidade um Jack P4), deixando apenas 2 pinos disponíveis: VCC e GND (os únicos que você precisa). </br>
**Passo 2:** Conecte VCC e GND diretamente dentro do jack P4 (seja cuidado com a polaridade).

Sua fonte de alimentação está pronta! :) </br>

*Abaixo, segue uma imagem da fonte de alimentação que eu usei no projeto:*

![Imgur](http://i.imgur.com/477PfSB.jpg) </br>

*Finalmente, aí está uma imagem do circuito funcionando perfeitamente.:*

![Imgur](http://i.imgur.com/myghT7r.jpg)

##Copyrigths

**O projeto pode ser reproduzido sem problemas.** </br>
No entanto, eu somente peço que **mantenha os créditos ao autor.** :)


Enjoy!

**Hollweg**

