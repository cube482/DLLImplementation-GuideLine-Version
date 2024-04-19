#include <iostream>
#include "LinkedList.h"

using namespace std;

void editCustomer(Customer*);
void search(int);
int validInt();
int validId();
double validDouble();
double validBal();
string validName();
Customer* createCustomer();

LinkedList* LL = nullptr;

int main()
{
	bool run = true;
	while (run) {
		cout << "==== Main Menu ====\n" << endl;
		cout << "1. Create Linked List\n" <<
			"2. Add Customer to Linked List\n" <<
			"3. Edit Customer Information\n" <<
			"4. Delete Customer from Linked List\n" <<
			"5. Search for Customer\n" <<
			"6. Display all Customers\n" <<
			"7. Clear Linked List\n" <<
			"8. End Program\n" << endl;
		int mainMenu_choice = validInt();
		switch (mainMenu_choice) {
		case 1:
		{
			if (LL == nullptr) {
				LL = new LinkedList();
			}
			else {
				cout << "Linked List already exists!\n" << endl;
			}
		}
		break;
		case 2:
		{
			if (LL != nullptr) {
				bool success = LL->addCustomer(createCustomer());
				if (success) {
					cout << "Customer added successfully!\n" << endl;
				}
				else {
					cout << "Customer add failed!\n" << endl;
				}
			}
			else {
				cout << "Linked List not created yet!\n" << endl;
			}
		}
		break;
		case 3:
		{
			if (LL != nullptr && LL->getStart() != nullptr) {
				cout << "=== Customer Edit ===\n" << endl;
				cout << "Enter ID of the customer whose data you wish to edit:\n" << endl;
				Customer* temp = LL->searchById(validId());
				editCustomer(temp);
			}
			else {
				cout << "Linked List not created or is empty!\n" << endl;
			}
		}
		break;
		case 4:
		{
			cout << "Enter the ID of the customer whose record you wish to delete:\n" << endl;
			if (LL->deleteRecord(validId())) {
				cout << "\nRecord deleted successfully!\n" << endl;
			}
			else {
				cout << "\nRecord delete failed!\n" << endl;
			}
		}
		break;
		case 5:
		{
			cout << "=== Customer Search ===" << endl;
			cout << "1. Search by ID\n" << endl;
			cout << "2. Search by first name\n" << endl;
			cout << "3. Search by last name\n" << endl;
			int choice = validInt();
			search(choice);
		}
		break;
		case 6:
		{
			if (LL != nullptr && LL->getStart() != nullptr) {
				LL->printRecordMult(LL->allRecords());
			}
			else {
				cout << "Linked list is not created yet, or is empty!" << endl;
			}
		}
		break;
		case 7:
		{
			LL->clearList();
		}
		break;
		case 8:
		{
			run = false;
		}
		break;
		}
	}
}

Customer* createCustomer() {
	cout << "== New Customer Creation ==\n" << endl;
	cout << "Enter Customer ID:\n" << endl;
	int id = validId();
	cout << "Enter Customer's first name:\n" << endl;
	string first = validName();
	cout << "Enter Customer's last name:\n" << endl;
	string last = validName();
	cout << "Enter Customer's balance:\n" << endl;
	double bal = validBal();
	cout << "Enter Customer's bonus:\n" << endl;
	double bonus = validBal();
	Customer* ret = new Customer(id, first, last, bal, bonus);
	return ret;
}

int validInt() {
	int ret;
	while (!(cin >> ret)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Must be an integer!\n" << std::endl;
	}
	return ret;
}

double validDouble() {
	double ret;
	while (!(cin >> ret)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Must be a double!\n" << std::endl;
	}
	return ret;
}

int validId() {
InvalidId:
	int ret = validInt();
	if (ret > 99999999) {
		cout << "Invalid ID! Must be 8 Digits or less!\n" << endl;
		goto InvalidId;
	}
	return ret;
}

string validName() {
InvalidName:
	string name;
	cin >> name;
	if (name.length() > 10) {
		cout << "Invalid name! Must be 10 characters or less!\n" << endl;
		goto InvalidName;
	}
	return name;
}

double validBal() {
InvalidBal:
	double bal = validDouble();
	if (bal > 9999999) {
		cout << "Invalid balance! Must be less than $10,000,000!\n" << endl;
		goto InvalidBal;
	}
	return bal;
}

void editCustomer(Customer* customer) {
	if (customer != nullptr) {
		cout << "1. Edit firt name\n" <<
			"2. Edit last name\n" <<
			"3. Edit balance\n" <<
			"4. Edit bonus\n" << endl;
		int choice = validInt();
		string ins;
		double ind;
		switch (choice) {
		case 1:
			cin >> ins;
			customer->setFirst(ins);
			cout << "\nEdit success!\n" << endl;
			break;
		case 2:
			cin >> ins;
			customer->setLast(ins);
			cout << "\nEdit success!\n" << endl;
			break;
		case 3:
			ind = validBal();
			customer->setBalance(ind);
			cout << "\nEdit success!\n" << endl;
			break;
		case 4:
			ind = validBal();
			customer->setBalance(ind);
			cout << "\nEdit success!\n" << endl;
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	else {
		cout << "Returning to main menu...\n" << endl;
	}
}

void search(int choice) {
	string in;
	switch (choice) {
	case 1:
		cout << "Enter ID to search for:\n" << endl;
		LL->printRecord(LL->searchById(validId()));
		break;
	case 2:
		cout << "Enter first name to search for:\n" << endl;
		cin >> in;
		LL->printRecordMult(LL->searchByFirst(in));
		break;
	case 3:
		cout << "Enter last name to search for:\n" << endl;
		cin >> in;
		LL->printRecordMult(LL->searchByLast(in));
		break;
	default:
		cout << "Invalid choice!\n" << endl;
	}
}