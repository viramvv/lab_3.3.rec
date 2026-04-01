#include <gtest/gtest.h>
#include "DoubleLinkedList.h"
#include <vector>

// Тест 1: Перевірка рекурсивного створення та зв'язків (prev/next)
TEST(RecursiveList, CreationTest) {
    std::vector<int> vals = {10, 20, 30};
    Node* head = createList(vals);

    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->data, 10);
    EXPECT_EQ(head->next->data, 20);
    EXPECT_EQ(head->next->prev->data, 10); // Перевірка зворотного зв'язку
    EXPECT_EQ(head->next->next->data, 30);

    clearListMemory(head);
}

// Тест 2: Рекурсивний обмін для парної кількості елементів
TEST(RecursiveList, SwapEvenCount) {
    std::vector<int> vals = {1, 2, 3, 4};
    Node* head = createList(vals);

    head = swapPairsRecursive(head);

    // Очікуємо: 2 <-> 1 <-> 4 <-> 3
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->data, 2);
    EXPECT_EQ(head->next->data, 1);
    EXPECT_EQ(head->next->next->data, 4);
    EXPECT_EQ(head->next->next->next->data, 3);

    // Перевірка цілісності prev-вказівників після рекурсії
    EXPECT_EQ(head->next->prev->data, 2);
    EXPECT_EQ(head->next->next->prev->data, 1);

    clearListMemory(head);
}

// Тест 3: Рекурсивний обмін для непарної кількості елементів
TEST(RecursiveList, SwapOddCount) {
    std::vector<int> vals = {1, 2, 3};
    Node* head = createList(vals);

    head = swapPairsRecursive(head);

    // Очікуємо: 2 <-> 1 <-> 3 (останній не міняється)
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->data, 2);
    EXPECT_EQ(head->next->data, 1);
    EXPECT_EQ(head->next->next->data, 3);

    clearListMemory(head);
}

// Тест 4: Порожній список
TEST(RecursiveList, EmptyList) {
    Node* head = nullptr;
    head = swapPairsRecursive(head);
    EXPECT_EQ(head, nullptr);
}