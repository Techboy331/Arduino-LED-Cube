/* Arduino LED Cube Code
 - By Chris P.
 
 Begun on 7/10/12
 
 */

//Declarations/Defines
int x;
int y;
//Cathodes
#define C1 2 //Cathode layer 1
#define C2 3 //Cathode layer 2
#define C3 4 //Cathode layer 3
#define C4 5 //Cathode layer 4
//Anodes
#define A1 23 //first anode column, noted in my sketches as the upper left corner
#define A2 24
#define A3 25
#define A4 26
#define A5 27
#define A6 28
#define A7 29
#define A8 30
#define A9 31
#define A10 32
#define A11 33
#define A12 34
#define A13 35
#define A14 36
#define A15 37
#define A16 38

void setup(){
  //Cathodes
  pinMode (C1,OUTPUT);
  pinMode (C2,OUTPUT);
  pinMode (C3,OUTPUT);
  pinMode (C4,OUTPUT);
  //Anodes
  pinMode (A1,OUTPUT);
  pinMode (A2,OUTPUT);
  pinMode (A3,OUTPUT);
  pinMode (A4,OUTPUT);
  pinMode (A5,OUTPUT);
  pinMode (A6,OUTPUT);
  pinMode (A7,OUTPUT);
  pinMode (A8,OUTPUT);
  pinMode (A9,OUTPUT);
  pinMode (A10,OUTPUT);
  pinMode (A11,OUTPUT);
  pinMode (A12,OUTPUT);
  pinMode (A13,OUTPUT);
  pinMode (A14,OUTPUT);
  pinMode (A15,OUTPUT);
  pinMode (A16,OUTPUT);


}
void test(){
  //toggles the Cathodes
  for (int i=2; i<=5; i++){
    digitalWrite (i,HIGH);
    //toggles the anodes
    for(int j=23; j<=38; j++){
      digitalWrite (j,HIGH);
      delay(50);
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
void loop(){
  for(int i=0; i<=4; i++){
    square();
  }
  for(int j=0; j<=1; j++){
    test();
  }
}


