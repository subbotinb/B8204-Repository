// дек двусвязный список.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
using namespace std;
struct dek {
	int value;
	struct dek *prev = NULL;
	struct dek *nxt = NULL;
	
};

struct dekInfo
{
	struct dek *head = NULL;
	struct dek *tail = NULL;
	int size = 0;
};
void lPush(dekInfo &dInf){
	dek *tmp =  (dek*) malloc(sizeof(dek));
	tmp->prev = NULL;
	tmp->nxt = NULL;
	dInf.size++;
	if (dInf.size == 1) {
		dInf.head = dInf.tail = tmp;

	}
	else {
		tmp->prev = dInf.head;
		dInf.head->nxt = tmp;
		dInf.head = tmp;
	}
	cout << "\n print value \n";
	cin >> tmp->value;
}
void RPush(dekInfo &dInf) {
	dek *tmp = (dek*)malloc(sizeof(dek));
	tmp->prev = NULL;
	tmp->nxt = NULL;
	dInf.size++;
	if (dInf.size == 1) {
		dInf.head = dInf.tail = tmp;

	}
	else {
		tmp->nxt = dInf.tail;
		dInf.tail->prev = tmp;
		dInf.tail = tmp;
	}
	cout << "\n print value \n";
	cin >> tmp->value;
}
void lPop(dekInfo &dInf) {
	dInf.head = dInf.head->prev;
	free(dInf.head->nxt);
	dInf.head->nxt = NULL;
}
void RPop(dekInfo &dInf) {
	dInf.tail = dInf.tail->nxt;
	free(dInf.tail->prev);
	dInf.tail->prev = NULL;
}
void printDek(dekInfo dInf) {
	cout << "\n";
	while (dInf.head != NULL) {
		cout << dInf.head->value << " ";
		dInf.head = dInf.head->prev;
	}
	cout << "\n";
	system("pause");
}
int main()
{
	dekInfo dequeInfo;
	int caseD;
	bool close = true;
	while (close) {
		cout << "choose operation \n 1)insert el. left \n 2)insert el. right \n 3)delete el. left \n 4)delete el. right \n 5)output deque \n 6)close \n";
		cin >> caseD;
		switch (caseD)
		{
		case 1: lPush(dequeInfo);
			break;
		case 2: RPush(dequeInfo);
			break;
		case 3:lPop(dequeInfo);
			break;
		case 4:RPop(dequeInfo);
			break;
		case 5: printDek(dequeInfo);
			break;
		case 6: close = false;
			break;
		}
	}
	
    return 0;
}

