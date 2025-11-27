#include "OurEx3.h"
#include <cmath>
#include <iostream> // Добавлено

namespace miit {
namespace algebra {

Matrix<int> OurEx3::Task3() const {
    Matrix<int> A;

    std::cout << "Creating new array by formula:" << std::endl;
    std::cout << "- Even indices: A[i] = (i+1) * D[i]^2" << std::endl;
    std::cout << "- Odd indices: A[i] = D[i] / i" << std::endl;

    for (std::size_t i = 0; i < data_.size(); ++i) {
        int result;

        if (i % 2 == 0) {
            // Четный индекс (0, 2, 4...): Aᵢ = (i+1) × Dᵢ²
            result = static_cast<int>(i + 1) * data_[i] * data_[i];
            std::cout << "A[" << i << "] = (" << i + 1 << ") * " << data_[i] << "^2 = " << result << std::endl;
        } else {
            // Нечетный индекс (1, 3, 5...): Aᵢ = Dᵢ / i
            if (i == 0) {
                result = data_[i]; // Избегаем деления на 0
            } else {
                result = data_[i] / static_cast<int>(i);
            }
            std::cout << "A[" << i << "] = " << data_[i] << " / " << i << " = " << result << std::endl;
        }
        
        A << result;
    }

    return A;
}

} // namespace algebra
} // namespace miit