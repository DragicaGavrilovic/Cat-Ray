#include <Servo.h>
Servo donji;
Servo gornji;

//inicujalizuju se najmanji i najveci uglovi do kojih motori mogu da se okrenu
int ugaoMin = 15;
int ugaoMax= 60;

//inicijalizuju se pocetni uglovi motora 
int donjiPocetna = 0;
int gornjiPocetna = 0;

//inicijalizuju se najmanja i najveca razlika izmedju promena uglova
int pauzaMin = 1000;
int pauzaMax=2000;

//inicalizuje se najmanja apsolutna razlika izmedju pocetnog i novog ugla 
int minRazlika = 15;


void setup() {

  pinMode(3, OUTPUT);

  //laser krece da svetli, ali ne maksimalno (3 pwm pin)
  analogWrite(3, 150);
  donji.attach(6);
  gornji.attach(9);

  //motori se okrecu na pocetni ugao
  donji.write(donjiPocetna);
  gornji.write(gornjiPocetna);
}

void loop() {

  //u ovom delu koda donji motor ce se pomeriti za odredjenji ugao
  

  //generise se pauza izmedju promene uglova
  int pauza = random(pauzaMin, pauzaMax);

  //generise se novi ugao za donji motor
  int donjiPom = random(ugaoMin, ugaoMax);

  //proverava se da li je apsolutna razlika izmedju pocetnog i novog ugla manja od ugla minimalne razlike
  if (abs(donjiPom - donjiPocetna) < minRazlika)
  {

    //ispituje se da li je novi ugao >= od pocetnog
    if (donjiPom >= donjiPocetna)
    {

      //ispituje se da li bi se dodavanjem ugla minimalne razlike na novi prekoracio maksimalni
      if (donjiPom + minRazlika <= ugaoMax)
      {

        //ako ne bi, na novi ugao se dodaje ugao minimalne razlike
        donjiPom += minRazlika;
      }
      else
      {

        //u suprotnom, novi ugao ce postati pocetni umanjen za ugao minimalne razlike
        donjiPom = donjiPocetna - minRazlika;
      }
    }
    else
    {
      
      //ispituje se da li bi novi ugao umanjen za ugao minimalne razlike bio manji od minimalnog
      if (donjiPom - minRazlika >= ugaoMin)
      {

        //ako ne bi, novi ugao se smanjuje za ugao minimalne razlike
        donjiPom -= minRazlika;
      }
      else
      {

        //u suprotnom, novi ugao postaje pocetni uvecan za ugao minimalne razlike
        donjiPom = donjiPocetna + minRazlika;
      }
    }
  }

  //pocetnom uglu se dodeljuje vrednost novog i motor se okrene do tog ugla
  donjiPocetna = donjiPom;
  donji.write(donjiPocetna);
  delay(pauza);

  //u ovom delu koda gornji motor ce se pomeriti za odredjenji ugao


  //postupak je isti kao i kod dodnjeg motora
  
  pauza = random(pauzaMin, pauzaMax);
  int gornjiPom = random(ugaoMin, ugaoMax);
  if (abs(gornjiPom - gornjiPocetna) < minRazlika)
  {
    if (gornjiPom >= gornjiPocetna)
    {
      if (gornjiPom + minRazlika <= ugaoMax)
      {
        gornjiPom += minRazlika;
      }
      else
      {
        gornjiPom = gornjiPocetna - minRazlika;
      }
    }
    else
    {
      if (gornjiPom - minRazlika >= ugaoMin)
      {
        gornjiPom -= minRazlika;
      }
      else
      {
        gornjiPom = gornjiPocetna + minRazlika;
      }
    }
  }
  gornjiPocetna = gornjiPom;
  gornji.write(gornjiPocetna);
  delay(pauza);
}
