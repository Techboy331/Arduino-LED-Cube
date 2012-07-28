/* Arduino LED Cube Code
 - By Chris P.
 
 Begun on 7/10/12
 
 FIGURE THIS OUT!!!
 */

//Declarations/Defines
boolean joyRunning=false;
int layer=5;
int currentX=0;
int currentY=0;
 int joyPlane[4][4] ={ 
  {23, 24, 25, 26  }
  , //[0][0] is 23, [0][2] is 31, [1][3] is 36, [3][3] is 38 etc... I hope...
  {27, 28, 29, 30  }
  , 
  {31, 32, 33, 34  }
  ,
  {35, 36, 37, 38  }
};
int BI;
int BII;
int BIII;

void setup(){
  Serial.begin(9600);
  //Cathodes
  pinMode (2,OUTPUT);//Layer1
  pinMode (3,OUTPUT);//Layer2
  pinMode (4,OUTPUT);//Layer3
  pinMode (5,OUTPUT);//Layer4
  //Anodes
  pinMode (23,OUTPUT);
  pinMode (24,OUTPUT);
  pinMode (25,OUTPUT);
  pinMode (26,OUTPUT);
  pinMode (27,OUTPUT);
  pinMode (28,OUTPUT);
  pinMode (29,OUTPUT);
  pinMode (30,OUTPUT);
  pinMode (31,OUTPUT);
  pinMode (32,OUTPUT);
  pinMode (33,OUTPUT);
  pinMode (34,OUTPUT);
  pinMode (35,OUTPUT);
  pinMode (36,OUTPUT);
  pinMode (37,OUTPUT);
  pinMode (38,OUTPUT);
  //Buttons
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  //Potentiometers
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  
  digitalWrite(layer,HIGH);
  digitalWrite(joyPlane[currentX][currentY],HIGH);

  
}

void loop(){
  joystick();
  buttons(); 
//  Serial.println(joyPlane[currentX][currentY]);*/
 // test();
//animation();

}

void test(){
  //toggles the Cathodes
  for (int i=2; i<=5; i++){
    digitalWrite (i,HIGH);
    //toggles the anodes
    for(int j=23; j<=38; j++){
      digitalWrite (j,HIGH);
      delay(100);
      digitalWrite(j,LOW);
    } 
    digitalWrite (i,LOW);
  }
}

void square(){
  for(int j=2; j<=5; j++){
    digitalWrite (j,LOW);
    for(int i=23; i<=38; i++){
      digitalWrite(i,HIGH);
    }
    digitalWrite (j,HIGH);
    delay(35);
    digitalWrite(j,LOW);
    for(int i=23; i<=38; i++){
      digitalWrite(i,LOW);
    }
  }
  for(int j=5; j>=2; j--){
    digitalWrite (j,LOW);
    for(int i=23; i<=38; i++){
      digitalWrite(i,HIGH);
    }
    digitalWrite (j,HIGH);
    delay(35);
    digitalWrite(j,LOW);
    for(int i=23; i<=38; i++){
      digitalWrite(i,LOW);
    }
  }
}


void buttons(){
 // int layer=5;
  //DOWN BUTTON: MOVES LED/SNAKE DOWN  
  BI=digitalRead(8);
  Serial.println(BI);
  if(BI==0){
    //TURN CURRENT LAYER OFF
    delay(200);
    digitalWrite(layer,LOW);
    //CHANGE CURRENT LAYER
    if (layer!=2){
      layer--;
    }
    else{
      layer=5;
    }
    //TURN NEW LAYER ON
    digitalWrite(layer,HIGH);
  }
  //UP BUTTON: MOVES LED/SNAKE UP
  BII=digitalRead(9);
  Serial.println(BII);
  if(BII==0){
    delay(200);
    //TURNS CURRENT LAYER OFF
    digitalWrite(layer,LOW);
    //CHANGE THE CURRENT LAYER
    if (layer!=5){
      layer++;
    }
    else{
      layer=2;
    }
    //TURN NEW LAYER ON
    digitalWrite(layer,HIGH);
  } 
  
  //JOYSTICK BUTTON
  BIII=digitalRead(10);
  Serial.println(BIII);
  if(BIII==0){
    square();
  }
}

