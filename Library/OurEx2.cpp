#include "OurEx2.h"
#include <cmath>
#include <stdexcept>

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

void OurEx2::Task1() {
    if (data_.size() < 2) {
        return;
    }
    int max_abs_value = data_[0];
    std::size_t max_abs_index = 0;

    for (std::size_t i = 1; i < data_.size(); ++i) {
        if (std::abs(data_[i]) > std::abs(max_abs_value)) {
            max_abs_value = data_[i];
            max_abs_index = i;
        }
    }

    data_[data_.size() - 2] = max_abs_value;
}

void OurEx2::Task2(int K) {
    int target_digit = std::abs(K) % 10;

    for (std::size_t i = data_.size(); i-- > 0; ) {
        int current_value = data_[i];
        int last_digit = std::abs(current_value) % 10;

        if (last_digit == target_digit) {
            data_.insert(i + 1, K);
            data_.insert(i, K);
        }
    }
}

Matrix<int> OurEx2::Task3() const { // <--- Важно: Matrix<int>, а не Matrix
    Matrix<int> A;

    for (std::size_t i = 0; i < data_.size(); ++i) {
        std::size_t one_based_index = i + 1;

        int result_value = 0;
        if (one_based_index % 2 == 0) {
            result_value = static_cast<int>(one_based_index) * data_[i] * data_[i];
        } else {
            if (one_based_index == 1) { // Особый случай: i=1 (индекс 0) -> деление на 0
                result_value = data_[i];
            } else {
                result_value = data_[i] / static_cast<int>(one_based_index - 1);
            }
        }
        A << result_value;
    }

    return A;
}

} // namespace algebra
} // namespace miit