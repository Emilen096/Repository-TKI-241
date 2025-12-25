#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit {
namespace algebra {

class Exercise {
protected:
    Matrix<int> data_;

public:
    explicit Exercise(std::unique_ptr<Generator> gen);

    virtual ~Exercise() = default;

    void fill(std::size_t n);

    enum class InputType {
        Random = 1,
        Constant = 2,
        Manual = 3
    };

    virtual void Task1() = 0;
    virtual void Task2(int K) = 0;
    virtual Matrix<int> Task3() const = 0;

    const Matrix<int>& data() const noexcept { return data_; }
};

} // namespace algebra
} // namespace miit
