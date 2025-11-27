#pragma once

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

/**
* @brief
*/
class Generator
{
public:
    /**
    * @brief
    */
    virtual ~Generator() = default; // Убрано "= 0 {};". Деструктор может быть виртуальным, но не абстрактным.
    /**
    * @brief
    */
    virtual int generate() = 0; // Чисто виртуальная функция
};

} // namespace algebra
} // namespace miit