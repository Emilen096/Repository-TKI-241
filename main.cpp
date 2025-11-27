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
    std::cout << "\n--- Task 1: Replace second last with max absolute ---" << std::endl;
    OurEx1 ex1(std::make_unique<RandomGenerator>(-15, 15)); // Копируем генератор
    ex1.fill(size);
    std::cout << "Before Task1: " << ex1.data() << std::endl;
    ex1.Task1();
    std::cout << "After Task1: " << ex1.data() << std::endl;

    // OurEx2 - Task2
    std::cout << "\n--- Task 2: Insert K before/after elements ending with K ---" << std::endl;
    OurEx2 ex2(std::make_unique<RandomGenerator>(-15, 15)); // Копируем генератор
    ex2.fill(size);
    
    int K;
    std::cout << "Enter K value: ";
    std::cin >> K;
    
    std::cout << "Before Task2: " << ex2.data() << std::endl;
    ex2.Task2(K);
    std::cout << "After Task2: " << ex2.data() << std::endl;

    // OurEx3 - Task3
    std::cout << "\n--- Task 3: Create new array by formula ---" << std::endl;
    OurEx3 ex3(std::make_unique<RandomGenerator>(-15, 15)); // Копируем генератор
    ex3.fill(size);
    
    std::cout << "Original array: " << ex3.data() << std::endl;
    Matrix<int> result = ex3.Task3();
    std::cout << "Result array A: " << result << std::endl;

    std::cout << "\nAll tasks completed!" << std::endl;
    return 0;
}
