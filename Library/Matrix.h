#pragma once
#include <cstddef>
#include <string>
#include <ostream>
#include <initializer_list>

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

template<typename T>
class Matrix {
private:
    T* data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;

    void reallocate(std::size_t new_capacity);

public:
    // --- Конструкторы ---
    Matrix();
    explicit Matrix(std::size_t n, const T& value = T{});
    Matrix(std::initializer_list<T> init);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;

    // --- Деструктор ---
    ~Matrix();

    // --- Операторы присваивания ---
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    // --- Оператор индексации ---
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    // --- Методы доступа ---
    std::size_t size() const noexcept; // <--- Публичный метод size()
    bool empty() const noexcept;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    // --- Методы изменения ---
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void push_front(const T& value);
    void push_front(T&& value);
    void pop_front();
    void insert(std::size_t index, const T& value); // <--- Публичный метод insert()
    void erase(std::size_t index);
    void clear();

    // --- Операторы сдвига ---
    Matrix& operator<<(const T& value);
    Matrix& operator>>(T& value);

    // --- Вывод в строку ---
    std::string to_string() const;

    // --- Дружественный оператор вывода ---
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        return os << m.to_string();
    }
};

extern template class Matrix<int>; // <--- Важно для шаблонов

} // namespace algebra
} // namespace miit