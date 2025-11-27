#include "OurEx2.h"
#include <cmath>
#include <iostream> // Добавлено

namespace miit {
namespace algebra {

void OurEx2::Task2(int K) {
    int target_digit = std::abs(K) % 10;
    int insertions = 0;

    // Проходим массив с конца чтобы не сломать индексы при вставке
    for (std::size_t i = data_.size(); i-- > 0; ) {
        int current_value = data_[i];
        int last_digit = std::abs(current_value) % 10;

        if (last_digit == target_digit) {
            data_.insert(i + 1, K); // Вставляем ПОСЛЕ
            data_.insert(i, K);     // Вставляем ДО
            insertions += 2;
        }
    }

    std::cout << "Inserted " << insertions << " elements with value " << K << std::endl;
}

} // namespace algebra
} // namespace miit
