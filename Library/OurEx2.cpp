#include "OurEx1.h"
#include <cmath>
#include <iostream>

namespace miit {
namespace algebra {

void OurEx1::Task() {
    if (data_.size() < 2) {
        std::cout << "Array too small for Task1 (need at least 2 elements)" << std::endl;
        return;
    }
    
    int max_abs_value = data_[0];
    std::size_t max_abs_index = 0;

    // Находим максимальный по модулю элемент
    for (std::size_t i = 1; i < data_.size(); ++i) {
        if (std::abs(data_[i]) > std::abs(max_abs_value)) {
            max_abs_value = data_[i];
            max_abs_index = i;
        }
    }

    // Заменяем предпоследний элемент
    data_[data_.size() - 2] = max_abs_value;
    std::cout << "Replaced second last element with max absolute value: " << max_abs_value << std::endl;
}

} // namespace algebra
} // namespace miit
