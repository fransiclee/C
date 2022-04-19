/*
 ============================================================================
 Name        : IPC144Assignment3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Birthday {
	int bitrhYear;
	int birthMonth;
	int birthDay;
};

struct Phone {
	char homePhone[10];
	char workPhone[10];
	char mobilePhone[10];
};

struct HomeAddress {
	char address1[50];
	char address2[50];
	char city[30];
	char provinces[3];
	char postalCode[6];
};

struct JobAndIncome {
	int jobCategory;
	char jobDescription[50];
	long yearlyPersonalIncome;
	long personalIncome;
	long otherHouseholdIncome;
	int paymentForHousing;
};

struct Customer {
	char firstName[30];
	char lastName[30];
	int dateOfBirth; //MM/DD/YY
	struct Birthday bd;
	int age;
	char emailAddress[50];
	struct Phone p;
	struct HomeAddress ha;
	struct JobAndIncome jai;
	int livingSituation;
	int livingYear[3];
	int livingMonth;
	char sin[9];
} c;

void getFirstName(char firstName[30]) {
	printf("\nPlease enter your first name/given name \n");
	scanf("%s", firstName);
}

void getLastName(char lastName[30]) {
	printf("\nPlease enter your last name/family name \n");
	scanf("%s", lastName);
}

int checkName(char name[]) {
	int i = 0;
	if (strlen(name) < 2) {
		printf("\nYou'll need to enter at least 2 letters.");
		return 0;
	}

	for (i = 0; i < strlen(name); i++) {
		char value = name[i];
		if (!(('A' <= value && value <= 'Z') || ('a' <= value && value <= 'z'))) {
			return 0;
		}
	}
	return 1;
}

void getCardNumber(char cardNumber[16]) {
	printf("\nPlease enter your card number \n");
	scanf("%s", cardNumber);
}

int checkCardNumber(char cardNumber[]) {
	int i = 0;
	for (i = 0; i < strlen(cardNumber); i++) {
		char value = cardNumber[i];
		if (value < '0' || value > '9') {
			return 0;
		}
	}
	if (strlen(cardNumber) != 16) {
		return 0;
	}
	return 1;
}

void getPassword(char password[]) {
	printf("\nPlease create your password: \n");
	scanf("%s", password);
}

int checkPassword(char *password) {
	int i;
//at least 8 characters long
	char passwords = 0;
	passwords = *password;
	if (strlen(password) < 8) {
		return 0;
	}

//find mix
	int foundLower = 0; /* "boolean" integers */
	int foundUpper = 0;
	for (i = 0; i < strlen(password); ++i) /* Loop over the entire string */
	{
		if (password[i] >= 'a' && password[i] <= 'z') /* Check for lowercase */
			foundLower = 1;
		if (password[i] >= 'A' && password[i] <= 'Z') /* Compare uppercase */
			foundUpper = 1;
	}
	if (foundLower == 1 && foundUpper == 0)/* if only lower case, return 0 */
		return 0;
	if (foundLower == 0 && foundUpper == 1)/* if only upper case, return 0 */
		return 0;

	return 1;
}

int getDateOfBirth(int dateOfBirth) {
	printf("\nPlease enter your date of birth (yyyymmdd):");
	scanf("%d", &dateOfBirth);
	return dateOfBirth;
}

int checkDateOfBirth(int dateOfBirth) {
	int year = dateOfBirth / 10000;
	int month = (dateOfBirth % 10000) / 100;
	int day = dateOfBirth % 100;

	if (1900 <= year && year <= 2022) {
		if (1 <= month && month <= 12 && 1 <= day && day <= 31) {
			return 1;
		}
		return 0;
	}
	return 1;
}


int getAge(int dateOfBirth) {
	int year = dateOfBirth / 10000;
	int month = (dateOfBirth % 10000) / 100;
	int cyear = 0;
	int age = 0;

	time_t now;

	time(&now);

	struct tm *local = localtime(&now);
	cyear = local -> tm_year + 1900;

	if (month <= 3) {
		age = cyear - year;
	}
	else {
		age = cyear - year - 1;
	}


	return age;
}

int checkAge(int age) {
	if (age < 1000) {
		return 1;
	}
	return 0;
}

