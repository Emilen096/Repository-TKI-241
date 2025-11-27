#include "ConstantGenerator.h"

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

ConstantGenerator::ConstantGenerator(int value) : value_(value) {}

int ConstantGenerator::generate() {
    return value_;
}

} // namespace algebra
} // namespace miit