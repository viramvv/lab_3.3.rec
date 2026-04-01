cmake_minimum_required(VERSION 3.20)
project(DoubleListRecursive)

set(CMAKE_CXX_STANDARD 17)

# Створюємо бібліотеку з логіки списку, щоб використовувати її і в main, і в тестах
add_library(ListLib DoubleLinkedList.cpp DoubleLinkedList.h)

# Основний додаток
add_executable(MainApp main.cpp)
target_link_libraries(MainApp ListLib)

# --- Налаштування Google Test ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Примусово використовуємо спільну бібліотеку для тестів
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Створюємо файл з тестами
add_executable(UnitTest UnitTest.cpp)
# gtest_main автоматично додає функцію main() для запуску тестів
target_link_libraries(UnitTest ListLib gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTest)