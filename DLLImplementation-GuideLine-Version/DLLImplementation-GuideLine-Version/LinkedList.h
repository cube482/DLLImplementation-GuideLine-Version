#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Customer.h"
class LinkedList
{
private:
	Customer* start;
public:
	struct CustomerList {
		Customer** list;
		int size = 0;
	};
	Customer* getStart();
	bool isDupe(int);
	bool isEmpty();
	bool addCustomer(Customer*);
	void printRecord(Customer*);
	void printRecordMult(Customer**, int);
	Customer* searchById(int);
	CustomerList* searchByFirst(std::string);
	CustomerList* searchByLast(std::string);
};
#endif

