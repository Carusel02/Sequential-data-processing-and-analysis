# Tema1
Readme tema1 # Tema1
Timp de lucru : 12-15h
Explicatie cerinte :
-functii principale
ca functii principale am folosit adaugarea in lista, stergerea
unui nod din lista, copierea unei liste in alta lista, afisarea
unei liste, eliberarea nodurilor unei liste
-task1(e1)
ideea principala care sta la baza cerintei a fost folosirea
unui "flag" pentru a marca nodurile ce trebuie sterse.
astfel, lista va fi parcursa inca o data si se vor sterge
nodurile care au un flag activ(1).(se putea folosi de asemenea
si modificarea timestampului cu o valoare negativa pentru a
evidentia acest procedeu)
de asemenea, am implementat 2 functii care calculeaza deviatia si
media.
-task2(e2)
la task2 un mod simplu de rezolvare ar fi adaugarea ferestei de
5 noduri intr o lista auxiliara, apoi sortarea acesteia.
valoarea din mijloc este apoi adaugata, iar pentru inlantuirea
comenzilor a trebuit sa dau free la lista anterioara si sa o 
actualizez cu noua lista formata din aceste valori extrase.
-task3(e3)
similar cu task2, acesta a avut nevoie de o functie care
calculeaza media pe o fereastra de 5 noduri si o adauga intr o
noua lista.
la final, vechea lista este actualizata.
-task4(u)
uniformizarea frecventei a constat intr o operatie simpla care 
parcurge lista si modifica nodurile care respecta cerintele.
folosind o functie de uniformizare, am modificat lista conform
cerintei.
-task5(c)
completarea unui interval consta in adaugarea de elemente dupa
un nod.
timestampul nodului se modifica cu +200 pana la ultima valoare
iar data fiecarui nod este influentata de un parametru C.
sumele left si right sunt niste medii ponderate(numere constante
pentru un interval in care se adauga noduri) care iau in calcul
primii 3 termeni si ultimii 3 termeni de unde se face adaugarea.
acestia sunt inmultiti cu niste coeficienti, cei mai importanti(mari)
coeficienti fiind inmultiti cu cei mai apropiati termeni fata de
intervalul in care se adauga.
pentru acest task, am folosit o singura functie care calculeaza
fiecare informatie a unui nod si il adauga dupa un nod printr o
functie auxiliara.
-task6(st)
partea cu extrasul din argument s a facut folosind operatii cu 
codul ASCII, apoi acest numar a fost transmis ca si parametru 
intr o functie ce sorteaza si apoi numara cate noduri au datele
apartinand intervalului.

![poza]("CODUL MEU.png")

# implementarea codului
-pentru implementarea codului, am folosit VScode pe Linux pentru
a putea folosi utilitarul valgrind(pentru memory leak uri) si gdb
(pentru segmentation fault uri). (cea mai grea parte nu a fost cerinta
si scrierea codului, ci partea de debugging xD)
