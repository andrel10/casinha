<h1>Casa Inteligente Arduino</h1> 

<p align="center">
  <img src="[(https://content.arduino.cc/assets/arduino_logo_1200x630-01.png)]"/>
  <img src="https://img.shields.io/static/v1?label=Netlify&message=deploy&color=blue&style=for-the-badge&logo=netlify"/>
  <img src="http://img.shields.io/static/v1?label=License&message=MIT&color=green&style=for-the-badge"/>
  <img src="http://img.shields.io/static/v1?label=Ruby&message=2.6.3&color=red&style=for-the-badge&logo=ruby"/>
  <img src="http://img.shields.io/static/v1?label=Ruby%20On%20Rails%20&message=6.0.2.2&color=red&style=for-the-badge&logo=ruby"/>
   <img src="http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=GREEN&style=for-the-badge"/>
</p>

> Status do Projeto: Concluído!

### Tópicos 

:small_blue_diamond: [Descrição do projeto](#descrição-do-projeto)

:small_blue_diamond: [Funcionalidades](#funcionalidades)

:small_blue_diamond: [Deploy da Aplicação](#deploy-da-aplicação-dash)

:small_blue_diamond: [Pré-requisitos](#pré-requisitos)

:small_blue_diamond: [Como rodar a aplicação](#como-rodar-a-aplicação-arrow_forward)



## Descrição do projeto 

<p align="justify">
  Trabalho desenvolvido pelos alunos do IFSC campus São Lourenço do Oeste, consiste na utilização do Arduino Uno via Ethernet W5500.  
</p>

## Funcionalidades

:heavy_check_mark: Enviar comandos via Ethernet 

:heavy_check_mark: Ligar e desligar led via Ethernet  

:heavy_check_mark: Desligar o alarme via Ethernet 

:heavy_check_mark: Aumentar e diminuir a intensidade da iluminação

:heavy_check_mark: Possui sensor de preseça no alarme

## Layout ou Deploy da Aplicação :dash:

imagens

## Pré-requisitos

:warning: 

É necessária a instalação das bibliotecas do Arduino: 
SPI.h
Ethernet.h

## Como rodar a aplicação :arrow_forward:

No terminal, clone o projeto: 

```
git clone https://github.com/andrel10/casinha/tree/b5a14bae431257816c70e4fd1085136ff70b58c8
```

... 

Passo a Passo:
Monte o projeto físico conforme as fotos acima, em seguida faça o upload do código para o Arduino.
A interface web está configurada para ser exibida ao digitar o endereço 192.168.1.200. Certifique-se que seu computador ou dispositivo esteja conectado nessa mesma rede.

## JSON :floppy_disk:

Os seguintes comandos são aceitos via navegador:

Ligar luz azul:
http://192.168.1.200/?LuzAzul

Ligar luz vermelha:
http://192.168.1.200/?LuzVermelho

Ligar luz verde:
http://192.168.1.200/?LuzVerde

Aumentar intensidade da luz:
http://192.168.1.200/?maisLuz

Diminuir intensidade da luz:
http://192.168.1.200/?menosLuz

Ligar luz:
http://192.168.1.200/?ligarLuz

Apagar luz:
http://192.168.1.200/?apagarLuz

Ativar Alarme:
http://192.168.1.200/?ativarAlarme

Desativar Alarme:
http://192.168.1.200/?desarmarAlarme




## Linguagens, dependencias e libs utilizadas :books:

- [C++](https://cplusplus.com/)

...


## Desenvolvedores/Contribuintes :octocat:

Liste o time responsável pelo desenvolvimento do projeto

|[<sub>Anderson Besbatti</sub>](https://github.com/andersonbesbatti) |
|[<sub>André Follmann</sub>](https://github.com/andrel10) |
|[<sub>Carlos Ely Leite Junior</sub>](https://github.com/carlos059) |
|[<sub>Fabiano Borges Amaral</sub>](https://github.com/fabianoborgesamaral) |
|[<sub>Marianne Pissaia</sub>](https://github.com/mariannepissaia) |

## Licença 

The [MIT License]() (MIT)

Copyright :copyright: Ano - Titulo do Projeto
