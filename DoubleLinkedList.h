#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <vector>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Прототипи функцій
Node* createList(const std::vector<int>& values);
void printList(Node* head);
void clearListMemory(Node*& head);

// ЧИСТО РЕКУРСИВНА функція обміну
Node* swapPairsRecursive(Node* head);

#endif