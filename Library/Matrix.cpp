#include "Matrix.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

// --- Используем старый синтаксис namespace ---
namespace miit {
namespace algebra {

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
Matrix<T>::Matrix() : data_(nullptr), size_(0), capacity_(0) {}

template<typename T>
Matrix<T>::Matrix(std::size_t n, const T& value) : size_(n), capacity_(n) {
    if (n > 0) {
        data_ = new T[n];
        for (std::size_t i = 0; i < n; ++i) {
            data_[i] = value;
        }
    }
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<T> init) : size_(init.size()), capacity_(init.size()) {
    if (capacity_ > 0) {
        data_ = new T[capacity_];
        std::size_t i = 0;
        for (const T& val : init) {
            data_[i++] = val;
        }
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new T[capacity_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] data_;
    data_ = nullptr;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (std::size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        } else {
            data_ = nullptr;
        }
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

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
std::size_t Matrix<T>::size() const noexcept { // <--- Реализация публичного метода size()
    return size_;
}

template<typename T>
bool Matrix<T>::empty() const noexcept {
    return size_ == 0;
}

template<typename T>
T& Matrix<T>::front() {
    if (empty()) {
        throw std::runtime_error("Matrix::front(): called on empty matrix");
    }
    return data_[0];
}

template<typename T>
const T& Matrix<T>::front() const {
    if (empty()) {
        throw std::runtime_error("Matrix::front(): called on empty matrix");
    }
    return data_[0];
}

template<typename T>
T& Matrix<T>::back() {
    if (empty()) {
        throw std::runtime_error("Matrix::back(): called on empty matrix");
    }
    return data_[size_ - 1];
}

template<typename T>
const T& Matrix<T>::back() const {
    if (empty()) {
        throw std::runtime_error("Matrix::back(): called on empty matrix");
    }
    return data_[size_ - 1];
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
void Matrix<T>::push_front(const T& value) {
    insert(0, value);
}

template<typename T>
void Matrix<T>::push_front(T&& value) {
    insert(0, std::move(value));
}

template<typename T>
void Matrix<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("Matrix::pop_front(): called on empty matrix");
    }
    for (std::size_t i = 0; i < size_ - 1; ++i) {
        data_[i] = std::move(data_[i + 1]);
    }
    --size_;
}

template<typename T>
void Matrix<T>::insert(std::size_t index, const T& value) { // <--- Реализация публичного метода insert()
    if (index > size_) {
        throw std::out_of_range("Matrix::insert: index out of range");
    }
    if (size_ >= capacity_) {
        std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(new_capacity);
    }
    for (std::size_t i = size_; i > index; --i) {
        data_[i] = std::move(data_[i - 1]);
    }
    data_[index] = value;
    ++size_;
}

template<typename T>
void Matrix<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Matrix::erase: index out of range");
    }
    for (std::size_t i = index; i < size_ - 1; ++i) {
        data_[i] = std::move(data_[i + 1]);
    }
    --size_;
}

template<typename T>
void Matrix<T>::clear() {
    size_ = 0;
}

template<typename T>
Matrix<T>& Matrix<T>::operator<<(const T& value) {
    push_back(value);
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator>>(T& value) {
    if (empty()) {
        throw std::runtime_error("Matrix::operator>>: called on empty matrix");
    }
    value = std::move(data_[size_ - 1]);
    pop_back();
    return *this;
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

// --- Явная инстанциация шаблона для int ---
template class Matrix<int>;

} // namespace algebra
} // namespace miit