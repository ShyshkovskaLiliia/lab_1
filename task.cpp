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
