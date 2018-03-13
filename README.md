# Tugas II. IF 2220 Teori Bahasa & Otomata

Aplikasi yang akan membuka file yang berisi sintaks program dan kemudian memeriksa apakah sintaks pada program tersebut valid atau tidak menggunakan tabel parser dengan acuan CNF.

Program sederhana yang dimaksud merupakan subset dari bahasa pemograman Pascal. Sintaks yang dimiliki terdiri atas:
1. Bagian nama program.  
Contoh:  
~~~
Program test1;
~~~

2. Bagian deklarasi variable. Tipe data yang dikenali hanya integer, real, char, array 1 dimensi dan array 2 dimensi. Tipe bentukan tidak termasuk.  
Contoh:  
~~~
Var
    X: integer;
~~~
3. Bagian Begin – end sebagai batas awal dan akhir dari program
4. Operator matematika (hanya operasi matematika untuk integer yaitu +, -, *, div, mod)
5. Kondisi (dengan operator: <, >, <=, >=, =, <>)
6. Ekspresi logik (and dan or)
7. Bagian isi program yang berisi hanya statement di bawah ini:
  * Statement assignment  
Contoh:  
~~~
a := b + c
~~~
  * Statement if-then-else beserta variannya, yaitu:  
~~~
If – then {begin end}  
If – then {begin end} – else {begin end}  
If – then {begin end} – else if – then {begin end} – else {begin end}
~~~
  * Statement while  
~~~
While (kondisi) – do {begin end}
~~~
  * Statement for beserta variannya, yaitu:  
~~~
For (variabel = constant to constant) do {begin end}  
For (variabel = constant downto constant) do {begin end}  
For (variabel = constant to constant step constant ) do {begin end}  
For (variabel = constant downto constant step constant) do {begin end}
~~~
  * Statement repeat  
~~~
Repeat – until (kondisi);
~~~
  * Statement input/output  
Contoh:  
~~~
Input(x)
Output(x)
~~~