void getEmailAddress(char emailAddress[50]) {
	printf("\nPlease enter your email address (emailaddress@domain.com) \n");
	scanf("%s", emailAddress);
}

int checkEmailAddress(char emailAddress[]) {
	int i = 0;
	if (strlen(emailAddress) < 2) {
		return 0;
	}

	int temp = 0;
	for (i = 0; i < strlen(emailAddress); i++) {
		char value = emailAddress[i];
		if (value == '@') {
			temp++;
		}
		if (value == '.') {
			temp += 10;
		}
	}
	if (temp == 11) {
		return 1;
	}
	return 0;
}

//sub function get address 1
void getAddress1(char address1[50]) {
	printf("\nPlease enter your first address: ");
	fgets(address1, 50, stdin);
	address1[strlen(address1)-1]='\0';
}
//sub function get address 2
void getAddress2(char address2[]) {
	printf("\nPlease enter your second address: ");
	fgets(address2, 50, stdin);
	address2[strlen(address2)-1]='\0';
}
//sub function get city
void getCity(char city[]) {
	printf("\nPlease enter your city: ");
	fgets(city, 30, stdin);
	city[strlen(city)-1]='\0';
}

//sub function valid address 1
int checkAddress1(char address1[50]) {
	int i;
	if (strlen(address1) < 2) {
		return 0;
	}
	for (i = 0; i < strlen(address1); i++) {
		char address = address1[i];
		if (!(('A' <= address && address <= 'Z')
				|| ('a' <= address && address <= 'z') || (address == ' '))) {
			return 0;
		}
	}
	return 1;
}
//sub function valid address 2

int checkAddress2(char address2[]) {
	int i;

	if (strlen(address2) < 2) {
		return 0;
	}
	for (i = 0; i < strlen(address2); i++) {
		char address = address2[i];
		if (!(('A' <= address && address <= 'Z')
				|| ('a' <= address && address <= 'z') || (address == ' '))) {
			return 0;
		}
	}
	return 1;
}
//sub function valid city
int checkCity(char city[]) {
	int i;

	if (strlen(city) < 2) {
		return 0;
	}
	for (i = 0; i < strlen(city); i++) {
		char city1 = city[i];
		if (!(('A' <= city1 && city1 <= 'Z') || ('a' <= city1 && city1 <= 'z') || (city1 == ' '))) {
			return 0;
		}
	}
	return 1;
}

void getProvinces(char provinces[]) {
	printf("\nPlease enter your provinces(must be capitalized): ");
	scanf("%s", provinces);
}

int checkProvinces(char provinces[]) {
	char provinces0[] = "AB";
	char provinces1[] = "BC";
	char provinces2[] = "MB";
	char provinces3[] = "NB";
	char provinces4[] = "NL";
	char provinces5[] = "NT";
	char provinces6[] = "NS";
	char provinces7[] = "NU";
	char provinces8[] = "ON";
	char provinces9[] = "PE";
	char provinces10[] = "QC";
	char provinces11[] = "SK";
	char provinces12[] = "YT";
	if (strlen(c.ha.provinces) != 2) {
		return 0;
	}

	if (!strcmp(c.ha.provinces, provinces0)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces1)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces2)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces3)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces4)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces5)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces6)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces7)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces8)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces9)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces10)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces11)) {
		return 1;
	}
	if (!strcmp(c.ha.provinces, provinces12)) {
		return 1;
	}

	return 0;
}

//sub function get living situation
void getLivingSituation(int *livingsituation) {
	int option = 0;
	printf("\nPlease enter below number which represent your living situation(1-5).\n ");
	printf("\n1. Rent\n ");
	printf("\n2. Own/buying\n ");
	printf("\n3. Live with Parents\n ");
	printf("\n4. Room or Board\n ");
	printf("\n5. Other\n ");
	scanf("%d", &option);
	*livingsituation = option;
}

//sub function check living situation
int checkLivingSituation(int livingSituation) {
	if (livingSituation > 5 || livingSituation < 0) {
		return 0;
	}
	return 1;
}

void getSin(char sin[]) {
	printf("\nPlease enter your 9 digit Social insurance number: \n");
	scanf("%s", sin);
}

