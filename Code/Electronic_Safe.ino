// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

#define buzzer 10
#define greenLed 11
#define redLed 12


//LCD
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//Keypad
const byte ROWS= 4; // 4 rows
const byte COLS= 3; // 3 columns

// Map the buttons to an array for the Keymap instance
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5};
byte colPins[COLS] = {4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


//servo
Servo myservo;  // create servo object to control a servo

//password
char truePassword[] = {"0000"};
int i = 0, count = 0, wrongEntery = 0, n = sizeof(truePassword)-1;
char password[sizeof(truePassword )-1];

void setup() {
  //rgb
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  digitalWrite(redLed,HIGH);
  //servo
  myservo.attach(13);  // attaches the servo on pin 13 to the servo object
  myservo.write(90);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("    Welcome!    ");
  lcd.setCursor(0, 1);
  lcd.print(" TO Our Project ");
  delay(2000);
  lcd.clear();
  lcd.print("Enter The Pass:");
  lcd.setCursor(0, 1);
}

void loop() 
{
  char button = customKeypad.getKey();
  
  if(button && button != '#')
  {
    lcd.print('*');
    password[i++] = button; //i is size of password array
    
    if(button == '*')reset();
  }
    
  else if(button == '#')
  {
    if(i == n) //n is size of truePassword array = 4
    {
      
      for(int j=0; j<n; j++)
      {
        if(password[j] == truePassword[j])
        count++; //count number of true input number
      }
        
      if(count == n)
      {
        lcd.clear();
        digitalWrite(greenLed,HIGH);
        digitalWrite(redLed,LOW);
        myservo.write(0);
        lcd.setCursor(0,0);
        lcd.print("CORRECT PASSWORD");
        delay(2000);
        
        //lock again
        lcd.setCursor(0, 0);
        lcd.print("Enter * To Lock:");
        while(1)
        {
          char button = customKeypad.getKey();
          if(button == '*')break;
        }
        wrongEntery = 0;//new begain
        reset();
      }else wrongPass(); //count != n
    }else wrongPass(); //i != n
  }
}

void wrongPass()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WRONG PASSWORD! ");
  delay(3000);
  
  wrongEntery++;
  if(wrongEntery == 3)callThePoliceThereIsAThief();
  
  reset();
}



void reset()
{
  count=0;
  i=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter The Pass: ");
  lcd.setCursor(0, 1);
  //lock again
  digitalWrite(greenLed,LOW);
  digitalWrite(redLed,HIGH);
  myservo.write(90);
}

void callThePoliceThereIsAThief()
{
  while(1)
  {  
    digitalWrite(redLed,LOW);
    delay(100);
    digitalWrite(redLed,HIGH);
    delay(100);
    tone(buzzer, 8200);
    lcd.setCursor(0,0);
    lcd.print("YOU CAN'T WRITE ");
    lcd.setCursor(0,1);
    lcd.print("PASSWORD AGAIN!");
  }
}
