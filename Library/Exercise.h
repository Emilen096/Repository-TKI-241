#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit {
namespace algebra {

class Exercise {
protected:
    Matrix<int> data_;
    std::unique_ptr<Generator> gen_;

public:
    explicit Exercise(std::unique_ptr<Generator> gen);
    virtual ~Exercise() = default;

    void fill(std::size_t n);
    
    // ОДИН виртуальный метод Task()
    virtual void Task() = 0;

    const Matrix<int>& data() const noexcept { return data_; }
};

} // namespace algebra
} // namespace miit
