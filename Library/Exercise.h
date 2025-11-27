#pragma once
#include "Matrix.h" // Убедитесь, что путь корректен
#include "Generator.h"
#include <memory>

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

class Exercise {
protected:
    Matrix<int> data_; // Используем Matrix<int>
    std::unique_ptr<Generator> gen_;

public:
    explicit Exercise(std::unique_ptr<Generator> gen);
    virtual ~Exercise() = default;

    void fill(std::size_t n);

    // --- Исправлены сигнатуры методов ---
    virtual void Task1() = 0;
    virtual void Task2(int K) = 0;
    virtual Matrix<int> Task3() const = 0; // <--- Важно: Matrix<int>, а не Matrix

    const Matrix<int>& data() const noexcept { return data_; }
};

} // namespace algebra
} // namespace miit