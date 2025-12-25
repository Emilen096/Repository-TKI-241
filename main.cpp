#include <iostream>
#include <memory>
#include "Matrix.h"
#include "Exercise.h"
#include "RandomGenerator.h"
#include "ConstantGenerator.h"
#include "IStreamGenerator.h"

int main() {
    using namespace miit::algebra;

    std::cout << "=== Выбор генератора ===" << std::endl;
    std::cout << "1 - Случайный" << std::endl;
    std::cout << "2 - Константный" << std::endl;
    std::cout << "3 - Ввод с клавиатуры" << std::endl;

    int choice = 0;
    std::cin >> choice;

    std::unique_ptr<Generator> gen = nullptr;

    switch (static_cast<Exercise::InputType>(choice)) {
        case Exercise::InputType::Random:
            gen = std::make_unique<RandomGenerator>(-10, 10);
            break;
        case Exercise::InputType::Constant:
            gen = std::make_unique<ConstantGenerator>(5);
            break;
        case Exercise::InputType::Manual:
            gen = std::make_unique<IStreamGenerator>(std::cin);
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
            return 1;
    }

    // Предположим, у вас есть класс, наследующий от Exercise, например, OurEx2
    // Exercise exercise(std::move(gen)); // <-- Это не сработает, так как Exercise абстрактный
    // Нужно создать конкретный класс, например, OurEx2
    // OurEx2 exercise(std::move(gen));

    // Пример с Matrix
    Matrix<int> matrix(std::move(gen));

    std::cout << "Заполняем массив из 5 элементов..." << std::endl;
    matrix.fill(5);
    std::cout << "Массив: " << matrix << std::endl;

    return 0;
}
