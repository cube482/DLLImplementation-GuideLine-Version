#include "Customer.h"

Customer::Customer(int id, std::string first, std::string last, double balance, double bonus) {
	this->id = id;
	this->first = first;
	this->last = last;
	this->balance = balance;
	this->bonus = bonus;
	this->prev = nullptr;
	this->next = nullptr;
}

Customer::Customer() {
	this->id = NULL;
	this->first = "\0";
	this->last = "\0";
	this->balance = NULL;
	this->bonus = NULL;
	this->prev = nullptr;
	this->next = nullptr;
}

int Customer::getId() {
	return this->id;
}

std::string Customer::getFirst() {
	return this->first;
}

std::string Customer::getLast() {
	return this->last;
}

double Customer::getBalance() {
	return this->balance;
}

double Customer::getBonus() {
	return this->bonus;
}

Customer* Customer::getPrev() {
	return this->prev;
}

Customer* Customer::getNext() {
	return this->next;
}

void Customer::setFirst(std::string first) {
	this->first = first;
}

void Customer::setLast(std::string last) {
	this->last = last;
}

void Customer::setBalance(double balance) {
	this->balance = balance;
}

void Customer::setBonus(double bonus) {
	this->bonus = bonus;
}

void Customer::addBalance(double balance) {
	this->balance += balance;
}

void Customer::subBalance(double balance) {
	this->balance -= balance;
}

void Customer::addBonus(double bonus) {
	this->bonus += bonus;
}

void Customer::subBonus(double bonus) {
	this->bonus -= bonus;
}

void Customer::setPrev(Customer* prev) {
	this->prev = prev;
}

void Customer::setNext(Customer* next) {
	this->next = next;
}

