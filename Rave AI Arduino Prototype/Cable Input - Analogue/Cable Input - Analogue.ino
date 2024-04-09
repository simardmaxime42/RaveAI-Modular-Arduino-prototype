// pin===================================================

//cable

int analogPin0 = A0; 
int analogPin1 = A1; 
int analogPin2 = A2; 
int analogPin3 = A3; 

//potentiometre

int analogPin4 = A4;
int analogPin5 = A5; 



// Variable Analogue===============================

//Cables
int sensorValue0 = 0; 
int sensorValue1 = 0; 
int sensorValue2 = 0; 
int sensorValue3 = 0; 

//potentiometre

int sensorValue4 = 0;
int sensorValue5 = 0;

//Treshold de voltage ==================================================

float input0VoltTresh = 5.00;
float input1VoltTresh = 3.40;
float input2VoltTresh = 1.67;
float input3VoltTresh = 0.00;



// Input de cable actifs=====================================
int input0;
int input1;
int input2;
int input3;



/*====================================================
Code
======================================================*/



void setup() {
  Serial.begin(9600);

}

void loop() {
  
  //cables
  sensorValue0 = analogRead(analogPin0);
  sensorValue1 = analogRead(analogPin1); 
  sensorValue2 = analogRead(analogPin2);
  sensorValue3 = analogRead(analogPin3);

  //potentio
  sensorValue4 = analogRead(analogPin4);
  sensorValue5 = analogRead(analogPin5);

  Serial.println(sensorValue5);
  

  
  // Variable de voltage
  
  float voltage0value = sensorValue0 * (5.0 / 1023.0); 
  float voltage1value = sensorValue1 * (5.0 / 1023.0); 
  float voltage2value = sensorValue2 * (5.0 / 1023.0); 
  float voltage3value = sensorValue3 * (5.0 / 1023.0); 



//==========================================
//            VOLTAGE MATCH CHECK
//==========================================



    if (voltage0value <= input0VoltTresh && voltage0value > input1VoltTresh){
        input0 = 1;
        //Serial.println("input0");

    }

    if (voltage1value <= input1VoltTresh && voltage1value > input2VoltTresh){
        input1 = 1;
        //Serial.println("input1");

    }

    if (voltage2value >= input2VoltTresh -0.05 && voltage2value <= 3){
        input2 = 1;
        //Serial.println("input2");


    }

    if (voltage3value == input3VoltTresh){
        input3 = 1;
        //Serial.println("input3");

        
         // Serial.println(voltage3value);

    }


/* ================================================================
                    OUT
====================================================================*/

  //Serial.println(input0);
  //Serial.println(input1);
  //Serial.println(input2);
  //Serial.println(input3);



  delay(500);




}




