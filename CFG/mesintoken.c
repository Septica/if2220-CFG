/* File: mesintoken.c */
/* Implementasi Mesin Token: Model Akuisisi Versi I */

#include "mesintoken.h"
#include "constkata.h"
#include <stdio.h>

/* State Mesin Token */
boolean EndToken;
Token CToken;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (isspace(CC) && !EOP)
    {
        ADV();
    }
}

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
    START();
    IgnoreBlank();
    if (EOP)
    {
        EndToken = true;
    }
    else /* CC != MARK */
    {
        EndToken = false;
        SalinToken();
    }
}

void ADVTOKEN()
/* I.S. : CC adalah karakter sesudah karakter terakhir dari Token yang sudah diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama sesudah karakter terakhir Token
          Jika CC = MARK, maka EndToken = true.
   Proses : Akuisisi Token menggunakan procedure SalinToken */
{   /* Kamus Lokal */
    /* Algoritma */
    IgnoreBlank();
    if (EOP)
    {
        EndToken = true;
    }
    else /* CC != MARK */
    {
        SalinToken();
    }
}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Token melebihi NMax, maka sisa Token "dipotong" */
{   /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (isalnum(CC)) {
        for (i = 0; i < NMax; ++i)
        {
            CKata.TabKata[i] = tolower(CC);

            ADV();
            if (isspace(CC) || (EOP) || ispunct(CC))
            {
                break;
            }
        } /* CC = MARK or CC = BLANK */
    } else {
        i = 0;
        CKata.TabKata[i] = CC;

        ADV();

        if (!EOP) {
            if (((CKata.TabKata[i] == '<') || (CKata.TabKata[i] == '>') || (CKata.TabKata[i] == ':')) && (CC == '=')) {
                CKata.TabKata[++i] = CC;

                ADV();
            } else if ((CKata.TabKata[i] == '<') && (CC == '>')) {
                CKata.TabKata[++i] = CC;

                ADV();
            } else if ((CKata.TabKata[i] == '.') && (CC == '.')) {
                CKata.TabKata[++i] = CC;

                ADV();
            }
        }
    }
    CKata.Length = i+1;
    CToken = GetToken(CKata);
}

int IsKataSama(Kata K1, Kata K2)
// Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama. Dua kata kosong adalah kata yang sama. }
{
	if (K1.Length == K2.Length)
	{
		for (int i = 0; i < K1.Length; ++i)
		{
			if (K1.TabKata[i] != K2.TabKata[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

Token GetToken(Kata K)
{
    int i;
    for (i = 0; i < sizeof(terminals)/sizeof(terminals[0]); ++i) {
        if (IsKataSama(K, terminals[i])) return i;
    }
    return i;
}