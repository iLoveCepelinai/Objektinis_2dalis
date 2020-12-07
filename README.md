# Versija v1.1
## Kodavimo eiga
(2020 12 06)

Kažkodėl programa suvalgo mano visus kompiuterio resursus kai paleidžiu su 100 000 eilučių. Su 10 000 dar veikia bet lėčiau. Aiškiai reikia optimizuoti..
Vėliau dieną išsiaiškinau kodėl: nes neišvaliau namų darbų laikino vektoriaus (ir jis vis pildėsi). Dabar kodas puikiai veikia.

## Paaiškinimai
* Programa pirma sukuria 100 000 eilučių failą, paskui atlieka užpildymą į klases (**S**tudentas), talpinamas į vektorių (grupe)
* Tada vyksta rūšiavimas į 2 vektorius (sukciukai ir dundukai)
* Galiausiai naujų failų kūrimas (100000_sukciukai.txt, 100000_dundukai.txt)
* Analogiška eiga su 1 000 000.
* Tada yra pradedama dirbti su struct'ais
* Pirma iš pradžioje sukurto 100 000 failo nuskaitomi duomenys į struct'us (**s**tudentas), talpinamus į vektorių (grupeS)
* Tada vyksta rūšiavimas į 2 vektorius
* Galiausiai naujų failų kūrimas (100000**s**_sukciukai.txt, 100000**s**_dundukai.txt)
* Analogiškai su 1 000 000

## Išvados
![laikai](https://github.com/iLoveCepelinai/Objektinis_2dalis/blob/v_1.1/1.1pav/structVSclass.png)

Taigi gauname, kad nuskaitymo laikas yra greitesnis į klases, rūšiavimo laikas yra greitesnis struct'ams, o išvedimo į naujus failus - panašiai. Viso laikas yra geresnis klasių.

## Kompiuterio parametrai
* Intel core i7-7700HQ
* 8 GB RAM DDR4
* Failas įrašomas/nuskaitomas iš HDD, bet Visual Studio įrašyta į SSD

