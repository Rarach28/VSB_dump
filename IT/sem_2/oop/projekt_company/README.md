# Systém Řízení Společnosti

Tento projekt implementuje jednoduchý systém řízení společnosti v jazyce C++. Obsahuje třídy pro reprezentaci zaměstnanců, pozic, oddělení a firem.

Odvíjí se od [https://github.com/PlesnikJakub/vsb-oop-2024/tree/main?tab=readme-ov-file](Zadíní) Předmětu OOP.

## Použití

Projekt můžete díky Makefilu zkompilovat a spustit na vašem počítači pomocí

```
make && ./main
```

## Struktura Projektu

- `Company.h` a `Company.cpp`: Definují třídy pro
  - Datum
  - Pozici
  - Osobu
  - Pracovníka
  - Vedoucího
  - Oddělení
  - Firmu.
- `main.cpp`: Obsahuje hlavní funkci pro demonstrování funkcionalit systému řízení společnosti.

## Třídy

### Date

Reprezentuje datum s dnem, měsícem a rokem.

### Position

Reprezentuje pozici ve společnosti s názvem a popisem.

### Person

Reprezentuje osobu s datem narození a plným jménem.

### Worker

Reprezentuje zaměstnance s dodatečnými atributy jako pozice, plat a datum nástupu.

### Boss

Reprezentuje vedoucího, dědícího z Pracovníka, s dodatečným atributem pro řízení zaměstnanců.

### Department

Reprezentuje oddělení s popisem a vedoucím.

### Company

Reprezentuje firmu s názvem, popisem a odděleními.

## UML Třídní Diagram

#### Níže je UML diagram tříd který blíže popisuje vztahy mezi třídami v projektu.

![UML Diagram](img/classDiagram_annot.png)

#### Diagram bez popisků

![UML Diagram](img/classDiagram.png)

## Body splnění projektu

1. Zadání (jiné než z přednášek) si vymyslíte sami, projekt ale musí obsahovat minimálně sedm
   tříd.

   - Mé Zadání nebylo nikdy na přednášsce zmíněno

2. Součástí projektu bude vlastní návrh popsaný v textové podobě a doplněný UML diagramem
   tříd (nebo jiným schématem popisujícím srozumitelně vztahy mezi třídami).

   - splněno tímto README

3. Projekt bude obsahovat kompozice (hierarchie) objektů.

- Např. Company má jako atribut pole \[Department\]

4. Projekt bude obsahovat a používat přetížené metody.

- Např. Přetížení Constructoru pro třídu Person

5. Projekt bude obsahovat a používat třídu v roli objektu.

- Splněno statickým atributem compnayCount ve třídě Company

6. Projekt bude obsahovat a využívat dědičnou hierarchii obsahující alespoň tři třídy.

- Splněno dědičností Boss -> Worker -> Person

7. Dědičnost bude obsahovat a používat jak rozšíření (dat i metod), tak změnu chování s využitou
   pozdní vazbou.

   - Rozšíření splněno ve třídě Worker, která rozšiřuje třídu Person o atributy Position, Salary a hireDate
   - Změna chování s využitím pozdní vazby splněno u Virtuální metody Person::printInfo, kterou si později upravují třídy Worker a Boss.

8. Dědičná hierarchie bude obsahovat čistě abstraktní třídu.

- splněno čistě abstraktní třídou CompanyPrinter, ze které dědí třída Company.

9. Projekt bude využívat polymorfismus (polymorfní přiřazení i polymorfní datovou strukturu).

- Splněno u třídy Boss, která má jako atribut pole Worker třídou Person

10. Po spuštění projektu bude vytvořeno alespoň několik desítek objektů zahrnujících objekty všech
    deklarovaných tříd (s výjimkou abstraktních) a ve výpisu na konzole budou prezentovány
    výsledky úloh, které objekty vykonají.

    - Splněno v [Mainu](main.cpp).
