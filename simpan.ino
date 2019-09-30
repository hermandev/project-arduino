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
