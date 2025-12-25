#pragma once
#include <cstddef>
#include <string>
#include <ostream>
#include <initializer_list>
#include <memory>

namespace miit {
namespace algebra {

class Generator; // Forward declaration

template<typename T>
class Matrix {
private:
    T* data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    std::unique_ptr<Generator> gen_;

    void reallocate(std::size_t new_capacity);

public:
    explicit Matrix(std::unique_ptr<Generator> gen);
    virtual ~Matrix() = default;
    void fill(std::size_t n);

    Matrix();
    explicit Matrix(std::size_t n, const T& value = T{});
    Matrix(std::initializer_list<T> init);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;

    ~Matrix();

    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    std::size_t size() const noexcept;
    bool empty() const noexcept;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void push_front(const T& value);
    void push_front(T&& value);
    void pop_front();
    void insert(std::size_t index, const T& value);
    void erase(std::size_t index);
    void clear();

    Matrix& operator<<(const T& value);
    Matrix& operator>>(T& value);

    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        return os << m.to_string();
    }
};

extern template class Matrix<int>;

} // namespace algebra
} // namespace miit
