#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
char dataIn;
char cmdIn;
char cmd;


#define R1 9
#define R2 10 
#define R3 11 
#define R4 12
int a=0;
int b=0;
int c=0;
int d=0;
int i=0; 
int p; 

void setup() 
{
  lcd.begin(16,2);
    Serial.begin(9600);
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);
}

void loop() 
{
  if(i == 0)
  {
    lcd.print("HOME AUTOMATION");
    delay(2000);
    lcd.clear();
    lcd.setCursor(4,1);
    lcd.print("loading");
    for(p=11;p<16;p++)
    {
      lcd.setCursor(p,1);
      lcd.print(".");
      delay(2000);
    }
    lcd.clear();
    lcd.setCursor(0,0);
    set_stat();
    i=1;
  }
    cmd = check();

    if(cmd == '1')
    {
      R1_ON();
    }
    else if(cmd == '2')
    {
      R1_OFF();
    }
    else if(cmd == '3')
    {
      R2_ON();
    }
    else if(cmd == '4')
    {
      R2_OFF();
    }
    else if(cmd == '5')
    {
      R3_ON();
    }
    else if(cmd == '6')
    {
      R3_OFF();
    }
    else if(cmd == '7')
    {
      R4_ON();
    }
    else if(cmd == '8')
    {
      R4_OFF();
    }
    else if(cmd == '0')
    {
      R1_OFF();
      R2_OFF();
      R3_OFF();
      R4_OFF();
    }
    else if(cmd == '9')
    {
      R1_ON();
      R2_ON();
      R3_ON();
      R4_ON();
    }
}
int check()
{
  if (Serial.available() > 0)
  {
    dataIn = Serial.read();
      if (dataIn == '1'){cmdIn = '1';}
      else if (dataIn == '2'){cmdIn = '2';}
      else if (dataIn == '3'){cmdIn = '3';}
      else if (dataIn == '4'){cmdIn = '4';}
      else if (dataIn == '5'){cmdIn = '5';}
      else if (dataIn == '6'){cmdIn = '6';}
      else if (dataIn == '7'){cmdIn = '7';}
      else if (dataIn == '8'){cmdIn = '8';}
      else if (dataIn == '0'){cmdIn = '0';}
      else if (dataIn == '9'){cmdIn = '9';}
  }
  return cmdIn;
}


void R1_ON()
{
  if (a==0)
  digitalWrite(R1,HIGH);
  lcd.setCursor(0,0);
  lcd.print("SWT1 ON");
  a=1;
}
void R2_ON()
{
  if (b==0)
  digitalWrite(R2,HIGH);
  lcd.setCursor(8,0);
  lcd.print("SWT2 ON");
  b=1;
}
void R3_ON()
{
  if (c==0)
  digitalWrite(R3,HIGH);
  lcd.setCursor(0,1);
  lcd.print("SWT3 ON");
  c=1;
}
void R4_ON()
{
  if (d==0)
  digitalWrite(R4,HIGH);
  lcd.setCursor(8,1);
  lcd.print("SWT4 ON");
  d=1;
}
void R1_OFF()
{
  if (a==1)
  digitalWrite(R1,LOW);
  lcd.setCursor(0,0);
  lcd.print("SWT1 OF");
  a=0;
}
void R2_OFF()
{
  if (b==1)
  digitalWrite(R2,LOW);
  lcd.setCursor(8,0);
  lcd.print("SWT2 OF");
  b=0;
}
void R3_OFF()
{
  if (c==1)
  digitalWrite(R3,LOW);
  lcd.setCursor(0,1);
  lcd.print("SWT3 OF");
  c=0;
}
void R4_OFF()
{
  if (d==1)
  digitalWrite(R4,LOW);
  lcd.setCursor(8,1);
  lcd.print("SWT4 OF");
  d=0;
}
void set_stat()
{
  lcd.setCursor(0,0);
  lcd.print("SWT1 OF");
  lcd.setCursor(8,0);
  lcd.print("SWT2 OF");
  lcd.setCursor(0,1);
  lcd.print("SWT3 OF");
  lcd.setCursor(8,1);
  lcd.print("SWT4 OF");
}

