#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void largest(int studentMark[], int n)
{
	int i = 0;
	int j = 0;
	int max = studentMark[0];


	for (i = 1; i < n; i++)
		if (studentMark[i] > max) {
			max = studentMark[i];
			j = i + 1;
		}
	printf("***********************************************************************************\n");
	printf("Student %d answered the most questions correctly with %d answers correct.\n", j, max);
	return 0;
}

int main()
{

	int i;
	int j;
	char mark[8][10];
	char answer[10];
	int correctNum = 0;
	int studentMark[8];
	int n = sizeof(studentMark) / sizeof(studentMark[0]);

	FILE* markFile = fopen("mark.txt", "r");
	FILE* answerFile = fopen("answer.txt", "r");

	if (markFile == NULL || answerFile == NULL)
	{
		printf("Error!Can't find the document");
		exit(1);
	}

	//get mark

	printf("Student answer:\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 10; j++) {
			fscanf(markFile, "%c\t", &mark[i][j]);
		}
	}



	for (i = 0; i < 8; i++) {
		for (j = 0; j < 10; j++) {
			printf("%2c", mark[i][j]);
		}
		printf("\n");
	}


	//get answer 
	printf("Correct answer:\n");
	for (i = 0; i < 10; i++) {
		fscanf(answerFile, "%c\t", &answer[i]);
	}

	for (i = 0; i < 10; i++) {
		printf("%2c", answer[i]);

	}
	printf("\n");
	//compare answer
	printf("\n***********************************************************************************\n");
	printf("\nMark:\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 10; j++) {
			if (mark[i][j] == answer[j]) {
				correctNum++;

			}

		}
		studentMark[i] = correctNum;
		/*printf("%d\n", studentMark[i]);*/
		printf("Student %d get %d answers correct.\n\n", i + 1, correctNum);
		correctNum = 0;
	}

	//find out who answer most correctly.
	largest(studentMark, n);


	fclose(markFile);
	fclose(answerFile);

}