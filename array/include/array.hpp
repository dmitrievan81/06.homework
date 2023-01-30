#pragma once 
#include <cstddef>

template <typename T>
class Array
{
public:
    
    Array() = delete;
    explicit Array(std::size_t sz);
    ~Array();
    void push_back(T el);
    bool insert(T el, std::size_t idx);
    void erase();
    void reserve(std::size_t N);
    std::size_t size() const;
    std::size_t capacity() const;
    const T* data() const;
    T& operator[](std::size_t idx);
    T operator[](std::size_t idx) const;

private:
    T *m_data;
    std::size_t m_size;
    std::size_t m_capacity;
};

template<typename T>
Array<T>::~Array() {
    delete [] T;
}

template <typename T>
Array<T>::Array(std::size_t sz) {
    
    m_size = sz;
    m_capacity = 2 * m_size;
    T* = new T[m_capacity];
}

template <typename T>
void Array<T>::reserve(std::size_t sz) {
    
    if (sz < m_capacity) {
        return true;
    } else {
        
        m_capacity *= 2;
        T* m_data_tmp = new T[m_capacity];
        for (std::size_t idx = 0; idx < m_size; idx++)
        {
            m_data_tmp[idx] = m_data[idx];
        }
        delete [] m_data;
        m_data = m_data_tmp;
        
    }
}

template <typename T>
void Array<T>::push_back(T el) {
    
    reserve<T>(m_size + 1);
    m_size++;
    m_data[m_size] = el;

}

template <typename T>
bool Array<T>::insert(T el, std::size_t idx) {
    
    if (idx < 0 || idx >= m_size) {
        return false;
    }
    
    reserve<T>(m_size + 1);
    
    std::size_t idx_ = idx;
    for (;idx_ < m_size; idx_++) {
        m_data[idx_+1] = m_data[idx_]
    }
    
    m_data[idx] = el;
    m_size++;

}