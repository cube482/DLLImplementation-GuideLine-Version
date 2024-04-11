#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
class Customer
{
private:
	int id;
	std::string first;
	std::string last;
	double balance;
	double bonus;
	Customer* prev;
	Customer* next;
public:
	Customer(int, std::string, std::string, double, double);
	Customer();
	int getId();
	std::string getFirst();
	std::string getLast();
	double getBalance();
	double getBonus();
	Customer* getPrev();
	Customer* getNext();
	void setFirst(std::string);
	void setLast(std::string);
	void setBalance(double);
	void setBonus(double);
	void addBalance(double);
	void subBalance(double);
	void addBonus(double);
	void subBonus(double);
	void setPrev(Customer*);
	void setNext(Customer*);
};
#endif
