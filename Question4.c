#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BOOK
{
	char isbn_13[15];
	char title[100];
	char author[5][50];
	char publisher[50];
	int publish_year;
	char subject[20];
	char book_id[5];

}Books ;

void getBookInfo(struct BOOK *book) {
	strcpy(book->isbn_13, "978-0131103627");
	strcpy(book->title, "C Programming Language");
	strcpy(book->publisher, "Prentice Hall");
	strcpy(book->author, "Brian W. Kernighan, Dennis Ritchie");
	book->publish_year = 1998;
	strcpy(book->subject, "Computer Science");
	strcpy(book->book_id, "00034");
}

void printBookInfo(struct BOOK *book) {


	printf("ISBN_13 : %s\n", book->isbn_13);
	printf("Book Title : %s\n", book->title);
	printf("Author : %s\n", book->author);
	printf("Publisher : %s\n", book->publisher);
	printf("Publish Year : %d\n", book->publish_year);
	printf("Subject : %s\n", book->subject);
	printf("Book_id : %s\n", book->book_id);
}

void bookCopy(struct BOOK *book, struct BOOK *book1) {
	strcpy(book1->isbn_13, book->isbn_13);
	strcpy(book1->title, book->title);
	strcpy(book1->publisher, book->publisher);
	strcpy(book1->author, book->author);
	book1->publish_year = book->publish_year;
	strcpy(book1->subject, book->subject);
	strcpy(book1->book_id, book->book_id);
}


int sameBook(struct BOOK* book, struct BOOK* book1) {
	if (strcmp(book->isbn_13, book1->isbn_13) == 0&& strcmp(book->title, book1->title) == 0) {
		return 1;
	}
	return 0;
}

int samePublisher(struct BOOK* book, struct BOOK* book1) {
	if (strcmp(book->publisher, book1->publisher)==0) {
		return 1;
	}
	return 0;
	}




int main() {

	Books book,book1;


	getBookInfo(&book);
	printf("Book:\n");
	printBookInfo(&book);
	printf("**********************************************************************\n");
	bookCopy(&book, &book1);
	
	
	printf("Book1:\n");
	printBookInfo(&book1);
	
	printf("**********************************************************************\n");
	if (samePublisher(&book, &book1)) {
		printf("True, ISBN and the Title of book and book1 are equal.\n");
	}
	else {
		printf("False, ISBN and the Title of book and book1 are not equal.\n");
	}



	printf("**********************************************************************\n");
	if (samePublisher(&book, &book1)) {
		printf("True, they are from the same publisher.");
	}
	else {
		printf("False, they are not from the same publisher.");
	}


	return 0;
}
