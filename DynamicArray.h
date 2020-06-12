
#pragma once
#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"

template <class T>
class DynamicArray
{

protected:

    int size = 0;
    bool* itemsCheck;
    T* massiv = nullptr;

public:



    DynamicArray(const T* massiv, const int size)
    {
        if (size < 0)
            throw std::out_of_range(NEGATIVE_SIZE_MESSAGE);
        this->size = size;
        this->itemsCheck = new bool[size];
        for (int i = 0; i < size; i++)
            this->itemsCheck[i] = true;
        this->massiv = new T[size];
        for (int i = 0; i < size; ++i)
            this->massiv[i] = massiv[i];
    }


    DynamicArray(const int size)
    {
        if (size < 0)
            throw std::out_of_range(NEGATIVE_SIZE_MESSAGE);
        this->itemsCheck = new bool[size];
        for (int i = 0; i < size; i++)
            this->itemsCheck[i] = true;
        this->size = size;
        this->massiv = new T[size];
    }

    DynamicArray(const DynamicArray<T>& massiv)
    {
        if (size < 0)
            throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        delete[] this->massiv;
        this->size = massiv.size;
        this->itemsCheck = new bool[massiv.size];
        for (int i = 0; i < massiv.size; i++)
            this->itemsCheck[i] = true;
        this->massiv = new T[massiv.size];
        for (int i = 0; i < massiv.size; ++i)
            this->massiv[i] = massiv.massiv[i];
    }




    ~DynamicArray()
    {
        this->size = 0;
        delete[] this->massiv;
    }


    T& operator [] (const int index) const
    {

        if (index < 0 || index >= this->size) throw throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        return this->data[index];

    }

    T Get(const int index) const
    {
        if (index < 0 || index >= this->size || !this->itemsCheck[index])
            throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        this->itemsCheck[index] = true;
        return this->massiv[index];

    }

    int GetLength() const
    {
        return this->size;
    }



    void Set(const int index, const T value)
    {
        if (index < 0 || index >= this->size)  throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        this->massiv[index] = value;

    }


    void Resize(const int newSize)
    {

        if (newSize < 0) throw std::out_of_range(NEGATIVE_SIZE_MESSAGE);

        int MinSize = newSize < this->size ? newSize : this->size;;
        T* newmassiv = new T[newSize];
        this->size = newSize;
        delete[] this->itemsCheck;
        for (int i = 0; i < MinSize; i++) {
            newmassiv[i] = this->massiv[i];
            this->itemsCheck[i] = true;
        }
        delete[] this->massiv;
        this->massiv = newmassiv;
    }

};
