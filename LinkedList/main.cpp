#include "LinkedList.h"

int main() {
    LinkedList list;

    // Adding elements to the list
    list.append(1);
    list.append(2);
    list.append(3);

    // Displaying the list
    std::cout << "Linked List: ";
    list.display();

    return 0;
}
