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
		std::cout << "Customer ID: " << customer->getId() << "already exists!\n" << std::endl;
		return false;
	}
	else {
		if (this->isEmpty()) {
			this->start = customer;
			return true;
		}
		else {
			Customer* temp = this->start;
			while (temp->getNext() != nullptr) {
				if (temp->getId() < customer->getId()) {
					temp = temp->getNext();
				}
				else {
					if (temp->getPrev() == nullptr) {
						this->start = customer;
						customer->setNext(temp);
						temp->setPrev(customer);
						return true;
					}
					else {
						temp->getPrev()->setNext(customer);
						customer->setPrev(temp->getPrev());
						customer->setNext(temp);
						temp->setPrev(customer);
						return true;
					}
				}
			}
		}
	}
	return true;
}

void LinkedList::printRecord(Customer* customer) {
	std::cout << "****************************************************************************************************************" << std::endl;
	std::cout << "|Customer ID: " << std::right << std::setw(8) << customer->getId() << " | " << std::left << "Customer Name:" << std::right << std::setw(23) <<
	customer->getFirst() + " , " + customer->getLast() << " | " << std::left << "Balance: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) <<
	customer->getBalance() << " | " << std::left << "Bonus: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) << customer->getBonus() << " |" << std::endl;
	std::cout << "****************************************************************************************************************" << std::endl;
}

void LinkedList::printRecordMult(Customer** customerList, int size) {
	std::cout << "****************************************************************************************************************" << std::endl;
	for (int i = 0; i < size; i++) {
		Customer* customer = customerList[i];
		std::cout << "|Customer ID: " << std::right << std::setw(8) << customer->getId() << " | " << std::left << "Customer Name:" << std::right << std::setw(23) <<
		customer->getFirst() + " , " + customer->getLast() << " | " << std::left << "Balance: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) <<
		customer->getBalance() << " | " << std::left << "Bonus: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) << customer->getBonus() << " |" << std::endl;
	}
	std::cout << "****************************************************************************************************************" << std::endl;
}

Customer* LinkedList::searchById(int id) {
	Customer* temp = this->start;
	while (temp->getNext() != nullptr) {
		if (temp->getId() == id) {
			return temp;
		}
		else {
			temp = temp->getNext();
		}
	}
	if (temp->getId() == id) {
		return temp;
	}
	else {
		return nullptr;
	}
}

/*LinkedList::CustomerList* LinkedList::searchByFirst(std::string first) {
	Customer* temp = this->start;
	LinkedList::CustomerList* ret;
	while (temp->getNext() != nullptr) {
		if (temp->getFirst() == first) {
			return temp;
		}
		else {
			temp = temp->getNext();
		}
	}
	if (temp->getFirst() == first) {
		return temp;
	}
	else {
		return nullptr;
	}
}

LinkedList::CustomerList* LinkedList::searchByLast(std::string last) {
	Customer* temp = this->start;
	while (temp->getNext != nullptr) {
		if (temp->getLast() == last) {
			return temp;
		}
		else {
			temp = temp->getNext();
		}
	}
	if (temp->getLast() == last) {
		return temp;
	}
	else {
		return nullptr;
	}
} */


