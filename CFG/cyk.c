#include "mesintoken.h"
#include "production.h"

#include <stdio.h>

#define NUnitProduction 46
#define NBiProduction 122
#define NMaxToken 1000
#define R 103

struct {
    Token tokens[NMaxToken];
    int n;
} input;

int P[NMaxToken][NMaxToken][R];

void PrintTable() {
    for (int i = input.n - 1; i >= 0; --i) {
        for (int j = 0; j < input.n; ++j) {
            int found = 0;
            for (int k = 0; k < R; ++k) {
                if (P[i][j][k]) {
                    found = 1;
                    printf("%03d", k);
                }
            }
            if (!found) printf("   ");
            printf(" ");
        }
        printf("\n");
    }
}

void CreateEmptyTable() {
    for (int i = 0; i < NMaxToken; ++i)
    {
        for (int j = 0; j < NMaxToken; ++j)
        {
            for (int k = 0; k < R; ++k)
            {
                P[i][j][k] = 0;
            }
        }
    }
}

void GetTokens() {
    input.n = 0;
    STARTTOKEN();
    while (!EndToken)
    {
        input.tokens[input.n++] = CToken;
        ADVTOKEN();
    }    
}

int main ()
{    
    GetTokens();
    CreateEmptyTable();

    for (int s = 0; s < input.n; ++s)
    {
        for (int v = 0; v < NUnitProduction; ++v)
        {
            if (input.tokens[s] == v)
            {
                P[0][s][v] = 1;
            }
        }
    }

    for (int l = 1; l < input.n; ++l)
    {
        for (int s = 0; s < input.n - l; ++s)
        {
            for (int p = 0; p < l; ++p)
            {
                for (int i = 0; i < NBiProduction; ++i)
                {
                    int a = productions[i].a;
                    int b = productions[i].b;
                    int c = productions[i].c;

                    if (P[p][s][b] && P[l - p - 1][s + p + 1][c])
                    {
                        P[l][s][a] = 1;
                    }
                }
            }
        }
    }

    if (P[input.n - 1][0][NUnitProduction])
        printf("Input Accepted.\n");
    else {
        printf("Input Rejected.\n");
    }

    //PrintTable();printf("\n");
}