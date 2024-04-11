#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Customer.h"
class LinkedList
{
private:
	Customer* start;
public:
	Customer* getStart();
	bool isDupe(int);
	bool isEmpty();
	bool addCustomer(Customer*);
	bool printRecord(Customer*);
	int validInt();
	double validDouble();
};
#endif

