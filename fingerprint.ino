#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <SoftwareSerial.h>
uint8_t id;
const int buzzer = 3;
int alamat=0;
int relay1=4;
int relay2=5;
int getFingerprintIDez();
uint8_t getFingerprintEnroll(int id);
uint8_t deleteFingerprint(uint8_t id);
SoftwareSerial mySerial(1, 2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup(){
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
//    Serial.println("Sensor Ditemukan!");
    tone(3,1800,100);
    delay(100);
    tone(3,1500,100);
    delay(500);
//    finger.emptyDatabase();
  } else {
//    Serial.println("Sensor Tidak Ditemukan! :(");
    tone(3,1500,100);
    delay(100);
    tone(3,3000,200);
    delay(200);
    tone(3,1500,100);
    delay(100);
    tone(3,3000,200);
    delay(200);
    while(1);
  }
  
}



void loop(){
//  check finger yang terdafatr
  getFingerprintIDez();

// tambah data finger berdasarkan id
//  getFingerprintEnroll(2);

// hapus data finger berdasarkan id
// deleteFingerprint(2);

}
