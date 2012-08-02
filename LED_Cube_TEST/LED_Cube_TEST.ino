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
int Delay=1;
 int joyPlane[4][4] ={ 
  {23, 24, 25, 26  }
  , //[0][0] is 23, [0][2] is 31, [1][3] is 36, [3][3] is 38 etc... I hope...
  {27, 28, 29, 30  }
  , 
  {31, 32, 33, 34  }
  ,
  {35, 36, 37, 38  }
};

int animate[4][4][4] = {{{0,0,0,0,},{0,28,29,0,},{0,32,33,0,},{0,0,0,0,},},{{0,24,25,0,},{27,28,29,30,},{31,32,33,34,},{0,36,37,0,},},{{0,24,25,0,},{27,28,29,30,},{31,32,33,34,},{0,36,37,0,},},{{0,0,0,0,},{0,28,29,0,},{0,32,33,0,},{0,0,0,0,},}};int nextHead[4][4]={{23,24,25,26},{27,28,29,30},{31,32,33,34},{35,36,37,38}};
int nextLevel=3;
int animateNew[4][4][4];
int Direction=3;
int length=3;
int oldheads[3]={25,24,23};
int oldheadsCopy[3];
int oldLevels[3]={3,3,3};
int oldLevelsCopy[3];
int food=26/*random(23,39)*/;
int foodLevel=3 /*random(0,4)*/;

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
  pinMode(12,OUTPUT);
  
 //digitalWrite(layer,HIGH);
// digitalWrite(23,HIGH);
digitalWrite(13,LOW); 

  
}

