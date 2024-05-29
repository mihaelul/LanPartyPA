# Simularea unui campionat LANParty <br><br>
## **Obiective**: <br>
•Înțelegerea conceptului de funcționare și implementare a unor structuri de date(precum liste, stive, cozi, arbori binari de căutare)<br>
•Operarea cu aceste structuri de date<br>
•Implementarea unei funcționalități practice folosind aceste concepte<br><br>
## **Tree-ul proiectului**<br>
*de mentionat ca nu am inclus in tree fisierele din checker
<br>
.<br>
└── LanParty/<br>
    ├── checker.sh<br>
    ├── main.c<br>
    ├── .vscode/<br>
    │   ├── launch.json<br>
    │   ├── settings.json<br>
    │   └── tasks.json<br>
    ├── Player.h<br>
    ├── main.c<br>
    ├── main.h<br>
    ├── makefile<br>
    ├── exec/<br>
    │   └── tasks.c<br>
    └── headers/<br>
        └── tasks.h <br>
    <br><br>

## **Structura directorului “LanParty”** <br>

•Fisierele cu extensia .c contin functiile specifice, acolo sunt definite, iar fisierele .h contin antelele acestora si structuri de date.<br>
•Proiectul este impartit in mai multe directoare, cu nume specifice, in fisierul principal fiind checkerul, main-ul si Player.h.<br> Directorul exec
contine fisierul tasks.c, unde sunt definite toate functiile necesare indeplinirii taskurilor.<br> In directorul "headers" se afla
tasks.h, ce contine declaratiile din tasks.c, a tuturor functiilor din proiect.
<br>
•In plus, in folderul "LanParty" este si makefile-ul.
<br>

 ### **Task 1:** <br><br>
•Taskul 1 cerea sa se citeasca din fisier intr-o lista toate echipele, cu datele necesare. Am initializat o lista de tip Player si am parcurs fisierul, 
citind pe rand numele echipei, numele jucatorilor s.a.m.d. .

### **Task 2:** <br><br>
•Pentru a face meciuri de cate doua echipe si a se derula corect, este necesar ca numarul de echipe sa fie o putere de doi. Acest algoritm se gaseste in taskul 2, unde se calculeaza punctajul tuturor echipelor si sunt eliminate dupa ele. <br>
•E necesar sa gasim cea mai apropiata putere de doi care e sub numarul de echipe existente in fisier, pentru a stii cate se vor elimina.<br>
•Se cauta in lista echipele cu cel mai mic punctaj si se elimina.<br>

### **Task 3:** <br><br>
•Fiind si cel mai comnplex si numarul de subtaskuri, mi s-a parut si cel mai bun exercitiu pentru a intelege gestiunea memoriei prin utilizarea cozilor si stivelor. <br>
•Se memoreaza in doua variabile Team1 si Team2, echipele care "se vor duela" si in urma acesteia, castigand cea cu pucntaj mai mare.<br>
•Echipa castigatoare va fi introdusa intr-o coada de castigatori, care va juca urmatoarele meciuri, iar echipa pierzatoare va fi introdusa in coada de pierzatori, ulterior fiind eliminate din lista <br>
•Se face acest ciclu cat timp va ramane o singura echipa, fiind cea castigatoare.<br>
•Rezultatele dupa fiecare meci sunt printate intr-un fisier.<br>

### **Task 4:** <br><br>
•In taskul 3 am salvat top-ul primelor opt echipe, pe care l-am folosit in acest Task. <br>
•Rezultatele in urma campionatului le-am afisat sub forma unui BST, ulterior citind acest BST descrescator(de la cel mai din dreapta nod) si afisand intr-un fisier.

### **Task 5:** <br><br>
•Asemenea taskului 4, am reutilizat topul primelor opt echipe si le-am inserat intr-un arbore de tip AVL.

## **Probleme intampinate** <br>
•La taskul3, numerotarea spatiilor pentru a afisa corect in fisier a fost o mica problema, ca trebuia sa fie exact ca in fisierul de rezultate.<br>
•Endline-ul din Windows de forma "\r\n", care in Linux le citea fix "\r\n" si trebuia sa tai din string 2 caractere, pentru a nu salva newline-ul

