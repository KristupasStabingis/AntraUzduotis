# AntraUzduotis

# V1.1 

Studento struktūra pakeista į klasę. Gali duomenis vesti ranka ir spausdinti pagal vidurkį/medianą, arba duomenis generuoti(nuskaityti) ir skirstyti pagal medianą/vidurkį bei išvesti į du skirtingus failus. Pridėta flagų 01 , 02, 03 analizė bei class vs struct sparta.

![class vs struct bei flagu analize](https://user-images.githubusercontent.com/91029531/150146479-3eb86a4c-e5c2-4079-a2ce-4603c7fd4be4.png)

Iš analizės galima pastebėti, jog programa veikia greičiau naudojant studentas Struktūra, jei yra dirbama su dideliu failų kiekiu.
Tarp 01, 02, 03 flagų esminių skirtumų nėra, iš esmės laiko skirtumas - labai minimalus.



# V1.2

V1.2 versijoje atsiranda lyginimo operatoriai, be to, destruktorius, copy ir copy assigment operatoriai. Nežymiai pakeista įvestis.
Likusios, prieš tai buvusios funkcijos liko nepakitusios.



# V1.5 

Šioje versijoje klasė studentas išdalinta į klases : Bazinė Žmogus bei išvestinę iš jos Studentas.

# v2.0
Pridėtas DOXYGEN programa sukurtas HTML failas.
Pridėtas CMAKELISTS.txt failas, kuris padeda sukurti programos exe failą. Taip pat pridėtas ir pats .exe failas, kuris buvo sukurtas CMAKELISTS.txt pagalba.

# Naudojimosi instrukcija:

Programos naudojimas:
1.Paleiskite programą.
2.Pasirinkite ar norite duomenis vesti patys, ar generuoti ir tada skirstyti.
3.Pasirinkite ar norite galutinį balą skaičiuot/skirstyti pagal medianą ar pagal vidurkį.
4.Jei 2. punkte pasirinkote duomenis vesti patys, tada jums rezultatas atsiras toje pačioje konsolėje.
kitu atveju, bus sukurti Studentų failai su jų vardais/pavardėm/pažymiais bei suskirstyti vargšiukų ir kietiakų failai
su jau suskirstytais studentais.

CMAKELISTS diegimas:
1. Atsidarykite projektą.
2. Pridėkite CMAKELISTS failą paspaudę FILE -> OPEN -> CMAKE
3. Atsidariusiame CMAKELISTS faile, ten, kur runninamas projektas pasirinkite V1.5.exe install
4. Jums bus instaliuota programa, kuria galėsite naudotis. Ją galima rasti out->install folderyje šalia programos cpp failo.
