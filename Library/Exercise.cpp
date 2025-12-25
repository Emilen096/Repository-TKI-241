#include "Exercise.h"

namespace miit {
namespace algebra {

Exercise::Exercise(std::unique_ptr<Generator> gen) : data_(std::move(gen)) {}

void Exercise::fill(std::size_t n) {
    data_.clear();
    for (std::size_t i = 0; i < n; ++i) {
        data_ << data_.gen_->generate();
    }
}

} // namespace algebra
} // namespace miit
