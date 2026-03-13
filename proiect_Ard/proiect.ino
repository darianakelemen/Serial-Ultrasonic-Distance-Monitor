#include <SoftwareSerial.h>

#define LED_VERDE 2
#define LED_GALBEN 3
#define LED_ROSU 4

SoftwareSerial ultrasonicSerial(8, 7);

String distantaText = "";

void setup() {
  Serial.begin(9600);
  ultrasonicSerial.begin(9600);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_GALBEN, OUTPUT);
  pinMode(LED_ROSU, OUTPUT);
}

void loop() {
  while (ultrasonicSerial.available()) {
    char c = ultrasonicSerial.read();

    if (c == '\n') {
     
      Serial.print("Text brut primit: ");
      Serial.println(distantaText);

      int distanta = extrageDistanta(distantaText);
      Serial.print("Distanta extrasa: ");
      Serial.println(distanta);

      actualizeazaLEDuri(distanta);
      distantaText = ""; 
    } 
    else if (c != '\r') {
      distantaText += c;
    }
  }
}

int extrageDistanta(String text) {
  
  String numar = "";
  for (int i = 0; i < text.length(); i++) {
    if (isDigit(text[i])) {
      numar += text[i];
    }
  }
  return numar.toInt();
}

void actualizeazaLEDuri(int distanta) {
  if (distanta > 20) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_GALBEN, LOW);
    digitalWrite(LED_ROSU, LOW);
  } else if (distanta > 10) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_GALBEN, HIGH);
    digitalWrite(LED_ROSU, LOW);
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_GALBEN, LOW);
    digitalWrite(LED_ROSU, HIGH);
  }
}