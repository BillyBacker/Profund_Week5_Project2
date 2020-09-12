#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream> 

using namespace std;

void swap(int* In1, int* In2) {
	int in1 = *In1;
	int in2 = *In2;
	*In1 = in2;
	*In2 = in1;
}

int main() {
	int money[4] = {0, 0, 0, 0};
	int name[4] = { 'A', 'B' ,'C' , 'D'};
	char person = 0;
	int amount = 0;
	for (int i = 0; i < 4; i++) {
		printf("%c borrowed money from : ", 'A'+i);
		cin >> person;
		printf("Amount : ");
		cin >> amount;
		money[i] += amount;
		money[person - 'A'] -= amount;
		person = 0;
		amount = 0;
	}
	for (int round = 0; round < 16; round++) {
		for (int i = 0; i < 3; i++) {
			if (money[i] < money[i + 1]) {
				swap(&money[i], &money[i + 1]);
				swap(&name[i], &name[i + 1]);
			}
		}
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		if (money[i] > 0) {
			printf("%c place %d Bath on table.\n", name[i], money[i]);
		}
		else if (money[i] == 0) {
			printf("%c Does nothings.\n", name[i], money[i]);
		}
		else {
			printf("%c pick %d Bath from the table.\n", name[i], -money[i]);
		}
	}
	
	return 0;
}