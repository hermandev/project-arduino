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
