#pragma once
#include "Exercise.h"

namespace miit {
namespace algebra {

class OurEx1 : public Exercise {
public:
    using Exercise::Exercise;

    void Task1() override; // Только Task1
    
    // Пустые реализации для остальных задач
    void Task2(int K) override {}
    Matrix<int> Task3() const override { return Matrix<int>{}; }
};

} // namespace algebra
} // namespace miit