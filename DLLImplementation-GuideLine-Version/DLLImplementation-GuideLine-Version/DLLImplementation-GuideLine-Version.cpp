#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList* LL = new LinkedList();
    Customer* newCust = new Customer(1, "Jae", "An", 1000000, 500000);
    LL->printRecord(newCust);
}

