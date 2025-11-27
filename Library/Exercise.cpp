#include "Exercise.h"

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

Exercise::Exercise(std::unique_ptr<Generator> gen) : gen_(std::move(gen)) {}

void Exercise::fill(std::size_t n) {
    data_.clear();
    for (std::size_t i = 0; i < n; ++i) {
        data_ << gen_->generate(); // Используем operator<< для Matrix
    }
}

} // namespace algebra
} // namespace miit