int checkSin(char sin[]) {
	int i;
	if (strlen(sin) != 9) {
		return 0;
	}
	for (i = 0; i < strlen(sin); i++) {
		int sinCheck = sin[i];
		if (!(9 <= sinCheck || sinCheck <= 0)) {
			return 0;
		}
	}
	return 1;
}

void getJobCategory(int *jobcategory) {
	int z = 0;
	printf("\nPlease choose your Job Category: \n");
	printf("\n1. Business and Finance. \n");
	printf("\n2. Arts, Audio/Video Technology, and Communication. \n");
	printf("\n3. Architecture and Construction. \n");
	printf("\n4. Agriculture, Food, and Natural Resources. \n");
	printf("\n5. Information Technology. \n");
	scanf("%d", &z);
	*jobcategory = z;
}

int checkJobCategory(int jobCategory) {
	if (jobCategory > 5 || jobCategory < 0) {
		return 0;
	}
	return 1;
}

int getPaymentForHousing(int paymentForHousing) {
	printf("\nHow much do you pay for housing per month (amount only)? $ ");
	scanf("%d", &paymentForHousing);
	return paymentForHousing;
}

int checkPaymentForHousing(int paymentForHousing) {
	if (paymentForHousing >= 0 && paymentForHousing < 10000) {
		return 1;
	}
	return 0;
}

long getYearlyPersonalIncome(long personalIncome) {
	printf("\nWhat is your personal yearly income (amount only): $ ");
	scanf("%ld", &personalIncome);
	return personalIncome;
}

long getYearlyOtherHouseholdIncome(long otherHouseholdIncome) {
	printf("\nWhat is your other household income per year (amount only): $ ");
	scanf("%ld", &otherHouseholdIncome);
	return otherHouseholdIncome;
}

long checkYearlyIncome(long personalIncome, long otherHouseholdIncome) {
	if (personalIncome <= 0 || personalIncome > 100000000
			|| otherHouseholdIncome < 0 || otherHouseholdIncome > 100000000) {
		return 0;
	}
	return 1;
}

long long int getCustomerID(long long int customerID) {
	int i = 0;
	for (i = 0; i < 8; i++) {
		customerID = customerID*10 + rand() % 10;
	}
	printf("\nYour customer ID is %lld", customerID);
	return customerID;
}

//get new card number

int getRandomDigit() {
	return rand() % 10;
}

void getNewCardNumber(char cardNumber[], int size) {
	for (int i = 0; i < size; i++) {
		cardNumber[i] = '0' + getRandomDigit();
	}
	cardNumber[size] = '\0';
}

void printArray(char array[]) {
	int i;
	for (i = 0; i < strlen(array); i++) {
		printf("%c", array[i]);
	}
}

