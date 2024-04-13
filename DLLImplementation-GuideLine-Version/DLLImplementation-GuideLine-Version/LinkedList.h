#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Customer.h"
class LinkedList
{
private:
	Customer* start;
public:
	struct CustomerList {
		Customer** list = nullptr;
		int size = 0;
	};
	Customer* getStart();
	bool isDupe(int);
	bool isEmpty();
	bool addCustomer(Customer*);
	void printRecord(Customer*);
	void printRecordMult(CustomerList*);
	bool deleteRecord(int);
	void clearList();
	Customer* searchById(int);
	CustomerList* allRecords();
	CustomerList* searchByFirst(std::string);
	CustomerList* searchByLast(std::string);
};
#endif

