Progetto finale: Sistema tutor
Gruppo: + di C ma - di D
Membri: Francesco Barban, Giacomo Alberto Dalla Riva, Sebastian Holospin

Note
----------------------
non essendo specificata la velocità media globale richiesta da stampare tramite stats (in tutor.exe), 
abbiamo deciso di considerare la media aritmetica della velocità media pesata nel tempo di ogni macchina

il file passages ha tutti i passaggi della stessa macchina raggruppati
il programma tutor opera su una "timeline" in cui i passaggi sono ordinati solo cronologicamente



Istruzioni per l’esecuzione
-------------------------------------------
creare build in TutorAutostradale (mkdir build), entrare (cd build) e chiamare "cmake .."
poi build con "make" (o in windows "cmake --build ." )
i path dei file in lettura e scrittura sono pensati per una cartella build \TutorAutostradale\build

ATTENZIONE:
compilare chiamando il compilatore da terminale funziona, ma, qualora non venissero spostati i file eseguibili
tutor e simulatore in una qualunque cartella successiva a TutorAutostradale, l'esecuzione potrebbe 
incontrare problemi, causa path relativi per lettura/scrittura file.

nel file CMakelists è attiva la flag "-O2"