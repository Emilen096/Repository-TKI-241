#pragma once
#include "Exercise.h"

namespace miit {
namespace algebra {

class OurEx2 : public Exercise {
public:
    using Exercise::Exercise;

    void Task2(int K) override; // Только Task2
    
    // Пустые реализации для остальных задач
    void Task1() override {}
    Matrix<int> Task3() const override { return Matrix<int>{}; }
};

} // namespace algebra
} // namespace miit
