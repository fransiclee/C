#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

struct library
{
	int bookNumber;
	char accessionNumber[50];
	char title[50];
	char author[50];
	double price;
	int flag;/*flag = 0 : N and,flag =  1: Y*/
}books[50] = {
1,"1789349915", "Learn C Programming : ","Jeff Szuhay", 45.99, 1,
2,"131103628", " C Programming Language", "Brian Kernighan and Dennis Ritchie", 83.75, 1,
3,"393979504", "C Programming : A Modern Approach", "K.King", 132.58, 0,
4,"111974024X", "C Programming For Dummies", "Dan Gookin", 35.23, 1,
5,"321776410", "Programming in C", "Stephen Kochan", 52.78, 0,
6,"72121246", "C : The Complete Reference", "Herbert Schildt", 40.66, 1,
};


int count()
{
	int i = 0;
	while (books[i].bookNumber)
		i++;
	return i;
}

void addBook()
{
	int next = count();
	
	/*fflush(stdin) or while(getch() != '\n'); to clear the buffer*/
	/*while (getchar() != '\n');*/
	printf("\nEnter the accession number : ");
	gets_s(books[next].accessionNumber, 49);
	printf("\nEnter the title of the book : ");
	gets_s(books[next].title,49);
	printf("\nEnter the author name of the book : ");
	gets_s(books[next].author,49);
	printf("\nEnter the price of the book : ");
	scanf("%.2lf", &books[next].price);
	printf("\nEnter the flag of the book : ");
	scanf("%.d", &books[next].flag);
	
}

void display(int i)
{
	i--;/*To use i as index*/
	printf("\n\n\n");
	printf("\nAccession Number : %d", books[i].accessionNumber);
	printf("\nTitle : %s", books[i].title);
	printf("\nAuthor : %s", books[i].author);
	printf("\nPrice : $  %.2lf", books[i].price);
	if (books[i].flag)
		printf("\nFLAG : Y");
	else
		printf("\nFLAG : N");
}


void listAurthor() {
	for (int i = 0; i < 6; i++) {
		printf("\nAuthor : %s", books[i].author);
	}
}

void listTitle(int an) {
	int i = 0;
	while (books[i].bookNumber)
	{
		if (books[i].bookNumber == an)
		{
			printf("\n\nTitle of the book : %s\n", books[i].title);
			return;
		}
	}
	printf("No any book found found\n");
}

void listBooks() {
	printf("not sure how to do this one....");
}

int main() {

	int answer = 0;
	int an = 0;
	while (answer != 7) {
		printf("\n--------------------MENU--------------------\n");
		printf("\n1. Add Book Information");
		printf("\n2. Display Book Information");
		printf("\n3. List all books of given author");
		printf("\n4. List the title of specified book");
		printf("\n5. List the counts of the books in library");
		printf("\n6. List the books in order of accession number");
		printf("\n7. Exit");
		printf("\n\n\t\tEnter you choice : ");
		scanf("%d", &answer);
		switch (answer) {
		case 1:
			addBook();
			break;
		case 2:
			printf("\nEnter the accession number of the book : ");
			scanf("%d", &an);
			display(an);
			break;
		case 3:
			listAurthor();
			break;
		case 4:
			printf("\nEnter the number of the book : ");
			scanf("%d", &an);
			listTitle(an);
		case 5:
			printf("\nTotal Number of books : %d", count());
			break;
		case 6:
			listBooks();
			break;
		case 7:
			return 0;
			

		}
	}

	

}