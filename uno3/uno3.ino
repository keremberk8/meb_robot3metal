#include <Servo.h>

Servo tokat;  // Servo nesnesi oluştur
Servo ceza_tokat;

const int sayac_sinyal = 13;
const int ceza_sinyal = 12;
const int kilit_bildirim = 11;
const int bolge_bildirim = 10;
const int ceza_tokatla_bildirim = 9;
bool kirmizi = false;
bool mavi = false;
bool ceza = false;

byte bolge = 0;
byte sayac = 0;

unsigned long baslangicZamani;

void setup() {

  tokat.attach(5);
  ceza_tokat.attach(6);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(sayac_sinyal, OUTPUT);
  pinMode(ceza_sinyal, OUTPUT);
  pinMode(kilit_bildirim, INPUT);
  pinMode(bolge_bildirim, INPUT);
  pinMode(ceza_tokatla_bildirim, INPUT);

  Serial.begin(9600);
  tokat.write(80);
  ceza_tokat.write(0);
  delay(2000);
  bolge = digitalRead(bolge_bildirim);

  baslangicZamani = millis();
}

void loop() {

  while (millis() - baslangicZamani < 45000) { 

    if (digitalRead(A0) == 1 && (digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0)) {
      //Serial.println("KIRMIZIIII");

      if (bolge == 1) {
        dogru_al();
      } else {
        rakip_al();
      }
    } else if (digitalRead(A0) == 1 && (digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 1)) {
      //Serial.println("MAVİİİ");

      if (bolge == 0) {
        dogru_al();
      } else {
        rakip_al();
      }

    } else if (digitalRead(A0) == 1 && !(digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 1) && !(digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0)) {
      //Serial.println("CEZA");
      ceza_al();
      ceza = true;
     
  }

      else {
        Serial.println("BOŞŞŞŞŞŞŞŞŞŞŞŞ");
      }
    
  }
  digitalWrite(sayac_sinyal, HIGH);
  delay(3000);
  while (digitalRead(kilit_bildirim) == 1) {}
  digitalWrite(sayac_sinyal, LOW);

  delay(5000);

  if (ceza == true){
    digitalWrite(ceza_sinyal, HIGH);
    delay(3000);
    while (digitalRead(kilit_bildirim) == 1) {
      if (digitalRead(ceza_tokatla_bildirim) == 1) {
        ceza_tokat.write(0);
      }
    }
    digitalWrite(ceza_sinyal, LOW);
    ceza = false;
  }
  
  //NORMAL KOD***********************************************************************************************
  while(true)
  {
    if (digitalRead(A0) == 1 && (digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0)) {
    //Serial.println("KIRMIZIIII");
    if (bolge == 1) {
      dogru_al();
      sayac++;
      if (sayac > 2) {
        digitalWrite(sayac_sinyal, HIGH);
        delay(3000);
        while (digitalRead(kilit_bildirim) == 1) {
        }
        digitalWrite(sayac_sinyal, LOW);
        sayac = 0;
      }
    } else {
      rakip_al();
    }
  } else if (digitalRead(A0) == 1 && (digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 1)) {
    //Serial.println("MAVİİİ");
    if (bolge == 0) {
      dogru_al();
      sayac++;
      if (sayac > 2) {
        digitalWrite(sayac_sinyal, HIGH);
        delay(3000);
        while (digitalRead(kilit_bildirim) == 1) {
        }
        digitalWrite(sayac_sinyal, LOW);
        sayac = 0;
      }
    } else {
      rakip_al();
    }

  } else if (digitalRead(A0) == 1 && !(digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 1) && !(digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0)) {
    //Serial.println("CEZA");
    ceza_al();
    digitalWrite(ceza_sinyal, HIGH);
    delay(3000);
    while (digitalRead(kilit_bildirim) == 1) {
      if (digitalRead(ceza_tokatla_bildirim) == 1) {
        ceza_tokat.write(0);
        delay(2000);
      }
    }
    digitalWrite(ceza_sinyal, LOW);
  } else {
    //Serial.println("BOŞŞŞŞŞŞŞŞŞŞŞŞ");
  }
  }
  
  
}

void dogru_al() {
  tokat.write(180);
  delay(100);
  tokat.write(80);
}

void rakip_al() {
  tokat.write(0);
  delay(100);
  tokat.write(80);
}

void ceza_al() {
  ceza_tokat.write(81);
  delay(600);
  tokat.write(180);
  delay(100);
  tokat.write(80);
  delay(100);
  ceza_tokat.write(26);
}