//MAIN-------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	setbuf(stdout, NULL);
	srand(time(NULL));
	char answer;
	char cardNumber[16];
	char passwords[8];
	char *password = passwords;
	int dateOfBirth = 0;
	long long int customerID = 0;
	int validAddress1 = 0;
	int validAddress2 = 0;
	int validCity = 0;
	int validProvinces = 0;
	int validLivingSituation = 0;
	int valid = 0;
	FILE* fptr;
	
	if ((fptr = fopen("C:\\francisle\\ass4.bin", "wb")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	

		while (valid == 0) {
			printf("\nAre you an existing client? Enter Y or N: ");
			scanf("%c", &answer);
			if (answer == 'Y' || answer == 'y' || answer == 'N' || answer == 'n') {
				valid = 1;
			}
			else {
				valid = 0;
			}
		}

		if (answer == 'Y' || answer == 'y') {
			int valid = 0;
			while (valid == 0) {
				int incorrectTimes = 0;
				while (!valid && incorrectTimes < 3) {
					getCardNumber(cardNumber);
					if (checkCardNumber(cardNumber) == 0) {
						printArray(cardNumber);
						printf("\nis not a valid card number.\n");
						incorrectTimes++;
						if (incorrectTimes >= 3) {
							printf(
								"\nIncorrect card number or password. Please try again tomorrow.");
							return 0;
						}
					}
					else {
						// compare to data base and pair card number with password
						printArray(cardNumber);
						valid = 1;
					}
				}
			}

			int validPassword = 0;

			while (!validPassword) {
				getPassword(password);
				if (!checkPassword(password)) {
					printf("\n%s is not a valid password.\n", password);
					validPassword = 0;
				}
				else {
					printf("\n%s is valid password.\n", password);
					validPassword = 1;
				}
			}
		}

		//generate a new card number and have client to setup password, then input in the data base

		else {
			int valid = 0;
			while (valid == 0) {
				srand(time(NULL));

				char newCardNumber[17];

				getNewCardNumber(newCardNumber, 17);

				printf("Your new card number is ");
				printArray(newCardNumber);

				getCustomerID(customerID);

				int validPassword = 0;

				while (!validPassword) {
					getPassword(password);
					if (!checkPassword(password)) {
						printf("\n%s is not a valid password.\n", password);
						validPassword = 0;
					}
					else {
						printf("\n%s is valid password.\n", password);
						validPassword = 1;
					}
				}
				valid = 1;
			}
		}

		valid = 0;
		while (!valid) {
			getFirstName(c.firstName);
			if (!checkName(c.firstName)) {
				printArray(c.firstName);
				printf(" is not a valid first name.\n");
				valid = 0;
			}
			else {
				printArray(c.firstName);
				printf(" is valid first name.\n");
				valid = 1;
			}
		}

		valid = 0;
		while (!valid) {
			getLastName(c.lastName);
			if (!checkName(c.lastName)) {
				printArray(c.lastName);
				printf(" is not a valid last name.\n");
				valid = 0;
			}
			else {
				printArray(c.lastName);
				printf(" is valid last name.\n");
				valid = 1;
			}
		}

		valid = 0;
		while (!valid) {
			dateOfBirth = getDateOfBirth(dateOfBirth);
			if (!checkDateOfBirth(dateOfBirth)) {
				printf("\n%d is not a valid date of birth. \n", dateOfBirth);
				valid = 0;
			}
			else {
				printf("\nYou are eligible to apply for a credit card. \n");
				valid = 1;
			}
		}

		valid = 0;
		c.age = getAge(dateOfBirth);
		while (c.age < 18) {
			printf(" You need to be at least 18 to apply for a credit card.");
			return 0;
		}

		valid = 0;
		while (!valid) {
			getEmailAddress(c.emailAddress);
			if (!checkEmailAddress(c.emailAddress)) {
				printArray(c.emailAddress);
				printf("is not a valid email address.\n");
				valid = 0;
			}
			else {
				printArray(c.emailAddress);
				printf("is valid email address.\n");
				valid = 1;
			}
		}


		//enter and valid Address 1
		while (!validAddress1) {
			getAddress1(c.ha.address1);
			if (!checkAddress1(c.ha.address1)) {
				printf("\n%s is not a valid first address.\n", c.ha.address1);
				validAddress1 = 0;
			}
			else {
				printf("\n%s is valid first address.\n", c.ha.address1);
				validAddress1 = 1;
			}
		}

		//enter and valid Address 2
		while (!validAddress2) {
			getAddress2(c.ha.address2);
			if (!checkAddress2(c.ha.address2)) {
				printf("\n%s is not a valid second address.\n", c.ha.address2);
				validAddress2 = 0;
			}
			else {
				printf("\n%s is valid second address.\n", c.ha.address2);
				validAddress2 = 1;
			}
		}

		//enter and valid city
		while (!validCity) {
			getCity(c.ha.city);
			if (!checkCity(c.ha.city)) {
				printf("\n%s is not a valid city.\n", c.ha.city);
				validCity = 0;
			}
			else {
				printf("\n%s is valid city.\n", c.ha.city);
				validCity = 1;
			}
		}

		while (!validProvinces) {
			getProvinces(c.ha.provinces);
			if (!checkProvinces(c.ha.provinces)) {
				printf("\n%s is not a valid provinces", c.ha.provinces);
				validProvinces = 0;
			}
			else {
				printf("\n%s is your provinces", c.ha.provinces);
				validProvinces = 1;
			}
		}

		while (!validLivingSituation) {
			getLivingSituation(&c.livingSituation);
			if (!checkLivingSituation(c.livingSituation)) {
				printf("\n%d is not a valid living situation.\n",
					c.livingSituation);
				validLivingSituation = 0;
			}
			else {
				printf("\n%d is your living situation.\n", c.livingSituation);
				validLivingSituation = 1;
			}
		}

		valid = 0;
		while (!valid) {
			getSin(c.sin);
			if (!checkSin(c.sin)) {
				printArray(c.sin);
				printf(" is not a valid SIN. \n");
				valid = 0;
			}
			else {
				printArray(c.sin);
				printf(" is a valid SIN. \n");
				valid = 1;
			}
		}

		valid = 0;
		while (!valid) {
			getJobCategory(&c.jai.jobCategory);
			if (!checkJobCategory(c.jai.jobCategory)) {
				printf("\n%d is not a valid job category.\n", c.jai.jobCategory);
				valid = 0;
			}
			else {
				printf("\n%d is valid job category.\n", c.jai.jobCategory);
				valid = 1;
			}
		}

		valid = 0;
		while (!valid) {
			c.jai.paymentForHousing = getPaymentForHousing(c.jai.paymentForHousing);
			if (!checkPaymentForHousing(c.jai.paymentForHousing)) {
				printf("\n%d is not a valid amount.\n", c.jai.paymentForHousing);
				valid = 0;
			}
			else {
				printf("\n%d is your payment for housing.\n",
					c.jai.paymentForHousing);
				valid = 1;
			}
		}

		valid = 0;
		c.jai.personalIncome = getYearlyPersonalIncome(c.jai.personalIncome);
		c.jai.otherHouseholdIncome = getYearlyOtherHouseholdIncome(c.jai.otherHouseholdIncome);
		while (!valid) {
			if (!checkYearlyIncome(c.jai.personalIncome, c.jai.otherHouseholdIncome)) {
				printf("\n%ld is not a valid personal income, %ld is not a valid other household income.",
					c.jai.personalIncome, c.jai.otherHouseholdIncome);
				valid = 0;
			}
			else {
				if (c.jai.personalIncome < 15000) {
					printf("\nYour personal income need to be at least $15,000 to apply for the credit card.");
					return 0;
				}
				printf(
					"\nYour personal income is $%ld, other household income is $%ld.\n",
					c.jai.personalIncome, c.jai.otherHouseholdIncome);
				valid = 1;
			}
		}

		printf(
			"\n\n\n**********************************Summary***********************************************\n");
		printf("\nFirst name is ");
		printArray(c.firstName);
		printf("\nLast name is %s", c.lastName);
		printf("\nDate of birth: %d", dateOfBirth);
		printf("\nAge: %d", c.age);
		printf("\nEmail is ");
		printArray(c.emailAddress);
		printf("\nAddress1: %s.", c.ha.address1);
		printf("\nAddress2: %s.", c.ha.address2);
		printf("\nCity: %s.", c.ha.city);
		printf("\nProvince: %s", c.ha.provinces);
		if (c.livingSituation == 1) {
			printf("\nLiving situation: Rent.");
		}
		else if (c.livingSituation == 2) {
			printf("\nLiving situation: Own/buying.");
		}
		else if (c.livingSituation == 3) {
			printf("\nLiving situation: Live with Parents.");
		}
		else if (c.livingSituation == 4) {
			printf("\nLiving situation: Room or Board.");
		}
		else if (c.livingSituation == 5) {
			printf("\nLiving situation: Other");
		}
		printf("\nSin is %s.", c.sin);
		if (c.jai.jobCategory == 1) {
			printf("\nJob category: Business and Finance.");
		}
		else if (c.jai.jobCategory == 2) {
			printf(
				"\nJob category: Arts, Audio/Video Technology, and Communication.");
		}
		else if (c.jai.jobCategory == 3) {
			printf("\nJob category: Architecture and Construction.");
		}
		else if (c.jai.jobCategory == 4) {
			printf("\nJob category: Agriculture, Food, and Natural Resources.");
		}
		else if (c.jai.jobCategory == 5) {
			printf("\nJob category: Information Technology.");
		}
		printf("\n$%d is payment for housing.", c.jai.paymentForHousing);
		printf("\n$%ld is personal income, $%ld is other household income. \n",
			c.jai.personalIncome, c.jai.otherHouseholdIncome);
		printf(
			"\n*****************************************************************************************\n");
		printf("\n\nThank you for applying credit card with us!\n");
		printf("\nPlease feel free to contact us if you have any questions. \n");
	

	fclose(fptr);
	return 0;
}

