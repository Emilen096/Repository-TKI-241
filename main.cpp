#include <iostream>
#include <memory>
#include "Matrix.h"
#include "Generator.h" // Если нужно создавать конкретные генераторы

// Пример использования Matrix с генератором
class RandomGenerator : public miit::algebra::Generator {
public:
    int generate() override {
        return rand() % 100; // Просто для примера
    }
};

int main() {
    using namespace miit::algebra;

    auto gen = std::make_unique<RandomGenerator>();
    Matrix<int> matrix(std::move(gen)); // Создаём Matrix с генератором

    std::cout << "Матрица до fill: " << matrix << std::endl;

    matrix.fill(5); // Заполняем 5 элементами

    std::cout << "Матрица после fill: " << matrix << std::endl;

    return 0;
}
