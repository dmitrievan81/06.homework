#pragma once 

template <typename T> 

class Iterator
{
protected:
    T* _item;
public:
    explicit Iterator(T* el):_item{el} {} ;
    ~Iterator() {};
    const T& operator*() const {
        return *_item;
    }
    T& operator*() {return *_item;}
};


template<typename T>
Iterator<T>::Iterator(T* el)
{
}

template<typename T>
Iterator<T>::~Iterator()
{
}
