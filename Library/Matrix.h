#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <memory> // Для std::unique_ptr
#include <iostream> // Для operator<<, если используется здесь
#include <sstream>  // Для to_string

// Подключаем Generator, так как Matrix теперь зависит от него
#include "Generator.h"

namespace miit {
namespace algebra {

template<typename T>
class Matrix {
private:
    T* data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    std::unique_ptr<Generator> gen_; // Храним генератор

    void reallocate(std::size_t new_capacity);

public:
    // --- Перемещённые строки из Exercise.h ---
    explicit Matrix(std::unique_ptr<Generator> gen);
    virtual ~Matrix() = default; // Виртуальный деструктор
    void fill(std::size_t n); // Метод fill
    // --- Конец перемещённых строк ---

    // --- Остальные конструкторы ---
    Matrix();
    explicit Matrix(std::size_t n, const T& value = T{});
    // ... (остальные конструкторы, если были)

    // --- Остальные методы ---
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    // ... (остальные методы)

    // --- Вывод в строку ---
    std::string to_string() const;

    // --- Дружественный оператор вывода ---
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        return os << m.to_string();
    }
};

// --- Реализация методов шаблона ---
template<typename T>
void Matrix<T>::reallocate(std::size_t new_capacity) {
    T* new_data = new T[new_capacity];
    std::size_t copy_size = std::min(size_, new_capacity);
    for (std::size_t i = 0; i < copy_size; ++i) {
        new_data[i] = std::move_if_noexcept(data_[i]);
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
    if (size_ > new_capacity) size_ = new_capacity;
}

template<typename T>
Matrix<T>::Matrix() : data_(nullptr), size_(0), capacity_(0), gen_(nullptr) {}

template<typename T>
Matrix<T>::Matrix(std::size_t n, const T& value) : size_(n), capacity_(n), gen_(nullptr) {
    if (n > 0) {
        data_ = new T[n];
        for (std::size_t i = 0; i < n; ++i) {
            data_[i] = value;
        }
    }
}

// --- Реализация перемещённых методов ---
template<typename T>
Matrix<T>::Matrix(std::unique_ptr<Generator> gen) : data_(nullptr), size_(0), capacity_(0), gen_(std::move(gen)) {}

template<typename T>
void Matrix<T>::fill(std::size_t n) {
    this->clear(); // Очищаем текущие данные
    for (std::size_t i = 0; i < n; ++i) {
        this->push_back(static_cast<T>(gen_->generate())); // Предполагаем, что generate() возвращает int
    }
}

// --- Остальные реализации методов ---
template<typename T>
T& Matrix<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Matrix::operator[]: index out of range");
    }
    return data_[index];
}

template<typename T>
const T& Matrix<T>::operator[](std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Matrix::operator[]: index out of range");
    }
    return data_[index];
}

template<typename T>
std::size_t Matrix<T>::size() const noexcept {
    return size_;
}

template<typename T>
bool Matrix<T>::empty() const noexcept {
    return size_ == 0;
}

template<typename T>
void Matrix<T>::push_back(const T& value) {
    if (size_ >= capacity_) {
        std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(new_capacity);
    }
    data_[size_++] = value;
}

template<typename T>
void Matrix<T>::push_back(T&& value) {
    if (size_ >= capacity_) {
        std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(new_capacity);
    }
    data_[size_++] = std::move(value);
}

template<typename T>
void Matrix<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Matrix::pop_back(): called on empty matrix");
    }
    --size_;
}

template<typename T>
void Matrix<T>::clear() {
    size_ = 0;
}

template<typename T>
std::string Matrix<T>::to_string() const {
    std::ostringstream oss;
    oss << "[ ";
    for (std::size_t i = 0; i < size_; ++i) {
        if (i > 0) oss << ", ";
        oss << data_[i];
    }
    oss << " ]";
    return oss.str();
}

// --- Явная инстанциация для int ---
template class Matrix<int>;

} // namespace algebra
} // namespace miit
