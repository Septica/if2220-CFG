#include "mesintoken.h"
#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	STARTTOKEN();
	while (!EndToken){
		switch (CToken) {
			case Program : printf("program\n"); break;
			case Var : printf("var\n"); break;
			case Comma : printf(",\n"); break;
			case Colon : printf(":\n"); break;
			case Integer : printf("integer\n"); break;
			case Real : printf("real\n"); break;
			case Char : printf("char\n"); break;
			case Array : printf("array\n"); break;
			case LBracket : printf("[\n"); break;
			case RBracket : printf("]\n"); break;
			case Range : printf("..\n"); break;
			case Of : printf("of\n"); break;
			case Begin : printf("begin\n"); break;
			case End : printf("end\n"); break;
			case Dot : printf(".\n"); break;
			case Plus : printf("+\n"); break;
			case Minus : printf("-\n"); break;
			case Times : printf("*\n"); break;
			case Div : printf("div\n"); break;
			case Mod : printf("mod\n"); break;
			case L : printf("<\n"); break;
			case G : printf(">\n"); break;
			case LE : printf(">=\n"); break;
			case GE : printf(">=\n"); break;
			case EQ : printf("=\n"); break;
			case NE : printf("<>\n"); break;
			case And : printf("and\n"); break;
			case Or : printf("or\n"); break;
			case Assignment : printf(":=\n"); break;
			case If : printf("if\n"); break;
			case Then : printf("then\n"); break;
			case Else : printf("else\n"); break;
			case While : printf("while\n"); break;
			case Do : printf("do\n"); break;
			case For : printf("for\n"); break;
			case To : printf("to\n"); break;
			case DownTo : printf("downto\n"); break;
			case Step : printf("step\n"); break;
			case Repeat : printf("repeat\n"); break;
			case Until : printf("until\n"); break;
			case Input : printf("input\n"); break;
			case Output : printf("output\n"); break;
			case Semicolon : printf(";\n"); break;
			case LParentheses : printf("(\n"); break;
			case RParentheses : printf(")\n"); break;
			default : printf("alphanumeric\n"); break;
		}
		
		ADVTOKEN();
	}
}
