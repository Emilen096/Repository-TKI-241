#pragma once
#include "Exercise.h"

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

class OurEx2 : public Exercise { // Наследует от Exercise
public:
    using Exercise::Exercise; // Наследуем конструктор Exercise

    // --- Исправлены сигнатуры методов для совпадения с Exercise.h ---
    void Task1() override; // Должен совпадать
    void Task2(int K) override; // Должен совпадать
    Matrix<int> Task3() const override; // <--- Важно: Matrix<int>, а не Matrix
};

} // namespace algebra
} // namespace miit