#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Введіть кількість елементів масиву (n <= 500): ";
    std::cin >> n;

    if (n <= 0 || n > 500) {
        std::cout << "Невірний розмір масиву. Введіть число від 1 до 500." << std::endl;
        return 1;
    }

    std::vector<int> A(n);
    std::cout << "Введіть елементи масиву: ";

    int first_negative = -1, last_negative = -1;
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
        if (A[i] < 0) {
            if (first_negative == -1)
                first_negative = i;
            last_negative = i;
        }
    }

    if (first_negative == -1 || first_negative == last_negative) {
        std::cout << "Від'ємних чисел немає або є тільки одне." << std::endl;
    } else {
        int sum = 0;
        for (int i = first_negative + 1; i < last_negative; ++i) {
            sum += A[i];
        }
        std::cout << "Сума елементів між першим і останнім від'ємними елементами: " << sum << std::endl;
        std::cout << "Діапазон: від " << first_negative + 2 << " до " << last_negative << std::endl;
    }

    return 0;
}
