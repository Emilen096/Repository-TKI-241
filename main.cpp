#include <iostream>
#include <memory>
#include "Library/RandomGenerator.h"
#include "Library/ConstantGenerator.h"
#include "Library/IStreamGenerator.h"
#include "Library/OurEx1.h"
#include "Library/OurEx2.h"
#include "Library/OurEx3.h"

int main() {
    using namespace miit::algebra;

    std::cout << "=== Matrix Operations Demonstration ===" << std::endl;

    // Ввод размера матрицы
    std::size_t size;
    std::cout << "Enter matrix size: ";
    std::cin >> size;

    // Выбор способа заполнения
    int choice;
    std::cout << "\nChoose filling method:\n";
    std::cout << "1 - Random numbers [-15, 15]\n";
    std::cout << "2 - Constant value\n";
    std::cout << "3 - Manual input\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    std::unique_ptr<Generator> generator;

    switch (choice) {
        case 1:
            generator = std::make_unique<RandomGenerator>(-15, 15);
            std::cout << "Using random generator [-15, 15]" << std::endl;
            break;
        case 2:
            int constant_value;
            std::cout << "Enter constant value: ";
            std::cin >> constant_value;
            generator = std::make_unique<ConstantGenerator>(constant_value);
            std::cout << "Using constant generator: " << constant_value << std::endl;
            break;
        case 3:
            generator = std::make_unique<IStreamGenerator>(std::cin);
            std::cout << "Using manual input. Enter " << size << " elements: ";
            break;
        default:
            std::cout << "Invalid choice, using random generator." << std::endl;
            generator = std::make_unique<RandomGenerator>(-15, 15);
            break;
    }

    // OurEx1 - Task1
    std::cout << "\n--- OurEx1: Task1 ---" << std::endl;
    OurEx1 ex1(std::make_unique<RandomGenerator>(-15, 15));
    ex1.fill(size);
    std::cout << "Before Task: " << ex1.data() << std::endl;
    ex1.Task();
    std::cout << "After Task: " << ex1.data() << std::endl;

    // OurEx2 - Task2
    std::cout << "\n--- OurEx2: Task2 ---" << std::endl;
    OurEx2 ex2(std::make_unique<RandomGenerator>(-15, 15));
    ex2.fill(size);
    std::cout << "Before Task: " << ex2.data() << std::endl;
    ex2.Task();
    std::cout << "After Task: " << ex2.data() << std::endl;

    // OurEx3 - Task3
    std::cout << "\n--- OurEx3: Task3 ---" << std::endl;
    OurEx3 ex3(std::make_unique<RandomGenerator>(-15, 15));
    ex3.fill(size);
    std::cout << "Before Task: " << ex3.data() << std::endl;
    ex3.Task();

    std::cout << "\nAll tasks completed!" << std::endl;
    return 0;
}
