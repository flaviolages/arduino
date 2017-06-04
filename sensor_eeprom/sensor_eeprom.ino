#include <EEPROM.h>


byte led = 13;
byte sensor = 8;
byte cont = 0;
byte vezes = 0;
byte quantidade = 0;

byte value;


int addr = 0;


void setup(){
    
    Serial.begin(9600);
        
    pinMode(led, OUTPUT);
    pinMode(sensor, OUTPUT);
    
}


void loop(){
  
  int sts = digitalRead(sensor);
  delay(50);
 
   
 
 
   if(sts == LOW){
   
      digitalWrite(led, LOW);
         
   }else if(sts == HIGH){
   
      digitalWrite(led, HIGH);
      
          while(cont == 0){
            int sts = digitalRead(sensor);
            delay(50);
            digitalWrite(led, HIGH);
            
              if(sts == LOW){
                cont = 1;                                  
                Serial.write("Abriu: ");


 
                 // LEITURA E GRAVAÇAO
                 value = EEPROM.read(addr);
                 delay(500);
                 quantidade = value + 1;
                 delay(10);
                 EEPROM.write(addr, quantidade);
                 delay(500);
                 
                 
                 
                 // PRINT READ EEPROM
                 vezes = EEPROM.read(addr);
                 delay(500);
                 Serial.println(vezes, DEC);                
                 
                }  
          }
          
          cont = 0;
      
       
   }
 
 
 
 
 
 /*   
 if(sts == LOW){
      digitalWrite(led, LOW);
    }else{
      digitalWrite(led, HIGH);
      
      
        int i = 0;
        while(i == 0){
          
         int sts1 = digitalRead(sensor);
         delay(100);
         
         
          
        }
        
        
         if(sts1 == LOW){
          cont++;
          Serial.write("Abriu ");
          Serial.println(cont);
         }
        
    }

  
*/



}
