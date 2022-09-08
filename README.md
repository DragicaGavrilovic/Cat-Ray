# Cat ray

Cat ray je uređaj koji služi za zanimanje mačaka pomoću pokretnog lasera i kreiran je pomoću Arduino platforme.

## Hardver

Cat ray se sastoji iz dva servo motora i jednog lasera. Donji motor rotira gornji, a za gornji je zakačen laser. Dakle, oba motora pomeraju laser. 
Takođe, bilo je potrebno i napraviti postolje (telo) za uređaj. Za to smo koristili 3D štampač i program Fusion 360. Telo se sastoji od dva dela – postolja za koje se kači jedan motor i dela koji se na njega priključuje, a na kom se nalazi drugi motor. 

## Softver

Ideja je da se laser pomera nasumično, bez ikakve pravilnosti, i da se u istoj tački zadržava različito vreme.
Na početku se svi motori moraju vratiti na ugao od 0°, a laser se uključuje, ali ne na najveći sjaj. To je moguće jer je povezan na digitalni pwm pin. Definisani su minimalni i maksimalni ugao do kog se motori mogu okrenuti, minimalno i maksimalno vreme između promena, kao i minimalna razlika izmedju novog i prethodnog ugla. 
U loop metodi prvo se pomera donji motor. Bira se nasumični ugao u okviru granica, a zatim sledi ispitivanje da li je apsolutna vrednost razlike novog i starog ugla veća od minimalne dozvoljene. Ako jeste, novi ugao ostaje nepromenjen, a ko nije, ispituje se da li je novi ugao veći ili manji od prethodnog. Ako je manji i ako se smanjivanjem novog ugla za ugao minimalne ne bi dobio manji ugao od minimalnog, novi ugao će se smanjiti za ugao minimalne razlike. U suprotnom, novi ugao će postati prethodni umanjen za ugao minimalne razlike. Inače, ako je je novi ugao veći od prethodnog i ako se uvećavanjem novog ugla za ugao minimalne ne bi dobio veći ugao od maksimalnig, novi ugao će se uvećati za ugao minimalne razlike. U suprotnom, novi ugao će postati prethodni uvećan za ugao minimalne razlike.
Nakon toga, motor se pomera do novog ugla i ceo uređaj ostaje u ovom položaju za vreme koje je nasumično generisano, poštujući definisane granice. 
Isti postupak se ponavlja i za gornji motor.

## Zaključak

Smatramo da smo projekat dobro uradili, telo za uređaj je jednostavno i veoma optimizovano, što je omogućilo brzo štampanje, šema je takođe jednostavna, a kod je efikasno odgovorio zahtevima. Naravno, postoji dosta prostora za unapređenje. Jedno poboljšanje bi moglo da bude dodavanje trećeg motora, kao još jednu osu rotacije. Naredni korak bi bilo pravljenje čitave robotske ruke, sa šakom umesto lasera. Upravo to su ideje za naše naredne projekte.

## The short notice in English

Cat ray is a device that attracts cats using a moving laser. It is created using the Arduino platform.
Device consists of two servo motors and one laser. The lower motor rotates the upper one, and a laser is attached to the upper one. So both motors move the laser. It was also necessary to make a body for the device. For that, we used a 3D printer and the Fusion 365 program.
The idea is to move the laser randomly, without any regularity, and to stay at the same point for different times. Also, the laser is on all the time.

## Autori

Dragica Gavrilović
Konstantin Petrović
Maksim Zečević





