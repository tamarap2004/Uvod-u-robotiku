# Upravljanje servo motorom pomoću potenciometra i tastera (Arduino)

## Opis zadatka

Cilj ovog zadatka je da se prikaže kako se servo motor može kontrolisati pomoću potenciometra, tako da se menja brzina okretanja, kao i kako se motor može zaustaviti tasterom, uz vizuelnu indikaciju stanja sistema preko LED dioda. Takođe, sistem prikazuje vrednosti na Serial Monitoru radi praćenja rada.

Sistem omogućava:
- Promenu brzine servo motora pomoću potenciometra  
- Zaustavljanje servo motora pritiskom na taster  
- Vizuelnu indikaciju stanja preko LED dioda  
- Praćenje stanja sistema putem Serial Monitora  

## Funkcionalnosti

Potenciometar određuje brzinu servo motora (vrednosti od 91 do 180).  
Taster služi za zaustavljanje servo motora.  
Zelena LED pokazuje da se servo motor okreće.  
Crvena LED pokazuje da je sistem zaustavljen.  
Serial Monitor prikazuje:
- vrednost potenciometra  
- izračunatu brzinu servo motora  
- stanje tastera  
- trenutno stanje sistema  

## Povezivanje komponenti

Servo motor je povezan na digitalni pin 9 Arduino ploče.  
Potenciometar je povezan tako da srednji pin ide na analogni pin A0, a spoljašnji pinovi na 5V i GND.  
Taster je povezan na digitalni pin 7, koristeći INPUT_PULLUP režim (taster je pritisnut kada je stanje LOW).  
Zelena LED je povezana na digitalni pin 5 preko otpornika od 220Ω do GND.  
Crvena LED je povezana na digitalni pin 6 preko otpornika od 220Ω do GND.  

## Način rada sistema

Nakon uključivanja, servo motor se okreće brzinom koja zavisi od položaja potenciometra.  
Kada se pritisne taster:
- Servo motor se zaustavlja (brzina = 0)  
- Crvena LED svetli  
- Zelena LED je ugašena  

Kada se taster otpusti:
- Servo motor nastavlja rad  
- Zelena LED svetli  
- Crvena LED je ugašena  

## Serial Monitor

Baud rate: 9600  

Primer ispisa:
Potenciometar: 512 | Brzina: 135 | Taster: Otpusten
Stanje: OKRETANJE

## Korišćene tehnologije

Arduino Uno  
Servo.h biblioteka  
Arduino IDE (C/C++)
