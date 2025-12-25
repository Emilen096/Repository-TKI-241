#pragma once
#include "Matrix.h" // Подключаем Matrix, так как теперь fill и конструктор находятся в Matrix
#include <memory>

namespace miit {
namespace algebra {

// Exercise теперь НЕ содержит перемещённых строк
class Exercise {
protected:
    Matrix<int> data_; // Используем Matrix<int> (предполагаем, что Matrix теперь может хранить int и имеет генератор)
    // std::unique_ptr<Generator> gen_; // <-- УБРАНО, теперь в Matrix

public:
    // Exercise больше не принимает gen в конструкторе, так как gen теперь в Matrix
    // explicit Exercise(std::unique_ptr<Generator> gen); // <-- УБРАНО
    // virtual ~Exercise() = default; // <-- УБРАНО
    // void fill(std::size_t n); // <-- УБРАНО

    // Если Exercise всё ещё нужен, можно добавить конструктор, который инициализирует Matrix с генератором
    explicit Exercise(std::unique_ptr<Generator> gen);

    // Виртуальные методы задач
    virtual void Task1() = 0;
    virtual void Task2(int K) = 0;
    virtual Matrix<int> Task3() const = 0;

    const Matrix<int>& data() const noexcept { return data_; }
};

// Реализация конструктора Exercise
template<typename T>
Exercise::Exercise(std::unique_ptr<Generator> gen) : data_(std::move(gen)) {} // Используем новый конструктор Matrix

} // namespace algebra
} // namespace miit
