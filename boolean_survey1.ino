#include <EEPROM.h>
bool lecturasi = false;
bool lecturano = false;
bool lecturareset = false;
int numsi;
int numno;
int si;
int no;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
  EEPROM.get(0, numsi);
  EEPROM.get(2, numno);
  EEPROM.get(0, si);
  EEPROM.get(2, no);
}

void loop()
{
  lecturasi = digitalRead(2);
  lecturano = digitalRead(3);
  lecturareset = digitalRead(4);
  
  if(lecturasi == true){
    numsi++;
	EEPROM.write(0, numsi);
    lecturasi = false;
    Serial.println("Si: " + String(numsi));
    Serial.println("No: " + String(numno));
    Serial.println("---------------------------");
    delay(500);
  }
  if(lecturano == true){
    numno++;
    EEPROM.write(2, numno);
    lecturano = false;
    Serial.println("Si: " + String(numsi));
    Serial.println("No: " + String(numno));
    Serial.println("---------------------------");
    delay(500);
  }
  
  if(lecturareset == true){
    numsi = 0;
    numno = 0;
    EEPROM.get(0, si);
    EEPROM.get(2, no);
    Serial.println("Resultados de la votacion: ");
    Serial.println("Si: " + String(si));
    Serial.println("No: " + String(no));
    Serial.println("---------------------------");
    delay(500);
    EEPROM.write(0, 0);
    EEPROM.write(2, 0);
  }
}