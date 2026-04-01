#include "DoubleLinkedList.h"
#include <iostream>

// Рекурсивне створення списку (для повної відповідності стилю)
Node* createListRecursive(const std::vector<int>& values, size_t index) {
    if (index >= values.size()) return nullptr;

    Node* newNode = new Node{values[index], nullptr, nullptr};
    Node* nextNode = createListRecursive(values, index + 1);
    
    if (nextNode) {
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
    return newNode;
}

Node* createList(const std::vector<int>& values) {
    return createListRecursive(values, 0);
}

void printList(Node* head) {
    if (!head) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << "[" << head->data << "] <-> ";
    printList(head->next); // Рекурсивний вивід
}

// ГОЛОВНА РЕКУРСИВНА ФУНКЦІЯ ОБМІНУ
Node* swapPairsRecursive(Node* head) {
    // Базовий випадок: якщо залишилося 0 або 1 елемент — обмін не потрібен
    if (!head || !head->next) {
        return head;
    }

    // Крок 1: Визначаємо вузли поточної пари
    Node* first = head;
    Node* second = head->next;

    // Крок 2: РЕКУРСІЯ — йдемо до наступної пари
    // Функція поверне нам вказівник на "нову голову" наступної пари
    Node* remaining = swapPairsRecursive(second->next);

    // Крок 3: Перестановка вказівників у ПОТОЧНІЙ парі
    
    // Зв'язуємо перший з результатом рекурсії
    first->next = remaining;
    if (remaining) {
        remaining->prev = first;
    }

    // Робимо другий вузол першим у парі
    second->next = first;
    second->prev = nullptr; // Тимчасово, буде встановлено на попередньому рівні рекурсії
    first->prev = second;

    // Крок 4: Повертаємо другий вузол як новий початок цього сегмента
    return second;
}

void clearListMemory(Node*& head) {
    if (!head) return;
    clearListMemory(head->next); // Рекурсивне видалення
    delete head;
    head = nullptr;
}