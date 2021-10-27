int led_sortie = A0;
float tension = 0;
int modele_carte;
char charInput;
String stringInput;
int i;
int j;
const int niveau_de_securite[]{1,2,3,4,5};
const int led1 = 6;
const int led2 = 5;
const int led3 = 4;
const int led4 = 3;
const int ledB = 2;
const int bouton1 = 13;
const int bouton2 = 12;
const int bouton3 = 11;
const int bouton4 = 10;
const int bouton5 = 9;
const int bouton6 = 8;
const int bouton7 = 7;
int etatBouton1;
int etatBouton2;
int etatBouton3;
int etatBouton4;
int etatBouton5;
int etatBouton6;
int etatBouton7;
int compteur;
int code_valide = 0;
int tentative = 0;

void setup() {
 Serial.begin(9600);
 randomSeed(30);
 pinMode(led_sortie, INPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(ledB, OUTPUT);
 pinMode(bouton1, INPUT);
 pinMode(bouton2, INPUT);
 pinMode(bouton3, INPUT);
 pinMode(bouton4, INPUT);
 pinMode(bouton5, INPUT);
 pinMode(bouton6, INPUT);
 pinMode(bouton7, INPUT);
}

void loop() {
    i=0;
    j=0;
    //Serial.println(analogRead(A0));
    //tension = (float)analogRead(A0)*5.0/1023;
    //Serial.println("--------------------------------");
    //Serial.print("Tension de sortie : U = ");
    //Serial.print(tension);
    //Serial.println("V");
    Serial.println("--------------------------------");
    Serial.println("Appuyez sur la touche 1 lorsque vous etes pret a vous authentifier.");
    if(Serial.available()==0){
    delay(500);
    }
    if(Serial.available()>0){
      if(Serial.read()=='1'){
        //tensions en analogRead(A0) = {0,4,54,127,164,200,271,339}
        if(analogRead(A0) == 0){
          modele_carte = 1;
          niveau_securite(niveau_de_securite[int(modele_carte-1)]);
        }
        else if(analogRead(A0) == 4){
          modele_carte = 2;
          niveau_securite(niveau_de_securite[int(modele_carte)]);
        }
        else if(analogRead(A0) == 54){
          modele_carte = 3;
          niveau_securite(niveau_de_securite[int(modele_carte-1)]);
        }
        else if(analogRead(A0) == 127){
          modele_carte = 4;
          niveau_securite(niveau_de_securite[int(modele_carte)]);
        }
        else if(analogRead(A0) == 164){
          modele_carte = 5;
          niveau_securite(niveau_de_securite[int(modele_carte-1)]);
        }
        else if(analogRead(A0) == 200){
          modele_carte = 6;
          niveau_securite(niveau_de_securite[int(modele_carte-5)]);
        }
        else if(analogRead(A0) == 271){
          modele_carte = 7;
          niveau_securite(niveau_de_securite[int(modele_carte-4)]);
        }
        else if(analogRead(A0) == 339){
          modele_carte = 8;
          niveau_securite(niveau_de_securite[int(modele_carte-4)]);
        }
      }
      if(i==1){
        Serial.println("--------------------------------");
        Serial.println("Entrez le code d'agence grâce au digicode à 7 chiffres");
        digicode();
      }
      else if(i==0){
        Serial.println("--------------------------------");
        Serial.println("Acces refuse");
    }
    }
}

//Fonction lire chaines de caractères
void lire(){
  stringInput = "";
  while(Serial.available()==0){}
  delay(50);
  while(Serial.available()>0){
    charInput = Serial.read();
    stringInput.concat(charInput);
  }
}

//MA1
int MA1(){
  char reponse1;
  char reponse2;
  char reponse3;
  char reponse4;
    Serial.println("--------------------------------");
    Serial.println("Comment s'appelle le chien du chef?");
    Serial.println("1) Franky");
    Serial.println("2) Rex");
    Serial.println("3) Churchill");
    Serial.println("4) Le chef n'a pas de chien");
    while(Serial.available()==0){}
    delay(50);
    if (Serial.available()>0){
        reponse1 = Serial.read();
        Serial.println("--------------------------------");
        Serial.println("Combien de machines a cafe y a-t-il dans la salle de repos?");
        Serial.println("1) 1");
        Serial.println("2) 2");
        Serial.println("3) 3");
        Serial.println("4) 10");
        while(Serial.available()==0){}
      delay(50);
        if(Serial.available()>0){
             reponse2 = Serial.read();
             Serial.println("--------------------------------");
             Serial.println("Quel est le meilleur anime parmi ceux-la?");
             Serial.println("1) One Piece");
             Serial.println("2) Naruto");
             Serial.println("3) Dragon Ball");
             Serial.println("4) Bleach");
             while(Serial.available()==0){}
         delay(50);
             if(Serial.available()>0){
                reponse3 = Serial.read();
                Serial.println("--------------------------------");
                Serial.println("Quel est le numero porte bonheur de l'agence?");
                Serial.println("1) 4");
                Serial.println("2) 8");
                Serial.println("3) 1");
                Serial.println("4) 0");
                while(Serial.available()==0){}
            delay(50);
                if(Serial.available()>0){
                  reponse4 = Serial.read();
                  if(reponse1 == '3' and reponse2 == '4' and reponse3 == '1' and reponse4 == '3'){
                    Serial.println("Reponses justes");
                    j=j+1;
                    i=1;
                  }
                  else{
                    Serial.println("Erreur d'authentification");
                    i=0;
                    j=0;
                  }
                }
             }
        }
    }
}
      

//MA2
int MA2(){
  int c;
  long m;
  char lettre;
  const int key_e[]{601,619,631,641,647,653,661,673,691,701,733,739,751,797,809,811};
    m=random(-2881,2882);
    Serial.println("--------------------------------");
    Serial.println("Entrez votre lettre d'agent :");
    while(Serial.available()==0){}
    delay(50);
    if(Serial.available()>0){
      lettre = Serial.read();
      if(lettre >= 'A' and lettre <= 'Q'){
        c = encrypt(m, key_e[int(lettre-65)], 2881);
        Serial.print("Dechiffrez ce message :");
        Serial.println(c);
        Serial.println("Saisissez le code dechiffre :");
        lire();
        if(stringInput.toInt() == m){
          Serial.println("Cle valide");
          j=j+1;
          i=1;
        }
        else{
          Serial.println("Erreur d'authentification");
          i=0;
          j=0;
        }
      }
    }
  }



//fonction d'encryptage pour MA2
long encrypt (int a, int e, int n) 
{
  long code;
  if (a == 0 or n ==1)
  {
    code=0;
  }
  else
  {
    for (code=1; e>0; e=e-1)
    {
      code= (code*(a%n)%n);
    }
  }
  return (code);
}

//MA3
int MA3(){
  char validation;
    Serial.println("--------------------------------");
    Serial.println("Placez votre oeil devant le capteur, puis appuyez sur 1 quand vous etes pret");
    while(Serial.available()==0){}
    delay(50);
    if(Serial.available()>0){
      validation = Serial.read();
      if(validation=='1'){
        Serial.println("Scan valide");
        i=1;
        j=j+1;
      }
      else{
        Serial.println("Erreur d'authentification");
        i=0;
        j=0;
      }
    }
  }


//MA4
int MA4(){
  char validation;
    Serial.println("--------------------------------");
    Serial.println("Placez votre doigts sur le scanner, puis appuyez sur 1 quand vous etes pret");
    while(Serial.available()==0){}
    delay(50);
    if(Serial.available()>0){
      validation = Serial.read();
      if(validation=='1'){
        Serial.println("Scan valide");
        i=1;
        j=j+1;
      }
      else{
        Serial.println("Erreur d'authentification");
        i=0;
        j=0;
      }
    }
  }


//MA5
int MA5(){
  char lettre;
  char charInput;
  const int CARD_ID[]{1276,8954,6285,1846,8234,1475,2518,1674,2856,4785,1256,2853,1502,1850,1812,9942};
  String code;
    Serial.println("--------------------------------");
    Serial.println("Entrez votre lettre d'agent :");
    while(Serial.available()==0){}
    delay(50);
    if(Serial.available()>0){
      lettre = Serial.read();
      if(lettre >= 'A' and lettre <= 'Q'){
        Serial.println("Entrez votre CARD_ID :");
      lire();
        if(CARD_ID[int(lettre-65)] == stringInput.toInt()){
          Serial.println("Code valide");
          i=1;
          j=j+1;
        }
        else{
          Serial.println("Erreur d'authentification");
          i=0;
          j=0;
        }  
      }
      else{
        Serial.println("Erreur d'authentification");
        i=0;
        j=0;
      }
    }
  }


//Fontion niveau de sécurité
int niveau_securite(int numero){
  if (numero==1){
    MA1();
    if(j==0){
      MA1();
    }
    else{
      MA3();
    }
  }
  else if(numero==2){
    MA1();
    if(j==0){
      MA1();
    }
    else{
      MA4();
    }
  }
  else if(numero==3){
    MA2();
    if(j==0){
      MA2();
    }
    else{
      MA5();
    }
  }
  else if(numero==4){
    MA2();
    if(j==0){
      MA2();
    }
    else{
      MA3();
    }
    if(j==0){
      MA2();
    }
    else{
      MA4();
    }
  }
  else if(numero==5){
    MA1();
    if(j==0){
      MA1();
    }
    else{
      MA2();
    }
    if(j==0){
      MA1();
    }
    else{
      MA3();
    }
    if(j==0){
      MA1();
    }
    else{
      MA5();
    }
  }
}

//Fonction du digicode
int digicode(){
  while(tentative!=4){
    compteur=0;
    etatBouton1 = digitalRead(13);
    etatBouton2 = digitalRead(12);
    etatBouton3 = digitalRead(11);
    etatBouton4 = digitalRead(10);
    etatBouton5 = digitalRead(9);
    etatBouton6 = digitalRead(8);
    etatBouton7 = digitalRead(7);
    lectureBouton();
    if(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == HIGH and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == LOW and etatBouton7 == LOW){
      digitalWrite(6, HIGH);
      lectureBouton();
      if(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == HIGH and etatBouton7 == LOW){
        digitalWrite(5, HIGH);
        lectureBouton();
        if(etatBouton1 == LOW and etatBouton2 == HIGH and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == LOW and etatBouton7 == LOW){
          digitalWrite(4, HIGH);
          lectureBouton();
          if(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == HIGH and etatBouton6 == LOW and etatBouton7 == LOW){
            digitalWrite(3, HIGH);
            code_valide=1;
          }
        }
      }
    }
    if(code_valide==1){
      Serial.println("Code valide");
      digitalWrite(2, HIGH);
      Serial.println("Ouverture du coffre");
      delay(5000);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      fermeture();
    }
    if(code_valide==0){
      while(compteur != 3){
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        delay(500);
        compteur+=1;
      }
      tentative += 1;
      Serial.println("Code invalide");
      Serial.print("Tentative(s) restante(s)");
      Serial.println(4-tentative);
    }
    if(tentative == 4){
      compteur=0;
      while(compteur != 3){
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        delay(500);
        compteur+=1;
      }
      Serial.println("ERREUR (attendez 30 secondes)");
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      delay(30000);
      tentative=0;
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
    }
  }
}

//Fonction lecture de boutons
int lectureBouton(){
  while(etatBouton1 == HIGH or etatBouton2 == HIGH or etatBouton3 == HIGH or etatBouton4 == HIGH or etatBouton5 == HIGH or etatBouton6 == HIGH or etatBouton7 == HIGH){
    etatBouton1 = digitalRead(13);
    etatBouton2 = digitalRead(12);
    etatBouton3 = digitalRead(11);
    etatBouton4 = digitalRead(10);
    etatBouton5 = digitalRead(9);
    etatBouton6 = digitalRead(8);
    etatBouton7 = digitalRead(7);
  }
  while(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == LOW and etatBouton7 == LOW){
    etatBouton1 = digitalRead(13);
    etatBouton2 = digitalRead(12);
    etatBouton3 = digitalRead(11);
    etatBouton4 = digitalRead(10);
    etatBouton5 = digitalRead(9);
    etatBouton6 = digitalRead(8);
    etatBouton7 = digitalRead(7);
  }
}


//Fonction de fermeture du coffre (digicode)
int fermeture(){
  while(tentative!=4){
    compteur=0;
    etatBouton1 = digitalRead(13);
    etatBouton2 = digitalRead(12);
    etatBouton3 = digitalRead(11);
    etatBouton4 = digitalRead(10);
    etatBouton5 = digitalRead(9);
    etatBouton6 = digitalRead(8);
    etatBouton7 = digitalRead(7);
    lectureBouton();
    if(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == HIGH and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == LOW and etatBouton7 == LOW){
      digitalWrite(6, HIGH);
      lectureBouton();
      if(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == HIGH and etatBouton7 == LOW){
        digitalWrite(5, HIGH);
        lectureBouton();
        if(etatBouton1 == LOW and etatBouton2 == HIGH and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == LOW and etatBouton6 == LOW and etatBouton7 == LOW){
          digitalWrite(4, HIGH);
          lectureBouton();
          if(etatBouton1 == LOW and etatBouton2 == LOW and etatBouton3 == LOW and etatBouton4 == LOW and etatBouton5 == HIGH and etatBouton6 == LOW and etatBouton7 == LOW){
            digitalWrite(3, HIGH);
            code_valide=1;
          }
        }
      }
    }
    if(code_valide==1){
      Serial.println("Code valide");
      digitalWrite(2, HIGH);
      Serial.println("Fermeture du coffre");
      delay(5000);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digicode();
    }
    if(code_valide==0){
      while(compteur != 3){
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        delay(500);
        compteur+=1;
      }
      tentative += 1;
      Serial.println("Code invalide");
      Serial.print("Tentative(s) restante(s)");
      Serial.println(4-tentative);
    }
    if(tentative == 4){
      compteur=0;
      while(compteur != 3){
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        delay(500);
        compteur+=1;
      }
      Serial.println("ERREUR (attendez 30 secondes)");
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      delay(5000);
      tentative=0;
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
    }
  }
}
