/**
 * By @miguel.pdf on Instagram.
 * My Github: https://github.com/java64
 */
#define IRledPin 12
#define IRSend 2
#define NumIRsignals 76
      
int IRsignal[] = {
// ON, OFF (in 10's of microseconds)
  450, 446,
  60, 162,
  54, 60,
  50, 170,
  52, 168,
  52, 60,
  54, 58,
  54, 166,
  56, 58,
  56, 56,
  56, 164,
  56, 56,
  56, 56,
  58, 162,
  58, 162,
  56, 58,
  56, 164,
  56, 56,
  56, 164,
  56, 164,
  56, 164,
  56, 164,
  56, 56,
  58, 162,
  58, 162,
  58, 162,
  56, 58,
  56, 56,
  56, 56,
  56, 56,
  56, 164,
  58, 56,
  56, 56,
  56, 164,
  56, 164,
  56, 164,
  56, 56,
  58, 54,
  58, 56,
  56, 56,
  56, 56,
  56, 58,
  56, 56,
  56, 56,
  56, 164,
  56, 164,
  56, 164,
  56, 164,
  56, 164,
  56, 536,
  450, 446,
  60, 164,
  56, 56,
  56, 164,
  56, 164,
  56, 56,
  56, 56,
  58, 162,
  58, 54,
  58, 56,
  56, 164,
  56, 56,
  56, 56,
  58, 162,
  58, 162,
  58, 56,
  56, 164,
  56, 56,
  56, 164,
  56, 164,
  56, 164,
  56, 164,
  56, 56,
  58, 162,
  58, 162,
  58, 162,
  56, 58,
  56, 56,
  56, 56,
  56, 58,
  56, 164,
  56, 56,
  56, 56,
  56, 164,
  56, 164,
  56, 164,
  56, 56,
  58, 56,
  56, 56,
  56, 56,
  56, 56,
  56, 58,
  56, 56,
  56, 56,
  56, 164,
  56, 164,
  56, 164,
  56, 164,
  58, 162,
  58, 0};
  
void setup(void) {
  Serial.begin(9600); 
  pinMode(IRledPin, OUTPUT);
  pinMode(IRSend, INPUT);
  digitalWrite(IRledPin, LOW);
  digitalWrite(IRSend, HIGH);
  
}

void loop() {
  if (digitalRead(IRSend) == LOW) {
      Serial.println("SENDING SIGNAL!");
      for (int i = 0; i < NumIRsignals; i+=2) { 
        pulseIR(IRsignal[i]*10);  
        delayMicroseconds(IRsignal[i+1]*10); 
      } 
      delay(1000);
  }
}

void pulseIR(long microsecs) {
  cli();
  while (microsecs > 0) {
   digitalWrite(IRledPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(IRledPin, LOW); 
   delayMicroseconds(10); 
   microsecs -= 26;
  }
  sei();
}
