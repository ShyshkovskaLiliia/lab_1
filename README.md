# Лабораторна робота №1: Варіант 16

##Завдання №1
Задано одновимірний масив А розміру 2N.
Побудувати масив В розміру 2N, розмістивши у першій половині масиву В другу половину
масиву А, а у другій половині масиву В, першу - А

##Код
```cpp
#include <iostream>

int main() {
    int N;
    std::cout << "Введіть N: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "N має бути додатнім!" << std::endl;
        return 1;
    }

    int* A = new int[2 * N];
    std::cout << "Введіть " << 2 * N << " елементів масиву A:" << std::endl;
    
    for (int i = 0; i < 2 * N; i++) {
        std::cin >> A[i];
    }
    
    int* B = new int[2 * N];

    // Циклічний зсув праворуч на N позицій
    for (int i = 0; i < 2 * N; i++) {
        B[i] = A[(i + N) % (2 * N)];
    }

    std::cout << "\nМасив A:" << std::endl;
    for (int i = 0; i < 2 * N; i++) {
        std::cout << A[i] << " ";
    }

    std::cout << "\nМасив B:" << std::endl;
    for (int i = 0; i < 2 * N; i++) {
        std::cout << B[i] << " ";
    }

    std::cout << std::endl;

    delete[] A;
    delete[] B;

    return 0;
}
```
##Завдання №2
Заданий одномірний масив цілих чисел А розміру N.
Знайти номер першого мінімального значення серед додатних елементів, 
розташованих правіше першого елемента, рівного нулю

##Код
```cpp
#include <iostream>
#include <limits>

int main() {
    int N;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> N;

    int* A = new int[N];
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int zeroIndex = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0) {
            zeroIndex = i;
            break;
        }
    }

    if (zeroIndex == -1) {
        std::cout << "У масиві немає елементів, рівних нулю." << std::endl;
        delete[] A;
        return 0;
    }

    int minPositive = std::numeric_limits<int>::max();
    int minPositiveIndex = -1;

    for (int i = zeroIndex + 1; i < N; ++i) {
        if (A[i] > 0 && A[i] < minPositive) {
            minPositive = A[i];
            minPositiveIndex = i;
        }
    }

    if (minPositiveIndex == -1) {
        std::cout << "Правіше першого нуля немає додатних елементів." << std::endl;
    } else {
        std::cout << "Номер першого мінімального додатного елемента правіше першого нуля: " << minPositiveIndex << std::endl;
    }

    delete[] A;
    return 0;
}
```
##Завдання №3
Задано масив чисел 
A(n), n <=500. Розробити програму, яка обчислює суму всіх чисел, які знаходяться між першим і 
останнім від’ємними елементами цього масиву і вказує цей діапазон. Якщо від’ємних чисел 
немає або є тільки одно, то виводить повідомлення про це.
