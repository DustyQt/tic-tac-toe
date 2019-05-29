#include <stdio.h>
#include <string.h>
unsigned long previousMillis=0;
int i=0;
int k=0;
const long interval=500;
int grounds[] ={14,15,16,17,18};
int greens []= {11,9,7,5,3};
int reds []= {10,8,6,4,2};
bool started = false;
bool ended = true;
/*
 * Testing code
  unsigned long previousMillis=0;
  const long interval=500;
  */
int matrix[5][5]={
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,2}
};

void setup() {
  
  // put your setup code here, to run once:
  for(int i=2;i<12;i++){
    pinMode(i,OUTPUT);    
  }
  for(int i=14;i<19;i++){
    pinMode(i,OUTPUT);    
  }
  Serial.begin(60000);
}

void loop() {
  // put your main code here, to run repeatedly:
  i=0;
  k=0;

   while(Serial.available() > 0){
   char incomingByte = Serial.read();
   if(incomingByte == '<')
   {
     started = true;
     ended = false;
   }
   else if(incomingByte == '>')
   {
     ended = true;
     break; // Break out of the while loop
   }
   else{    
         if(i>=5){
          k++;
          i=0;
        }
        int number = incomingByte- '0';
        Serial.print(number);
         matrix[i][k]= number;
         i++;
        
     
    }
  }
  matrixDisplay(matrix);
  
}
/** Display method, should be called constantly for the LEDmatrix to refresh correctly
 *  Takes a 5x5 int matrix with values {0,1,2} for {off,red,green} respectively
 *  
 */
void matrixDisplay(int matrix [5][5]){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      ledDisplay(i,j,matrix[i][j]);
    }
  }
}
/**
 * ledDisplay method, instead of taking the full amtrix just gives the row column and state and loads into the LED matrix its called by matrixDisplay method
 */
void ledDisplay(int row, int column,  int state){
  for(int i=0;i<5;i++){
    if(state ==0){
      for(int j=0;j<5;j++){
        digitalWrite(greens[j],LOW);
        digitalWrite(reds[j],LOW);
        digitalWrite(grounds[j],LOW);
      }
    }
    if(state==1){
      for(int j=0;j<5;j++){
        digitalWrite(greens[j],LOW);
        if(j==column){
          digitalWrite(reds[j],HIGH);
        }else{
          digitalWrite(reds[j],LOW);
        }
        if(j==row){
          digitalWrite(grounds[j],LOW);
        }else{
          digitalWrite(grounds[j],HIGH);
        }
         
      }
    }
    if(state==2){
      for(int j=0;j<5;j++){
        digitalWrite(reds[j],LOW);
        if(j==column){
          digitalWrite(greens[j],HIGH);
        }else{
          digitalWrite(greens[j],LOW);
        }
        if(j==row){
          digitalWrite(grounds[j],LOW);
        }else{
          digitalWrite(grounds[j],HIGH);
        }
         
      }
    }
  }
}