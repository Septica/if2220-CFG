/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

#ifndef __MESINTOKEN_H__
#define __MESINTOKEN_H__

#include "boolean.h"
#include "mesinkar.h"

#include <ctype.h>

#define NMax 50
#define BLANK ' '

typedef enum EToken {
  Program, 
  Var, Comma, Colon, Integer, Real, Char, Array, LBracket, RBracket, Range, Of, 
  Begin, End, Dot, 
  Plus, Minus, Times, Div, Mod, 
  L, G, LE, GE, EQ, NE, 
  And, Or, 
  Assignment, 
  If, Then, Else, 
  While, Do, 
  For, To, DownTo, Step, 
  Repeat, Until, 
  Input, Output, 
  Semicolon, 
  LParentheses, RParentheses,
  Alphanumeric
} Token;

typedef struct
{
  char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
  int Length;
} Kata;

typedef Kata Terminals[];

/* State Mesin Kata */
extern boolean EndToken;
extern Token CToken;
extern Kata CKata;
extern Terminals terminals;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN();
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken();
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int IsKataSama(Kata K1, Kata K2);
// Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama. Dua kata kosong adalah kata yang sama.

Token GetToken(Kata K);

#endif
