#include "Matrix.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

// Реализация методов шаблона находится в заголовочном файле Matrix.h
// Однако, явная инстанциация шаблона должна быть в .cpp файле
namespace miit {
namespace algebra {

// Явная инстанциация для int
template class Matrix<int>;

} // namespace algebra
} // namespace miit
