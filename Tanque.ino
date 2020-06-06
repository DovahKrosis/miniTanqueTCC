// TCC ELETRÔNICA 2020 A.G.R 
// Guilherme Gil
// Luan
// Victor
// Raphael
//==================================================================================================


//Sensor ultrassom funciona com 5v
//Servo motor funciona com 5v


#include <Ultrasonic.h> //Carrega a biblioteca do sensor ultrassonico
#include <Servo.h>      //Carrega a biblioteca do servo motor


//Definição dos pinos para o trigger e echo ( ultrassom )
#define pino_trigger 4
#define pino_echo 3


// Porta Digital 5 PWM ( Servo )
#define SERVO 5 


Servo s; // Variável Servo
int pos; // Posição Servo

// Variaveis globais

//float cmMsec;
//long microsec;
 
//Inicializa o sensor ( Ultrassom ) nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//==================================================================================================



void setup()
   {
     pinMode( 8, OUTPUT );
     s.attach(SERVO);
     Serial.begin(9600);
     s.write(0); // Inicia o servo motor na posição zero
     delay(1000);
     Serial.println("Lendo dados do sensor..."); // Ultrassom
    }


 //==================================================================================================

void retornar(){
  //TODO: implementar funcao de retorno
}

void colisao(float cmMsec, long microsec){
  while ( cmMsec <= 10 )
      {
        digitalWrite( 8, HIGH );
        microsec = ultrasonic.timing();
        cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
        Serial.print("Distancia em cm: ");  
        Serial.println(cmMsec);
        delay(1000);
        retornar();              
       }
       digitalWrite( 8, LOW );
}
 
void loop()

{
  
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(1000);

   for(pos = 50; pos < 150; pos = pos + 50) // O servo inicia na posição 50 e soma 50 até atingir 150; a cada soma ele realiza uma leitura no sensor
  {
      
      s.write(pos); // escreve a posição para o servo usando a variável "pos"
        
      float cmMsec;
  
      long microsec = ultrasonic.timing();
  
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
      Serial.print("Distancia em cm: ");
  
      Serial.println(cmMsec);
  
      delay(1000);

      colisao(cmMsec, microsec);
   
  }

  for(pos = 150; pos >= 50; pos = pos - 50) // O servo inicia na posição 150 e subtrai 50 até atingir 50; a cada subtração ele realiza uma leitura no sensor
  {
    
     s.write(pos); // escreve a posição para o servo usando a variável "pos"

     delay(500);
    
     float cmMsec;
   
     long microsec = ultrasonic.timing();
  
     cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
     Serial.print("Distancia em cm: ");
  
     Serial.println(cmMsec);
  
     delay(500);

     colisao(cmMsec, microsec);
  
  }
}
