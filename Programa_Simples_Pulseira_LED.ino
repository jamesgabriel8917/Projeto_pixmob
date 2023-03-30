/**********************************************************************************
 * **       PROGRAMA SIMPLES PARA CONTROLE DE PULSEIRA LED
 * ********************************************************************************/
#include <Arduino.h>      // Carrega Bibliotecas 
#include <IRremote.hpp>

// Variáveis do programa
const uint16_t pin_IR_LED = 4; // numero do pino para ligar o transmissor IR
int tamanho;  // variavel para guardar o numero de bytes referente a cor enviada para a pulseira, nessesário para a função IRSender

// Código de Cores que será enviado para a pulseira
uint16_t   vermelho[] = {
           1400, 1400, 700, 700, 700, 1400, 700, 2800, 700, 2800, 700, 700, 700, 700, 700, 1400, 1400, 2800, 1400, 2800, 700};
uint16_t   verde[]    = {
           700, 700, 700, 700, 1400, 1400, 1400, 2800, 700, 1400, 700, 1400, 700, 1400, 700, 2100, 1400, 2100, 1400, 2800, 700};
uint16_t   azul[]     = {
           700, 700, 700, 2100, 1400, 1400, 700, 2100, 700, 1400, 700, 700, 700, 1400, 1400, 700, 700, 1400, 700, 700, 700, 700, 700, 700, 700, 2100, 700};

void setup() { // ajusta as configuraçãoes iniciais
  IrSender.begin(pin_IR_LED); // Inicializa o pino do Arduino que enviará os dados
  IrSender.enableIROut(38);   // Define a frequencia da portadora do sinal IR
} // fim das configuraçoes iniciais

void loop() { // loop de execução do programa principal
    
  tamanho = sizeof vermelho / sizeof *vermelho; // conta quantos bytes serão enviados da cor vermelha 
  for(int i=0; i<=2; i=i+1)  { IrSender.sendRaw(vermelho, tamanho, 38);    // envia os dados para o tranmissor IR
      delay(250); } // Pausa 500 mili segundos
 

} // retorna para repetir o programa, loop.
