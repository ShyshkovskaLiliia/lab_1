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
