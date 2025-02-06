//définir la broche de la DEL
const int ledPin = 13;
const float MONCHIFFRE= 3;
int resultat;
//définir l'état de la DEL
bool ledState = LOW;
int delais_d_allumage = 2000;
int delais_d_extinction = 2000;
int delais_de_clignotement = 250;
int delais_de_variation;

const String NUMERO_D_ETUDIANT="2405238";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void allumer(){
    digitalWrite(ledPin, HIGH);
    Serial.print("Allume-");
    Serial.println(NUMERO_D_ETUDIANT);
    delay(delais_d_allumage);
}
void clignotement(){
    resultat =ceil(MONCHIFFRE / 2.0) + 1;
       
    for(int i= 0 ; i< resultat ; i++){
        digitalWrite(ledPin, LOW);
        delay(delais_de_clignotement);
        digitalWrite(ledPin, HIGH);
        delay(delais_de_clignotement);
        
      
    }
    Serial.print("Clignotement-");
    Serial.println(NUMERO_D_ETUDIANT);
}
void variation(){
    delais_de_variation = 2048/255;
    for(int i =0 ; i<=255 ; i++){
        analogWrite(ledPin, i);
        delay(delais_de_variation);

    }
    Serial.print("Variation-");
    Serial.println(NUMERO_D_ETUDIANT);
}

void eteindre(){
    digitalWrite(ledPin, LOW);
    Serial.print("Éteint-");
    Serial.println(NUMERO_D_ETUDIANT);
    delay(delais_d_extinction);

}

void loop() {
  allumer();
  clignotement();
  variation();
  eteindre();
}