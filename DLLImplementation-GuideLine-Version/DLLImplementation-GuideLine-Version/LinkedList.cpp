#include "LinkedList.h"
#include <iomanip>
#include <iostream>
#include <vector>

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
			if (temp->getId() < customer->getId()) {
				temp->setNext(customer);
				customer->setPrev(temp);
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

void LinkedList::printRecord(Customer* customer) {
	if (customer == nullptr) { return; }
	std::cout << "****************************************************************************************************************" << std::endl;
	std::cout << "|Customer ID: " << std::right << std::setw(8) << customer->getId() << " | " << std::left << "Customer Name:" << std::right << std::setw(23) <<
	customer->getFirst() + " , " + customer->getLast() << " | " << std::left << "Balance: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) <<
	customer->getBalance() << " | " << std::left << "Bonus: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) << customer->getBonus() << " |" << std::endl;
	std::cout << "****************************************************************************************************************" << std::endl;
}

void LinkedList::printRecordMult(LinkedList::CustomerList* customerList) {
	if (customerList == nullptr) {
		return;
	}
	else {
		std::cout << "****************************************************************************************************************" << std::endl;
		for (int i = 0; i < customerList->size; i++) {
			Customer* customer = customerList->list[i];
			std::cout << "|Customer ID: " << std::right << std::setw(8) << customer->getId() << " | " << std::left << "Customer Name:" << std::right << std::setw(23) <<
				customer->getFirst() + " , " + customer->getLast() << " | " << std::left << "Balance: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) <<
				customer->getBalance() << " | " << std::left << "Bonus: " << std::right << "$" << std::fixed << std::setprecision(2) << std::setw(12) << customer->getBonus() << " |" << std::endl;
		}
		std::cout << "****************************************************************************************************************" << std::endl;
	}
}

bool LinkedList::deleteRecord(int id) {
	Customer* temp = searchById(id);
	if (temp == nullptr) {
		return false;
	}
	else {
		if (temp->getPrev() == nullptr) {
			if (temp->getNext() == nullptr) {
				this->start = nullptr;
				delete temp;
				return true;
			}
			else {
				temp->getNext()->setPrev(nullptr);
				this->start = temp->getNext();
				delete temp;
				return true;
			}
		}
		else {
			if (temp->getNext() == nullptr) {
				temp->getPrev()->setNext(nullptr);
				delete temp;
				return true;
			}
			else {
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				delete temp;
				return true;
			}
		}
	}
	return false;
}

void LinkedList::clearList() {
	Customer* temp = this->start;
	std::vector<Customer*> collection;
	while (temp != nullptr) {
		collection.push_back(temp);
		temp = temp->getNext();
	}
	for (int i = 0; i < collection.size(); i++) {
		delete collection.at(i);
	}
	this->start = nullptr;
	std::cout << "List Emptied." << std::endl;
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
		std::cout << "Customer not found!\n" << std::endl;
		return nullptr;
	}
}

LinkedList::CustomerList* LinkedList::allRecords() {
	Customer* temp = this->start;
	LinkedList::CustomerList* ret = new LinkedList::CustomerList();
	std::vector<Customer*> collection;
	while (temp != nullptr) {
		collection.push_back(temp);
		ret->size++;
		temp = temp->getNext();
	}
	ret->list = new Customer * [ret->size];
	for (int i = 0; i < ret->size; i++) {
		ret->list[i] = collection.at(i);
	}
	return ret;
}

LinkedList::CustomerList* LinkedList::searchByFirst(std::string first) {
	Customer* temp = this->start;
	LinkedList::CustomerList* ret = new LinkedList::CustomerList();
	std::vector<Customer*> collection;
	while (temp->getNext() != nullptr) {
		if (temp->getFirst() == first) {
			collection.push_back(temp);
			ret->size++;
			temp = temp->getNext();
		}
		else {
			temp = temp->getNext();
		}
	}
	if (temp->getFirst() == first) {
		collection.push_back(temp);
		ret->size++;
	}
	if (ret->size == 0) {
		std::cout << "\nCustomer not found!\n" << std::endl;
		return nullptr;
	}
	else {
		ret->list = new Customer * [ret->size];
		for (int i = 0; i < ret->size; i++) {
			ret->list[i] = collection.at(i);
		}
		return ret;
	}
}

LinkedList::CustomerList* LinkedList::searchByLast(std::string last) {
	Customer* temp = this->start;
	LinkedList::CustomerList* ret = new LinkedList::CustomerList();
	std::vector<Customer*> collection;
	while (temp->getNext() != nullptr) {
		if (temp->getLast() == last) {
			collection.push_back(temp);
			ret->size++;
			temp = temp->getNext();
		}
		else {
			temp = temp->getNext();
		}
	}
	if (temp->getLast() == last) {
		collection.push_back(temp);
		ret->size++;
	}
	if (ret->size == 0) {
		std::cout << "\nCustomer not found!\n" << std::endl;
		return nullptr;
	}
	else {
		ret->list = new Customer * [ret->size];
		for (int i = 0; i < ret->size; i++) {
			ret->list[i] = collection.at(i);
		}
		return ret;
	}
}


