#pragma once
#include "Generator.h"
#include <iostream> // Необходимо для std::istream

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

/**
* @brief
*/
class IStreamGenerator : public Generator
{
private:
    std::istream& in; // Ссылка
public:
    /**
    * @brief
    * @param in - ссылка на поток ввода
    */
    IStreamGenerator(std::istream& in = std::cin); // Конструктор принимает ссылку и инициализирует член 'in'
    /**
    * @brief
    */
    int generate() override;
};

} // namespace algebra
} // namespace miit