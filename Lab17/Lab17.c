#include "Header.h"

#define Massiv 20
int a[Massiv];
int n = 0;

void number0() {
	printf("\nñêîëüêî ýëåìåíòîâ = ");
	scanf_s("%d", &n);
	if (n <= 20) printf("\nçàïîëíÿåì\n");
	else printf_s("\nìíîãî");
	for (int i = 0; i < n; i++) { 
		scanf_s("%d", &a[i]); 
	}
	printf("\nçàïîëíåíî\n");
	
}
void number1() {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
void number2() {
	int elementindex; int l = 0;
	printf("óäàëèòü ýëåìåíò íîìåð \n");
	scanf_s("%d", &elementindex);
	int b[20];
	for (int i = 0; i < n; i++) {
		if (i < elementindex - 1) {
			b[i] = a[i];
		}
		if (i == elementindex - 1) { continue; }
		if (i > elementindex - 1) {
			b[i - 1] = a[i];
		}
		l++;
	}
	n = l;
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}
}
void number3() {
	int element, elementindex; 
	printf("íà êàêîå ìåñòî âñòàâèòü? ");
	scanf_s("%d", &elementindex);
	printf("÷èñëî = ");
	scanf_s("%d", &element);
	int b[20];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	n++;
	for (int i = 0; i < n; i++) {
		if (i < elementindex - 1) {
			a[i] = b[i];
		}
		if (i == elementindex - 1) {
			a[i] = element;
		}
		if (i > elementindex - 1) {
			a[i] = b[i - 1];
		}
	}
}
int findMin() {
	int indexofmin = 0; int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			indexofmin = i;
		}
	}
	return indexofmin;
}
void number4() {
	int indexofmin = findMin();
	int b[20];
	for (int i = 0; i < n; i++) { b[i] = a[i]; }
	n--;
	for (int i = 0; i <= n; i++) {
		if (i < indexofmin) {
			a[i] = b[i];
		}
		if (i == indexofmin) { continue; }
		if (i > indexofmin) {
			a[i - 1] = b[i];
		}
	}
}
void number5() {
	int indexofmin = findMin();
	for (int i = 0; i < n; i++) {
		if (i < indexofmin) a[i] = 0;
	}
}
void number6() {
	int b[20], k = 0, k2 = 0;
	for (int i = 0; i < n; i++) { 
		b[i] = a[i];
		if (a[i] % 2 == 0) k++;
	}
	for (int i = 0; i < Massiv; i++) { a[i] = 0; }
	//n -= k;
	for (int i = 0; i < n; i++) {
		if (b[i] % 2 != 0) {
			a[i - k2] = b[i];
		}
		if (b[i] % 2 == 0) {
			k2++;
		}
	}
	n -= k;
	for (int i = 0; i < n; i++) { a[i] = a[i]; }
}



void main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int number;
	do {
		printf("\n0 - ââåñòè ìàññèâ\n");
		printf("1 - âûâåñòè ìàññèâ\n");
		printf("2 - óäàëèòü ýëåìåíò\n");
		printf("3 - âñòàâèòü ýëåìåíò\n");
		printf("4 - óäàëèòü ìèíèìàëüíûé\n");
		printf("5 - ñäåëàòü íîëü ïåðåä ìèíèìàëüíûì\n");
		printf("6 - óäàëèòü ÷¸òíûé\n");
		printf("\níîìåð = ");
		scanf_s("%d", &number);
		switch (number)
		{
		case 0:
			number0();
			break;
		case 1:
			number1();
			break;
		case 2:
			number2();
			break;
		case 3:
			number3();
			break;
		case 4:
			number4();
			break;
		case 5:
			number5();
			break;
		case 6:
			number6();
			break;
		default:
			return;
		}
	} while (1);
}
