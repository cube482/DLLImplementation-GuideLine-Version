#include "LinkedList.h"
#include <iomanip>
#include <iostream>

Customer* LinkedList::getStart() {
	return this->start;
}

bool LinkedList::isEmpty() {
	if (this->start == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool LinkedList::isDupe(int input) {
	if (!this->isEmpty()) {
		Customer* temp = this->start;
		while (temp->getNext() != nullptr) {
			if (temp->getId() == input) {
				return true;
			}
			else {
				temp = temp->getNext();
			}
		}
		if (temp->getId() == input) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		std::cout << "The linked list is empty!" << std::endl;
		return false;
	}
}

bool LinkedList::addCustomer(Customer* customer) {
	if (this->isDupe(customer->getId())) {
		std::cout << "Customer ID";
	}
	return true;
}

bool LinkedList::printRecord(Customer* customer) {
	std::cout << "*************************************************************************************************************************" << std::endl;
	std::cout << "|Customer ID: " << std::right << std::setw(8) << customer->getId() << " | " << std::left << "Customer Name:" << std::right << std::setw(23) << customer->getFirst() + " , " + customer->getLast() << " | " << std::left << "Balance: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) << customer->getBalance() << " | " << std::left << "Customer Bonus: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) << customer->getBonus() << " |" << std::endl;
	std::cout << "*************************************************************************************************************************" << std::endl;
	return true;
}

int LinkedList::validInt() {
	int ret;
	while (!(std::cin >> ret)) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input! Must be an integer!\n" << std::endl;
	}
	return ret;
}

double LinkedList::validDouble() {
	double ret;
	while (!(std::cin >> ret)) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input! Must be a double!\n" << std::endl;
	}
	return ret;
}
