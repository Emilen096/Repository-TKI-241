#include <iostream>
#include <memory>
#include "Library/RandomGenerator.h"
#include "Library/ConstantGenerator.h"
#include "Library/IStreamGenerator.h"
#include "Library/OurEx2.h"

int main() {
    using namespace miit::algebra;

    std::cout << "=== OurEx2 Demonstration (Variant 2) ===" << std::endl;

    // Testing with random numbers
    auto gen = std::make_unique<RandomGenerator>(-15, 15);
    OurEx2 exercise(std::move(gen));

    std::cout << "Filling array with 5 random elements..." << std::endl;
    exercise.fill(5);
    std::cout << "Original array: " << exercise.data() << std::endl;

    std::cout << "\nExecuting Task1 (second last = max absolute value)..." << std::endl;
    exercise.Task1();
    std::cout << "After Task1: " << exercise.data() << std::endl;

    std::cout << "\nExecuting Task2 (insert K=3 before/after elements ending with digit 3)..." << std::endl;
    exercise.Task2(3);
    std::cout << "After Task2: " << exercise.data() << std::endl;

    std::cout << "\nExecuting Task3 (creating array A using formula)..." << std::endl;
    Matrix<int> result_A = exercise.Task3();
    std::cout << "Task3 result (A): " << result_A << std::endl;

    // Additional testing with ConstantGenerator
    std::cout << "\n\n=== Testing with ConstantGenerator ===" << std::endl;
    auto const_gen = std::make_unique<ConstantGenerator>(7);
    OurEx2 const_exercise(std::move(const_gen));
    
    const_exercise.fill(4);
    std::cout << "Array with constant values: " << const_exercise.data() << std::endl;
    const_exercise.Task1();
    std::cout << "After Task1: " << const_exercise.data() << std::endl;

    std::cout << "\nProgram completed." << std::endl;
    return 0;
}