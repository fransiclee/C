#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float calculateSD(float number[],int numberEnter) {
    float sum = 0.0;
    float mean = 0.0;
    float sumOfPow = 0.0;
    int i;

    for (i = 0; i < numberEnter ; ++i) {
        sum += number[i];
    }
    mean = sum / (float)numberEnter;
    for (i = 0; i < numberEnter; ++i) {
        sumOfPow += pow(number[i] - mean, 2);
    }


    return sqrt(sumOfPow / (float)(numberEnter-1));
}

int main() {
    int numberEnter = 0;
    float number[20];

    printf("How many numbers do you want to enter?");
    scanf("%d",&numberEnter);

    
    for (int i = 0; i < numberEnter; ++i) {
        printf("Enter your %d number:",i+1);
        scanf("%f", &number[i]);
    }

    printf("\nStandard Deviation = %.6f", calculateSD(number,numberEnter));
    return 0;

 
}