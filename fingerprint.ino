#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <SoftwareSerial.h>
uint8_t id;
const int buzzer = 3;
int alamat=0;
int relay1=4;
int relay2=5;
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


uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
     
     
  delay(1000);
      break;
    case FINGERPRINT_NOFINGER:
   
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
  
      return p;
    case FINGERPRINT_IMAGEFAIL:
   
      return p;
    default:
   
      return p;
  }

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
   
  delay(1000);
      break;
    case FINGERPRINT_IMAGEMESS:
   
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
    
      return p;
    case FINGERPRINT_FEATUREFAIL:
   
      return p;
    case FINGERPRINT_INVALIDIMAGE:
     
      return p;
    default:
   
      return p;
  }
  
 
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
   
  
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
  
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
 
    return p;
  } else {
  
    return p;
  }   
  
}


// check fingher
int getFingerprintIDez() {
//  digitalWrite(led,HIGH);
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  
  {
    Serial.println("Salah");
    tone(3,1500,100);
    delay(100);
    tone(3,3000,200);
    tone(3,1500,100);
    delay(100);
    tone(3,3000,200);
//    delay(200);
//    tone(3,1500,100);
//    delay(100);
//    tone(3,3000,200);
//    delay(200);
     while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
    Serial.println("Lepaskan");
  }
  delay(2000);
  return -1;
  }
  tone(3,1800,100);
  delay(100);
  tone(3,1500,100);
  delay(500);
  digitalWrite(relay1,HIGH);
  delay(1000);

  digitalWrite(relay1,LOW);
  

  return finger.fingerID; 
}


//simpan
uint8_t getFingerprintEnroll(int id) {
  int p = -1;
  
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
  
      break;
    case FINGERPRINT_NOFINGER:
   
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
     
      break;
    case FINGERPRINT_IMAGEFAIL:
    
      break;
    default:
   
      break;
    }
  }

 

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
   
      break;
    case FINGERPRINT_IMAGEMESS:
     tone(3,1500,100);
  delay(100);
  tone(3,3000,200);
  delay(200);
    tone(3,1500,100);
  delay(100);
  tone(3,3000,200);
  delay(200);
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
   
      return p;
    case FINGERPRINT_FEATUREFAIL:
    tone(3,1500,100);
  delay(100);
  tone(3,3000,200);
  delay(200);
    tone(3,1500,100);
  delay(100);
  tone(3,3000,200);
  delay(200);
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      tone(3,1500,100);
  delay(100);
  tone(3,3000,200);
  delay(200);
    tone(3,1500,100);
  delay(100);
  tone(3,3000,200);
  delay(200);
      return p;
    default:
   
      return p;
  }
  tone(3,1800,100);
  delay(100);
  Serial.println("Lepaskan jari");
  delay(1000);
 
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }

  p = -1;
 tone(3,1800,100);
  delay(100);
   Serial.println("Tempelkan jari");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
   
      break;
    case FINGERPRINT_NOFINGER:
   
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
    
      break;
    case FINGERPRINT_IMAGEFAIL:
   
      break;
    default:
     
      break;
    }
  }

 

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
   
      break;
    case FINGERPRINT_IMAGEMESS:
   
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
  
      return p;
    case FINGERPRINT_FEATUREFAIL:
    
      return p;
    case FINGERPRINT_INVALIDIMAGE:
  
      return p;
    default:
    
      return p;
  }
 
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
 
   
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
  
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
   
    return p;
  } else {
   
    return p;
  }   
 
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
     Serial.println("Disimpan");
  tone(3,1800,100);
  delay(100);
  tone(3,3000,500);
  delay(500);
 
  delay(1000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
   
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
  
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
 
    return p;
  } else {

    return p;
  }   
}

// haspus
uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;
  
  p = finger.deleteModel(id);
 
  if (p == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not delete in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(p, HEX);
    return p;
  }   
}
