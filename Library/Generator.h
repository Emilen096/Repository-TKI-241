#pragma once

namespace miit {
namespace algebra {

class Generator {
public:
    virtual ~Generator() = default; // Виртуальный деструктор
    virtual int generate() = 0;     // Чисто виртуальная функция
};

} // namespace algebra
} // namespace miit
