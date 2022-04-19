#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int i;
	int j;

	double rawData[20][3];
	double revenue[5][4];
	double sum = 0;
	double total = 0;
	double totals[4] = { 0 };


	FILE* rawFile = fopen("rawdata.txt", "r");

	if (rawFile == NULL)
	{
		printf("Error!Can't find the document");
		exit(1);
	}

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++) {
			fscanf(rawFile, "%lf\t", &rawData[i][j]);
		}
	}
	printf("RAW DATA\n******************************************************************************\n");
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.2lf\t", rawData[i][j]);
		}
		printf("\n");
	}


	//0—Emergency, 1—Medicine, 2—Oncology, 3—Orthopedics, 4—Psychiatry.


	//summer
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (rawData[j][0] == i) {
				revenue[i][0] = rawData[j][2];
				/*printf("%0.2lf\t", revenue[i][0]);*/
			}
		}
	}

	//fall  
	for (j = 5; j < 10; j++) {
		for (i = 0; i < 5; i++) {
			if (rawData[j][0] == i) {
				revenue[i][1] = rawData[j][2];
				/*printf("%0.2lf\t", revenue[i][0]);*/
			}
		}
	}

	//winter
	for (j = 10; j < 15; j++) {
		for (i = 0; i < 5; i++) {
			if (rawData[j][0] == i) {
				revenue[i][2] = rawData[j][2];
				/*printf("%0.2lf\t", revenue[i][0]);*/
			}
		}
	}

	//Spring
	for (j = 15; j < 20; j++) {
		for (i = 0; i < 5; i++) {
			if (rawData[j][0] == i) {
				revenue[i][3] = rawData[j][2];
				/*printf("%0.2lf\t", revenue[i][0]);*/
			}
		}
	}

	//print
	printf("\n******************************************************************************\n");
	printf("REVENUE SUMMARY\n---------------------------\n");
	printf("Unit\t\tSummer\t\tFall\t\tWinter\t\tSpring\t\tTOTAL*\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Emergency\t");
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 4; i++) {
			printf("%0.2lf\t", revenue[j][i]);
			sum += revenue[j][i];
		}
		sum = sum / 1000;
		printf("%.0lf", sum);
		sum = 0;
		printf("\n");
		if (j == 0) {
			printf("Medical\t\t");
		}
		if (j == 1) {
			printf("Oncology\t");
		}
		if (j == 2) {
			printf("Orthopedics\t");
		}
		if (j == 3) {
			printf("Psychology \t");
		}

	}

	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("TOTALS*\t");
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 5; i++) {
			total += revenue[i][j];
		}
		totals[i] = total / 1000;

		printf("\t%1.0lf\t", totals[i]);
		total = 0;
	}

}


