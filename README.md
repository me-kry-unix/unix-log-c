# unix-log-c

## Készítsünk egy kis C alkalmazas, ami 3 dolgot csinál:
* fogadja a rendszer szignálokat, es kilép, ha kap egyet.
* a rendszer logot hasznalja. Megnyitja, minden másodpercben kiir, majd a legvégén lezarja a rendszer logot (ha szignált kap).
* vegtelen ciklusban másodpercenként leptet egy számlálót, es printf-el kiír egy szöveget.

##
1. Készítsünk egy szignál kezelő metódust: typedef void (*sighandler_t)(int); Ebben a metodusban: zard le a logot.
2. Használva a signal metódust, regisztráljunk be egy saját szignál kezelőt!
(https://man7.org/linux/man-pages/man2/signal.2.html)
3. Nyissuk meg a rendszer log-ot. https://www.man7.org/linux/man-pages/man3/openlog.3.html 
```
 openlog("syslogTestDaemon", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
```
4. Irjuk ki a logba, hogy a program elindult. (LOG_INFO szint) Irjuk ki, hogy ki inditotta, használjuk a getuid() függvényt.
5. definiáljunk egy számlálót
```
int counter = 1;
```
7. végtelen ciklusban: 
* írd ki minden log szinten a log szintet, és a számláló értékét.
* pihentesd a futást 1 másodpercig
```
sleep(1);
```
* léptesd a számlálót


## Mentsuk el main.c file-ba a tartalmat!
Fordítsuk le: 
```
gcc main.c
```
(ebben a mappában letrejon egy a.out file, ellenőrizzük)


Futtassuk az új alkalmazást, es közben figyeljük a rendszer logot!
egyik terminal ablakban 
```
tail -f /etc/syslog
```
a masik terminálban 
```
./a.out
```
, ez egy beragado alkalmazas (végtelen ciklus)
