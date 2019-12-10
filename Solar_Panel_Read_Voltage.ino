int V = A0;  //rename input A0 to V
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5 ,d6, d7);

void setup() {
  pinMode(V, INPUT);     //input voltage from solar panel
  Serial.begin(9600);    //Setup display in serial
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 1);
 }
void loop() {
  float InitialVolt = analogRead(V);      //Read volatage input
  float CalcVolt = InitialVolt /1023 *5;  //Manipulate input value to be actual volatge difference
  Serial.println(CalcVolt,5);             // display volatge difference
  delay(300);

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
   lcd.print(CalcVolt*3);
  lcd.setCursor(6, 1);
  lcd.print("Volts");
 
//The voltage difference is ~1/3 of the votage output from the solarpanel
}
