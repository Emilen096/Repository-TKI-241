#include "IStreamGenerator.h"

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

IStreamGenerator::IStreamGenerator(std::istream& in)
    : in{in}
{
}

int IStreamGenerator::generate()
{
    int value = 0;
    this->in >> value;
    return value;
}

} // namespace algebra
} // namespace miit