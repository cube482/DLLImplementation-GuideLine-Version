#include <iostream>
#include "LinkedList.h"

// function prototypes
void createLinkedList(LinkedList*&);
void addCustomer(LinkedList*);
void editCustomer(LinkedList*);
void deleteCustomer(LinkedList*);
void searchCustomer(LinkedList*);
void displayCustomer(LinkedList*);
void clearLinkedList(LinkedList*);
void endProgram(bool*);
void populateTestData(LinkedList*);
int validInt();
int validId();
double validDouble();
double validBalance();
std::string validName();
// end function prototypes


// main
int main() {
	LinkedList* LL = nullptr;
	bool run = true;
	while (run) {
		std::cout << "\n== Main Menu ===\n" << std::endl;
		std::cout << "1. Create linked list\n" <<
			"2. Add Customer\n" <<
			"3. Edit Customer Info\n" <<
			"4. Delete Customer\n" <<
			"5. Search for Customer\n" <<
			"6. List all customers\n" <<
			"7. Clear linked list\n" <<
			"8. Close Program\n" <<
			"9. Populate with test data\n" << std::endl;
		int choice = validInt();
		switch (choice) {
		case 1:
			createLinkedList(LL);
			break;
		case 2:
			addCustomer(LL);
			break;
		case 3:
			editCustomer(LL);
			break;
		case 4:
			deleteCustomer(LL);
			break;
		case 5:
			searchCustomer(LL);
			break;
		case 6:
			displayCustomer(LL);
			break;
		case 7:
			clearLinkedList(LL);
			break;
		case 8:
			endProgram(&run);
			break;
		case 9:
			populateTestData(LL);
			break;
		default:
			std::cout << "\nInvalid Choice!\n" << std::endl;
		}
	}
}
// end main

// Helper Functions(input validation)
int validInt() {
	int ret;
	while (!(std::cin >> ret) || ret < 0) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\nInvalid input! Must be a positive integer!\n" << std::endl;
	}
	return ret;
}

int validId() {
InvalidId:
	int ret = validInt();
	if (ret > 99999999) {
		std::cout << "\nInvalid ID! Must be 8 Digits or less!\n" << std::endl;
		goto InvalidId;
	}
	return ret;
}

double validDouble() {
	double ret;
	while (!(std::cin >> ret)) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\nInvalid input! Must be a double!\n" << std::endl;
	}
	return ret;
}

double validBalance() {
InvalidBal:
	double bal = validDouble();
	if (bal > 9999999) {
		std::cout << "\nInvalid balance! Must be less than $10,000,000!\n" << std::endl;
		goto InvalidBal;
	}
	return bal;
}

std::string validName() {
InvalidName:
	std::string name;
	std::cin >> name;
	if (name.length() > 10) {
		std::cout << "\nInvalid name! Must be 10 characters or less!\n" << std::endl;
		goto InvalidName;
	}
	return name;
}
// end Helper Functions

// Main Functions
void createLinkedList(LinkedList*& LL) {
	LL = new LinkedList();
	std::cout << "\nLinked list created!\n" << std::endl;
}

void addCustomer(LinkedList* LL) {
	if (LL == nullptr) {
		std::cout << "\nLinked list not created yet!\n" << std::endl;
		return;
	}
	std::cout << "\n== New Customer Creation ==\n" << std::endl;
	std::cout << "Enter Customer ID:\n" << std::endl;
	int id = validId();
	std::cout << "Enter Customer's first name:\n" << std::endl;
	std::string first = validName();
	std::cout << "Enter Customer's last name:\n" << std::endl;
	std::string last = validName();
	std::cout << "Enter Customer's balance:\n" << std::endl;
	double bal = validBalance();
	std::cout << "Enter Customer's bonus:\n" << std::endl;
	double bonus = validBalance();
	Customer* ret = new Customer(id, first, last, bal, bonus);
	if (LL->addCustomer(ret)) {
		std::cout << "\nCustomer added successfully!\n" << std::endl;
	}
	else {
		std::cout << "\nCustomer add failed!\n" << std::endl;
	}
}

