#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <exception>


template <typename T>
class Vector
{
public:
    Vector();
    ~Vector();

    void insert(int value, int index);
    void remove(int index);

    T& operator[](int index);
    size_t size() const;

private:
    void testIndex(int index, bool canBeSize=false) const;
    void reallocation();

private:
    T* data;
    size_t data_size;
    size_t reserved;
};

template <typename T>
Vector<T>::Vector(): 
    data(new T[2]), 
    data_size(0), 
    reserved(2) 
{
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
void Vector<T>::insert(int value, int index)
{
    testIndex(index, true);

    reallocation();
    
    // move all elements forward
    for (size_t i = size(); i > index; --i)
        data[i] = data[i - 1];

    // insert new element
    data[index] = value;
    ++data_size;
}

template <typename T>
void Vector<T>::remove(int index)
{
    testIndex(index);

    // move all elements backward
    for (size_t i = index; i < size() - 1; ++i)
        data[i] = data[i + 1];

    // decrease size
    --data_size;
}

template <typename T>
T& Vector<T>::operator[](int index)
{
    testIndex(index);
    
    return data[index];
}

template <typename T>
size_t Vector<T>::size() const
{
    return data_size;
}

template <typename T>
void Vector<T>::testIndex(int index, bool canBeSize) const
{
    auto error_string = std::string("Index is out of range") + " " + std::to_string(index);
    if (index < 0 || index > size())
        throw std::out_of_range(error_string);

    if (index == size() && !canBeSize)
        throw std::out_of_range(error_string);
}

template <typename T>
void Vector<T>::reallocation()
{
    if (size() == reserved)
    {
        // reallocate memory
        reserved *= 2;
        ++data_size;

        T* new_data = new T[reserved];
        for (size_t i = 0; i < size(); ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }
}

#endif // VECTOR_H
