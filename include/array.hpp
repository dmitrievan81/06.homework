#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    Array() = delete;
    ~Array();
    explicit Array(std::size_t sz);
    bool in_range(std::size_t idx) const;
    void push_back(T el);
    bool insert(T el, std::size_t idx);
    bool erase(std::size_t idx_begin, std::size_t idx_end);
    bool erase(std::size_t idx);
    void reserve(std::size_t N);
    std::size_t size() const;
    std::size_t capacity() const;
    const T *data() const;
    T &operator[](std::size_t idx);
    T operator[](std::size_t idx) const;
    T &begin();
    T &end();
    // error code

private:
    T *m_data;
    std::size_t m_size;
    std::size_t m_capacity;
};

template <typename T>
Array<T>::~Array()
{
    try
        {
           delete [] m_data;
        }
        catch (...)
        {
            std::cout << "delete [] m_data" << std::endl;
        }

}

template <typename T>
Array<T>::Array(std::size_t sz)
{

    m_size = sz;
    m_capacity = 2 * m_size;
    m_data = new T[m_capacity];
}

template <typename T>
void Array<T>::reserve(std::size_t sz)
{

    if (sz > m_capacity)
    {

        m_capacity = 1000;
        T *m_data_tmp = new T[m_capacity];
        // T *m_data_tmp = new T[1000];

        for (std::size_t idx = 0; idx < m_size; idx++)
        {
            std::cout << "m_data_tmp[" << idx << "] = m_data[" << idx << "];" << std::endl;
            m_data_tmp[idx] = m_data[idx];
        }

        try
        {
            delete[] m_data;
            m_data = m_data_tmp;
        }
        catch (...)
        {
            std::cout << "delete [] m_data" << std::endl;
        }

        
    }
}

template <typename T>
std::size_t Array<T>::size() const { return m_size; }

template <typename T>
std::size_t Array<T>::capacity() const { return m_capacity; }

template <typename T>
bool Array<T>::in_range(std::size_t idx) const
{
    return idx >= 0 || idx < m_size;
}

template <typename T>
void Array<T>::push_back(T el)
{

    reserve(m_size + 1);
    m_size++;
    m_data[m_size] = el;
}

template <typename T>
bool Array<T>::insert(T el, std::size_t idx)
{

    if (!in_range(idx))
    {
        return false;
    }

    reserve(m_size + 1);

    std::size_t idx_ = idx;
    for (; idx_ < m_size; idx_++)
    {
        m_data[idx_ + 1] = m_data[idx_];
    }

    m_data[idx] = el;
    m_size++;

    return true;
}

template <typename T>
bool Array<T>::erase(std::size_t idx_begin, std::size_t idx_end)
{

    if (!in_range(idx_begin))
    {
        return false;
    }

    if (!in_range(idx_end))
    {
        return false;
    }

    std::size_t idx_first = idx_begin;
    std::size_t idx_last = idx_end + 1;

    for (; idx_last < m_size - 1; idx_last++)
    {
        m_data[idx_first] = m_data[idx_last];
    }

    m_size = m_size - (idx_end - idx_begin + 1);

    return true;
}

template <typename T>
bool Array<T>::erase(std::size_t idx)
{
    return erase(idx, idx);
}