void editCustomer(LinkedList* LL) {
	if (LL == nullptr || LL->getStart() == nullptr) {
		std::cout << "\nLinked list empty or not created yet!\n" << std::endl;
		return;
	}
	std::cout << "=== Customer Edit ===\n" << std::endl;
	std::cout << "Enter ID of the customer whose data you wish to edit:\n" << std::endl;
	Customer* customer = LL->searchById(validId());
	std::cout << "1. Edit firt name\n" <<
				 "2. Edit last name\n" <<
				 "3. Edit balance\n" <<
				 "4. Edit bonus\n" << std::endl;
	int choice = validInt();
	std::string ins;
	double ind;
	switch (choice) {
		case 1:
			std::cout << "\nEnter new first name:\n" << std::endl;
			ins = validName();
			customer->setFirst(ins);
			std::cout << "\nEdit success!\n" << std::endl;
			break;
		case 2:
			std::cout << "\nEnter new last name:\n" << std::endl;
			ins = validName();
			customer->setLast(ins);
			std::cout << "\nEdit success!\n" << std::endl;
			break;
		case 3:
			std::cout << "\nEnter new balance:" << std::endl;
			ind = validBalance();
			customer->setBalance(ind);
			std::cout << "\nEdit success!\n" << std::endl;
			break;
		case 4:
			std::cout << "\nEnter new bonus:\n" << std::endl;
			ind = validBalance();
			customer->setBalance(ind);
			std::cout << "\nEdit success!\n" << std::endl;
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;
	}
}

void deleteCustomer(LinkedList* LL) {
	if (LL == nullptr || LL->getStart() == nullptr) {
		std::cout << "\nLinked list empty or not created yet!\n" << std::endl;
		return;
	}
	std::cout << "\nEnter the ID of the customer whose record you wish to delete:\n" << std::endl;
	if (LL->deleteRecord(validId())) {
		std::cout << "\nRecord deleted successfully!\n" << std::endl;
	}
	else {
		std::cout << "\nRecord delete failed!\n" << std::endl;
	}
}

void searchCustomer(LinkedList* LL) {
	if (LL == nullptr || LL->getStart() == nullptr) {
		std::cout << "\nLinked list empty or not created yet!\n" << std::endl;
		return;
	}
	std::cout << "\n=== Customer Search ===\n" << std::endl;
	std::cout << "1. Search by ID\n" << 
				 "2. Search by first name\n" <<
				 "3. Search by last name\n" << std::endl;
	int choice = validInt();
	std::string in;
	switch (choice) {
	case 1:
		std::cout << "Enter ID to search for:\n" << std::endl;
		LL->printRecord(LL->searchById(validId()));
		break;
	case 2:
		std::cout << "Enter first name to search for:\n" << std::endl;
		in = validName();
		LL->printRecordMult(LL->searchByFirst(in));
		break;
	case 3:
		std::cout << "Enter last name to search for:\n" << std::endl;
		in = validName();
		LL->printRecordMult(LL->searchByLast(in));
		break;
	default:
		std::cout << "Invalid choice!\n" << std::endl;
	}
}

void displayCustomer(LinkedList* LL) {
	if (LL == nullptr || LL->getStart() == nullptr) {
		std::cout << "\nLinked list empty or not created yet!\n" << std::endl;
		return;
	}
	LL->printRecordMult(LL->allRecords());
}

void clearLinkedList(LinkedList* LL) {
	if (LL == nullptr || LL->getStart() == nullptr) {
		std::cout << "\nLinked list empty or not created yet!\n" << std::endl;
		return;
	}
	LL->clearList();
}

void endProgram(bool* run) {
	*run = false;
}

void populateTestData(LinkedList* LL) {
	if (LL == nullptr) {
		std::cout << "\nLinked list not created yet!\n" << std::endl;
		return;
	}
	for (int i = 0; i < 20; i++) {
		LL->addCustomer(new Customer(i+1, "Test" + std::to_string(i+1), "TestLast" + std::to_string(i+1), i * 1000, i * 100));
	}
	std::cout << "\nLinked list populated with test data\n" << std::endl;
}


// end main functions