void loop(){
snake();


//DO THIS FIRST
animation();

//THEN THIS
//joystick();
buttons(); 



 // test();

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

void animation(){
  //set the array in the paste area below 
  
int povArrayX=0; //these values are 0-3, but them together in the array produce the pin value
int povArrayY=0;
int povLayer=5;  


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
    /*if (millis() >20000){
      Delay++;
    }*/
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

void buttons(){
 // int layer=5;
  //DOWN BUTTON: MOVES LED/SNAKE DOWN  
  BI=digitalRead(8);
//Serial.println(BI);
  if(BI==0){
    //TURN CURRENT LAYER OFF
    Direction=4;
   /* delay(200);
    digitalWrite(layer,LOW);
    //CHANGE CURRENT LAYER
    if (layer!=2){
      layer--;
    }
    else{
      layer=5;
    }
    //TURN NEW LAYER ON
    digitalWrite(layer,HIGH);*/
  }
  //UP BUTTON: MOVES LED/SNAKE UP
  BII=digitalRead(9);
 // Serial.println(BII);
  if(BII==0){
    Direction=5;
   /* delay(200);
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
    digitalWrite(layer,HIGH);*/
  }
  
  //JOYSTICK BUTTON
  /*BIII=digitalRead(10);
  Serial.println(BIII);
  if(BIII==0){
    square();
  }*/
}

void snake(){
  //int length=2;
  // Jeremy was proposing that this array could have a max size rather than incrementing its maximum size over and over again
  int Y=analogRead(2);
  int X=analogRead(1);
  //Left=0, Right=1, Up=2, Down=3 
  
 
     //FIGURE OUT NEXT HEAD
   //only write oldest head to be low, while others should be set to high
    //Next head is based on the direction (X, Y, Z "momentum")
   

////////////INPUT\\\\\\\\\\\\\
if(X>712||X<388){
      //SETS IT LEFT
      if(X>712){
        Direction=0;
      }
      //SETS IT RIGHT
      if(X<388){
        Direction=1; 
      }       
  //  }
else if(Y>712||Y<388){
  //SETS IT UP
      if(Y>712){
        Direction=2;
      } 
 //SETS IT DOWN
      if(Y<388){
        Direction=3;
        }
}  
////////SET NEXT HEAD\\\\\\\\\  
 //LEFT
if (Direction==0){
 //Set next heads to be in that direction
  if(currentX!=0){
   currentX--;
  }
//WRAPS AROUND X AXIS
  else{
  currentX=3;
  }
}
  //RIGHT
else if(Direction==1){
  if(currentX!=3){
   currentX++;
  }       
//WRAPS AROUND X AXIS
  else{
  currentX=0;
  }
}
 //Forward
 else if (Direction==2){
   if(currentY!=0){
      currentY--;
    }
     //WRAPS AROUND Y AXIS
    else{
     currentY=3;
    }
 }
 //Backward
 else if (Direction==3){
  if(currentY!=3){
   currentY++;
   }
//WRAPS AROUND Y AXIS
  else{
  currentY=0;
  } 
} 
//UP
else if (Direction==4){
//move the head up 
if(nextLevel!=0){
nextLevel--;
}
else{
 nextLevel=3; 
}
}
//DOWN
else if (Direction==5){
//move the head up
if(nextLevel!=3){
nextLevel++;
}
else{
 nextLevel=0; 
} 
}

//DELETE OLDEST HEAD, WHILE SAVING RECENT HEADS
//figure out what the next head is, push most recent head to the old head matrix, get rid of the oldest head,
// the ones that should be lit are the old heads array, and the next head
  
  //REDECLARE OLDHEADS
 /* int proxyheads[length]
  for(int i=0; i<length; i++){
    
  }*/
  //int oldheads[length];
  //turn off the last LED, thus "deleting" it
 //Serial.println(oldheads[length-1],DEC);
 
 

  if(nextHead[currentX][currentY]==food && nextLevel == foodLevel){
   
   for(int i=sizeof(oldheads)-1; i>0; i--){
    oldheadsCopy[i]=oldheads[i];
    oldLevelsCopy[i]=oldLevels[i];
   } 
   length++; 
   
  delay(200); 
   int oldheads[length];
   int oldLevels[length];
  // Serial.print("line 439");
 
   for(int i=sizeof(oldheadsCopy)-1; i>0; i--){
     oldheads[i]=oldheadsCopy[i];
     oldLevels[i]=oldLevelsCopy[i];
      
 }
 // 
   
   
  // oldLevels[1]=oldLevels[length-2];
  // oldheads[1]=oldheads[0];
   int oldheadsCopy[length];
   int oldLevelsCopy[length];
  }
  else{
   digitalWrite(oldheads[length-1],LOW);
  }
 
  //Go through each index and push the value back an index
  //  Serial.print("line 459 "); 
  for(int i=length-1; i>0; i--){
  oldheads[i]=oldheads[i-1];
  oldLevels[i]=oldLevels[i-1];
  Serial.print(oldLevels[i-1]);
  Serial.print(",");
  }
  Serial.println(" ");
  // Serial.println(";");
  //set the first index to be the current position of the X/Y plane
  
  for(int i=0; i<=sizeof(oldheads); i++){
  if(nextHead[currentX][currentY] == oldheads[i]){
    Serial.println("GAME OVER!!!");
    //break;
  }
  }
  
  oldheads[0]=nextHead[currentX][currentY];
  //digitalWrite(oldheads[1],HIGH);
  //Serial.println(oldheads[1]);
  oldLevels[0]=nextLevel;
  // Serial.print("line 484 "); 
  //for(int i=length-1; i>0; i--){
  //Serial.print(nextLevel);
  //Serial.print(",");
 // }
 // Serial.println(" ");
 // Serial.println(oldheads[0]);
 /*Serial.print("X: ");
 Serial.println(currentX);
 Serial.print("Y: ");
 Serial.println(currentY);*/
  //digitalWrite(head[currentX][currentY],HIGH);
 /* for(int i=0; i<length; i++){
    digitalWrite(oldheads[i],HIGH);
  //  Serial.println(oldheads[i]);
  }*/
 
 //Empty the Animate Array
 for(int i=0; i<4; i++){
  for(int j=0; j<4; j++){
   for(int k=0; k<4; k++){
     animateNew[i][j][k]=0;
   }
  } 
 }
//delay(150);
//3D PUSH TO ANIMATE FUNCTION
delay(300);
for (int L=0; L<4; L++){
animation();
 for(int n=0; n< sizeof(oldLevels)-1; n++){
   if(oldLevels[n]==L){
     for(int x=0; x<4; x++){  
      for(int y=0; y<4; y++){
       if(oldheads[n]==(23+x+(4*y))){
         animateNew[L][x][y]=oldheads[n];
       }
      } 
     }
   }
   if(foodLevel==L){
      for(int x=0; x<4; x++){  
      for(int y=0; y<4; y++){
       if(food==(23+x+(4*y))){  
         animateNew[L][x][y]=food;
       }
      } 
     } 
   }
 }
}
//animation();
//delay(10);
for(int i=0; i<4; i++){
  for(int j=0; j<4; j++){
    for(int k=0; k<4; k++){
    animate[i][j][k]=animateNew[i][j][k];
   }
  }
}
//animation();
//delay(150);
/*
for(int i=0; i<4; i++){
  Serial.print("Layer: ");
   Serial.println(i);
 for(int j=0; j<4; j++){
   Serial.print("X value: ");
   Serial.println(j);
   for(int k=0; k<4; k++){
Serial.print(animate[i][j][k]);
Serial.print(",");
}
Serial.println(" ");
}
}
*/
//for(int i=0; i<=; i++){
//animation();
//}
//COLLISIONS
    //with self
  // if the new head is a value inside of the oldHeads array, then it's game over
    //with "food"
  // if the new head matches the value of the "food", then don't get rid of the oldest head, or add onto the head or tail or something...
    //increment length
}

void gameover(){
 square();

  for (int i=2; i<=5; i++){
    digitalWrite (i,HIGH);
    
    for(int j=23; j<=38; j++){
      digitalWrite (j,HIGH);
      delay(100);
      digitalWrite(j,LOW);
    } 
    digitalWrite (i,LOW);
  }
  
}






