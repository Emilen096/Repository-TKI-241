#pragma once
#include "Generator.h" // Убедитесь, что Generator.h подключен до этого

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

class ConstantGenerator : public Generator {
private:
    int value_;
public:
    explicit ConstantGenerator(int value);
    int generate() override;
};

} // namespace algebra
} // namespace miit