#pragma once

template <class T>
class Sequence
{
public:
    int size = 0;
public:

    Sequence() = default;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(const int index) const = 0;
    virtual int GetLength() const = 0;

    virtual Sequence<T>* GetSubsequence(const int start_index, const int end_index) const = 0;
    virtual Sequence<T>* Ñoncat(const Sequence<T>& seq) const = 0;
    virtual void Append(const T value) = 0;
    virtual void Prepend(const T value) = 0;
    virtual void Set(int index, const T& item) = 0;
    virtual void Insert(const T value, const int index) {};

     ~Sequence() = default;

};