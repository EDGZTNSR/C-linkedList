#include <stdio.h>
#include <stdlib.h>

//Define the struct Person /*Dominic Pohland*/
typedef struct Person
{
	int Value;            /* der Wert des Elements */
	char Firstname[40];
	char Name[40];
	int Vintage;
	struct Person *pNext; /* Zeiger auf das n�chste Element */
} struPerson;

void printliste(const struct Person *e)
{
	for (; e != NULL; e = e->pNext)
	{
		printf("%d\n", e->Value);
	}
}

void append(struct Person **lst, int value)
{ 
	struct Person *newPerson;

	/* Zeiger auf die Einf�geposition ermitteln, d.h. bis zum Ende laufen */
	while (*lst != NULL)
	{
		lst = &(*lst)->pNext;
	}
	
	newPerson = malloc(sizeof(*newPerson)); /*Erzeugt ein neues Elemnet*/
	newPerson->Value = value;
	newPerson->pNext = NULL; 
	*lst = newPerson;
}

int main()
{
	struct Person *Liste;

	Liste = NULL;      /* init. die Liste mit NULL = leere Liste */
	append(&Liste, 1); /* f�ge neues Element in die Liste ein    */
	append(&Liste, 3); /* f�ge neues Element in die Liste ein    */
	append(&Liste, 2); /* f�ge neues Element in die Liste ein    */
	printliste(Liste); /* zeige alle Elemente der Liste an */ 

	return 0;
}