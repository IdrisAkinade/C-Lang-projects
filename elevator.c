// Elevator 
// Written by Idris Akinade
// Last updated 14-12-2018
//
#include <SoftwareSerial.h>

int i=1; // the value represents where elevator stay ( first time elevator start in the first floor
int btn4=5; // represents the 4th floor
int btn3=4; // 3rd floor
int btn2=3; // 2nd floor
int btn1=2; // 1st floor

int buttonState1=0;
int buttonState2=0;
int buttonState3=0;
int buttonState4=0;

int motorPin1 = 11;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 6;

int step_delay = 20; // 20ms, i.e. 50 steps per second

const int latchPin = 2; // Pin connected to Pin 12 of 74HC595 (Latch)
const int dataPin = 3; // Pin connected to Pin 14 of 74HC595 (Data)
const int clockPin = 7; // Pin connected to Pin 11 of 74HC595 (Clock)

const byte numbers[16] = {
0b11111100,
0b01100000,
0b11011010,
0b11110010,
0b01100110,
0b10110110,
0b10111110,
0b11100000,
0b11111110,
0b11100110,
0b11101110,
0b00111110,
0b10011100,
0b01111010,
0b10011110,
0b10001110
};

void setup()
{
int delayTime = 50;

pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);

pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

pinMode(btn4, INPUT);
pinMode(btn2, INPUT);
pinMode(btn3, INPUT);
pinMode(btn1, INPUT);

Serial.begin(9600);
}

// up function which moves the elevator up 1 floor
void up()
{
show(numbers[i]);
for(int a=0 ; a<150 ; a++)
{
motor_pins(0, 0, 0, 1);
delay(step_delay);
motor_pins(0, 0, 1, 0);
delay(step_delay);
motor_pins(0, 1, 0, 0);
delay(step_delay);
motor_pins(1, 0, 0, 0);
delay(step_delay);
}
}

// down function which moves the elevator down 1 floor
void down()
{
show(numbers[i]);
for(int a=0 ; a<150 ; a++)
{
motor_pins(1, 0, 0, 0);
delay(step_delay);
motor_pins(0, 1, 0, 0);
delay(step_delay);
motor_pins(0, 0, 1, 0);
delay(step_delay);
motor_pins(0, 0, 0, 1);
delay(step_delay);
}
}

void show(byte number)
{
for (int j=0 ; j<=7 ; j++)
{
byte toWrite = number & (0b10000000 >> j);
if (!toWrite)
{
continue;
}

// Otherwise shift it into the register
shiftIt(toWrite);
}
}

void shiftIt (byte data)
{
// Set latchPin LOW while clocking these 8 bits in to the register
digitalWrite(latchPin, LOW);

for (int k=0; k <= 7; k++)
{
// clockPin LOW prior to sending a bit
digitalWrite(clockPin, LOW);

if ( data & (1 << k) )
{
digitalWrite(dataPin, LOW); // turn â€œOnâ€
}
else
{
digitalWrite(dataPin, HIGH); // turn â€œOffâ€
}

// and clock the bit in
digitalWrite(clockPin, HIGH);
}

//stop shifting out data
digitalWrite(clockPin, LOW);

//set latchPin to high to lock and send data
digitalWrite(latchPin, HIGH);
delay(100);
}

void motor_pins(int a, int b, int c, int d)
{
digitalWrite(motorPin1, a);
digitalWrite(motorPin2, b);
digitalWrite(motorPin3, c);
digitalWrite(motorPin4, d);
}
void loop()
{
buttonState1 = digitalRead(btn1);
buttonState2 = digitalRead(btn2);
buttonState3 = digitalRead(btn3);
buttonState4 = digitalRead(btn4);
show(numbers[i]); //write number on the 7 segment display which floor elevator stays

// start of 4th floor code
if(buttonState4 == HIGH)
{
while(i<4)
{
i++;
up();
Serial.print(“You are on the “);
Serial.println(i);
Serial.println(“floor”);
show(numbers[i]);
}
i=4;
show(numbers[i]);
}
// end of 4th floor code

// start of 3rd floor code
if(buttonState3 == HIGH)
{
if(i>3)
{
while(i>3)
{
i–;
down();
Serial.print(“You are on the “);
Serial.println(i);
Serial.println(“floor”);
show(numbers[i]);
}
}
if(i<3)
{
// person is waiting on the first or second floor. Call the elevator
while(i<3)
{
i++;
up();
Serial.print("You are on the");
Serial.println(i);
Serial.println("floor");
show(numbers[i]);
}
}
i=3; //assign the elevator value to the three
show(numbers[i]);
delay(1000);
}
// end of 3rd floor code

// start of 2nd floor code
if(buttonState2 == HIGH)
{
if(i>2)
{
while(i>2)
{
i–;
down();
Serial.print("You are on the");
Serial.println(i);
Serial.println("floor");
show(numbers[i]);
}
i=2;
}
if(i<2)
{
while(i<2)
{
i++;
up();
Serial.print("You are on the");
Serial.println(i);
Serial.println("floor");
show(numbers[i]);
}
i=2;
show(numbers[i]);
delay(1000);
}
}
// end of 2nd floor code

// start of 1st floor code
if (buttonState1 == HIGH)
{
if (i>1)
{
while (i>1)
{
i–;
down();
Serial.print("You are on the");
Serial.print(i);
Serial.println("floor"););
show(numbers[i]);

}
}
i=1;
show(numbers[i]);
delay(1000);
}
// end of 1st floor code
}
