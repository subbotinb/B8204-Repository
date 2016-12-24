#include "stdafx.h"
#include "Header.h"
#include <iostream>
#include "stdlib.h"
using namespace std;

void lPush(dekInfo &dInf, int insVal){
	dek *tmp = (dek*)malloc(sizeof(dek));
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
	tmp->value = insVal;
}
void RPush(dekInfo &dInf, int insVal) {
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
	tmp->value = insVal;

}
int lPop(dekInfo &dInf) {
	if (dInf.head != NULL){
		dInf.size--;
		int tmp = dInf.head->value;
		dInf.head = dInf.head->prev;
		if (dInf.head != NULL){
			free(dInf.head->nxt);
			dInf.head->nxt = NULL;
		}
		return tmp;
	}
	else return(-1);
}
int RPop(dekInfo &dInf) {
	if (dInf.tail != NULL){
		dInf.size--;
		int tmp = dInf.head->value;
		dInf.tail = dInf.tail->nxt;
		if (dInf.tail != NULL){
			free(dInf.tail->prev);
			dInf.tail->prev = NULL;
		}
		return tmp;
	}
	else return(-1);
}
void printDekSize(dekInfo dInf) {
	cout << "\n" << dInf.size;
	cout << "\n";
}
