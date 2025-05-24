//Прочитати текст приведеної вище програми на SPL, розпізнати лексеми і занести ідентифікатори в таблицю ідентифікаторів char TNM[400].
//Ідентифікатори та їхні адреси занести в файл.
// Завдання 1
// Ввести програму в комп’ютер і дослідити її роботу на прикладі приведеної вище програми мовою SPL

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

// Лексичний аналізатор інтерпретатора мови SPL
enum {
	BEGINL = 257, ENDL, IFL, THENL, WHILEL, DOL, RETRL, READL, PRITL, INTL,
	CONSTL, IDEN, NUMB
};

int nst = 0;
int lval, lex;
static char nch = '\n';
FILE* PF, * padres;
void get(void);
void number(void);
void word(void);
char* add(char* nm);
//**************************************

int main()

{
	PF=fopen("bbb.txt", "r");
	padres=fopen("getrez.txt", "w");
	if (!PF || !padres){
		puts("File bbb.txt isn't open ");
		puts("File getrez.txt isn't open");
	}
	else
		get();

	return 0;

}

// ***********************************

void get()
{
	while (nch != EOF)
	{
		while (isspace(nch))
		{
			if (nch == '\n')
				nst++;
			nch = getc(PF);
		}
		if (nch == '{') {
			lex = BEGINL;
			nch = getc(PF);
		}
		else if (nch == '}') {
			lex = ENDL;
			nch = getc(PF);
		}
		else if (isdigit(nch))
			number();
		else
			if (isalpha(nch))
				word();
			else
				if (nch == '(' || nch == ')' || nch == ',' || nch == ';' || nch == '='
					|| nch == '+' || nch == '-' || nch == '*' || nch == '/' || nch == '%')
				{
					lex = nch;
					nch = getc(PF);
				}

	}
	if (nch == EOF)
		lex = EOF;
	else
		puts("Invalid symbol");
	return;

}
//******************************************

void number()
{
	for (lval = 0; isdigit(nch); nch = getc(PF))
		lval = lval * 10 + nch - '0';
	lex = NUMB;
	return;
}
//******************************************

void word()
{
	static int cdl[] = { BEGINL,ENDL,IFL,THENL,WHILEL,DOL,RETRL,READL,
	PRITL,INTL,CONSTL,IDEN,NUMB };
	static const char* serv[] = { "{","}","if","then","while","do","return","read",
	"print","int","const" };
	int i;
	char tx[40];
	char* p;
	for (p = tx; isdigit(nch) || isalpha(nch); nch = getc(PF))
		*(p++) = nch;
	*p = '\0';
	for (i = 0; i < 11; i++)
		if (strcmp(tx, serv[i]) == 0)
		{
			lex = cdl[i];
			return;
		}
	lex = IDEN;
	lval = (int)add(tx);
	printf(" Address for %s =%p\n", tx, lval);
	fprintf(padres, "Address for %s =%p\n", tx, lval);
	return;
}

//********************************************
char TNM[400];
char* ptn = TNM;
char* add(char* nm)
{
	char* p;
	for (p = TNM; p < ptn; p += strlen(p) + 1)
		if (strcmp(p, nm) == 0)
			return p;
	if ((ptn += strlen(nm) + 1) > TNM + 400)
	{
		puts("Overload of TNM");
		exit(0);
	}
	strcpy(p, nm);
	return p;

}