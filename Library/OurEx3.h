#pragma once
#include "Exercise.h"

namespace miit {
namespace algebra {

class OurEx3 : public Exercise {
public:
    using Exercise::Exercise;

    Matrix<int> Task3() const override; // Только Task3
    
    // Пустые реализации для остальных задач
    void Task1() override {}
    void Task2(int K) override {}
};

} // namespace algebra
} // namespace miit