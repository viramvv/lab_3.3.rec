#include <iostream>
#include "DoubleLinkedList.h"

int main() {
    // Формуємо список: 1, 2, 3, 4, 5, 6
    std::vector<int> data = {1, 2, 3, 4, 5, 6};
    Node* myList = createList(data);

    std::cout << "Pochatkovyi spysok (Recursive print):" << std::endl;
    printList(myList);

    // Виклик чистої рекурсії
    myList = swapPairsRecursive(myList);

    std::cout << "\nSpysok pislia rekursyvnoho obminu par:" << std::endl;
    printList(myList);

    clearListMemory(myList);
    return 0;
}