void joystick(){
  //IF JOYSTICK MOVES OUT OF THRESHOLD
  int Y=analogRead(2);
  int X=analogRead(1);
 // int currentX=0;
  //int currentY=0;

 // if (joyRunning==false){
  
  //joyRunning=true;
  //}
  if((X>712||X<388) || (Y>712||Y<388)){
    //TURN THE CURRENT LED OFF
   digitalWrite(joyPlane[currentX][currentY],LOW);
    //THEN CHANGE THE currentX and currentY
    //X AXIS
    if(X>712||X<388){
      //MOVES IT LEFT
      if(X>712){
        if(currentX!=0){
          currentX--;
        }
        //WRAPS AROUND X AXIS
        else{
          currentX=3;
        }
      }
      //MOVES IT RIGHT
      if(X<388){
        if(currentX!=3){
          currentX++;
        }
        //WRAPS AROUND X AXIS
        else{
          currentX=0;
        }
      }       
    }
    //Y AXIS
    else if(Y>712||Y<388){
      //MOVES IT UP
      if(Y>712){
        if(currentY!=0){
          currentY--;
        }
        //WRAPS AROUND Y AXIS
        else{
          currentY=3;
        }
        //MOVES IT DOWN
      }
      if(Y<388){
        if(currentY!=3){
          currentY++;
        }
        //WRAPS AROUND Y AXIS
        else{
          currentY=0;
        }
      }
    }
    digitalWrite(joyPlane[currentX][currentY],HIGH);
    delay(400);
  }
  //OUTPUT TO SERIAL MONITOR (I SHOULD MAKE THIS LOOK PRETTIER) 
  /*delay(750);
   Y=analogRead(1);
   Serial.println(" ");
   Serial.println("Y: ");
   Serial.print(Y);
   Serial.println(" ");
   delay(750);
   X=analogRead(2);
   Serial.println("X: ");
   Serial.print(X);*/


}

void animation(){
  //set the array in the paste area below 
  
int povArrayX=0; //these values are 0-3, but them together in the array produce the pin value
int povArrayY=0;
int povLayer=2;  

int animate[4][4][4] = {
{{0, 0, 0, 0},
  {0, 28, 29, 0}, 
  {0, 32, 33, 0},
  {0 ,0, 0, 0},},

{{0, 24, 25, 0},
  {27, 28, 29, 30}, 
  {31, 32, 33, 34},
  {0 ,36, 37, 0},},
  
{{0, 24, 25, 0},
  {27, 28, 29, 30}, 
  {31, 32, 33, 34},
  {0 ,36, 37, 0},},
  
{{0, 0, 0, 0},
  {0, 28, 29, 0}, 
  {0, 32, 33, 0},
  {0 ,0, 0, 0},}, 
};
  //digitalWrite the leds that correspond to the array values for ONLY ONE LAYER!!! (at a time)
 
  for(int i=0; i<4; i++){//Z axis
    digitalWrite(povLayer,LOW);
     
    for(int j=0; j<=3; j++){//X axis
      //turn on values that aren't zero
     // Serial.println(j);
      
      for(int k=0; k<=3; k++){
      /*Serial.print("X :");
      Serial.println(povArrayX);*/
      if((animate[povLayer-2][k][j])!=0){
        digitalWrite(animate[povLayer-2][k][j],HIGH);
      }
      }
    }
    //POV
    digitalWrite(povLayer,HIGH);
   
    delay(1);
    //Turn everything off
    digitalWrite(povLayer,LOW);
    
    //go through the array and turn off any LEDs that are on
    for(int j=0; j<=3; j++){//X axis
      //turn on values that aren't zero
      for(int k=0; k<=3; k++){
      if((animate[povLayer-2][k][j])!=0){
        digitalWrite(animate[povLayer-2][k][j],LOW);
      }
      }
    }
    
    //Change the layer
    if(povLayer<5){
      povLayer++;//This will also change the array value
    }
    else{
      povLayer=2;  
    }
  }
}








