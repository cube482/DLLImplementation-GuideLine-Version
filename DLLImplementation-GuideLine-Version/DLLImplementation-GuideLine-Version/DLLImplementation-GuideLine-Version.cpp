#include <iostream>
#include "LinkedList.h"

using namespace std;

int validInt();
int validId();
double validDouble();
double validBal();
string validName();
Customer* createCustomer();

int main()
{
	LinkedList* LL = nullptr;
	bool run = true;
	while (run) {
		cout << "==== Main Menu ====\n" << endl;
		cout << "1. Create Linked List\n" <<
			"2. Add Customer to Linked List\n" <<
			"3. Edit Customer Information\n" <<
			"4. Delete Customer from Linked List\n" <<
			"5. Search for Customer\n" <<
			"6. Display all Customers\n" <<
			"7. End Program\n" << endl;
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
				if (LL->addCustomer(createCustomer())) {
					cout << "Customer added successfully!\n" << endl;
				}
			}
			else {
				cout << "Linked List not created yet!\n" << endl;
			}
		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
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