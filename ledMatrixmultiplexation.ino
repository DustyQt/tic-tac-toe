unsigned long previousMillis=0;

const long interval=500;
int grounds[] ={14,15,16,17,18};
int greens []= {1,3,5,7,9};
int reds []= {0,2,4,6,8};
/*
 * Testing code
  unsigned long previousMillis=0;
  const long interval=500;
int matrix[5][5]={
  {1,0,2,0,0},
  {0,2,0,1,0},
  {0,0,0,1,2},
  {1,0,2,0,0},
  {0,2,0,0,2}
};*/

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<10;i++){
    pinMode(i,OUTPUT);    
  }
  for(int i=14;i<19;i++){
    pinMode(i,OUTPUT);    
  }
  /* Testing Code
  randomSeed(analogRead(0));*/
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Testing Code
  unsigned long currentMillis=millis();
  if(currentMillis-previousMillis >=interval){
    previousMillis=currentMillis;
    for(int k=0;k<5;k++){
      for(int l=0;l<5;l++){
        matrix[k][l]=random(0,3);  
      }
    }
  }
  matrixDisplay(matrix);
  */
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
