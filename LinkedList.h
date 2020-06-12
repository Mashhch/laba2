#pragma once
#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"

template <class T>
class LinkedList
{

private:

    struct Record
    {
        T data;
        Record* next = nullptr;
    };

    int size = 0;
    Record* head = nullptr;

public:

    //Creation constructors
    LinkedList() : size(0), head(nullptr) {};

    LinkedList(const T* data, const int size) : LinkedList()
    {

        if (size < 0) throw std::out_of_range(NEGATIVE_SIZE_MESSAGE);

        this->size = size;
        Record** newptr = &(this->head);
        for (int i = 0; i < size; ++i)
        {
            (*newptr) = new Record;
            (*newptr)->data = data[i];
            newptr = &((*newptr)->next);
        }

    }

    //Copy constructor
    LinkedList(const LinkedList<T>& list) {
        Record* ptr = list.head;
        Record** newptr = &(this->head);

        for (int i = 0; i < list.size; i++, ptr = ptr->next) {
            *newptr = new Record;
            (*newptr)->data = ptr->data;
            newptr = &((*newptr)->next);

        }

        this->size = list.size;
    }

    //Destructor
    ~LinkedList() {
        Record* ptr = this->head;
        Record* next;
        while (ptr != nullptr) {
            next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }

    //Methods of class
    T GetFirst() const
    {

        if (this->size == 0) throw std::length_error(ZERO_SIZE_MESSAGE);
        return this->head->data;

    }

    T GetLast() const
    {

        if (this->size == 0) throw std::length_error(ZERO_SIZE_MESSAGE);
        Record* ptr = this->head;
        while (ptr->next != nullptr) ptr = ptr->next;

        return ptr->data;

    }

    T Get(const int index) const
    {
        if (index < 0 || index >= this->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        Record* ptr = this->head;
        for (int i = 0; i < index; i++) ptr = ptr->next;

        return ptr->data;
    }

  /*   T& operator [] (const int index) const
    {

         if (this->head == nullptr || index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRangeException);

        Record* ptr = this->head;

        for (int i = 0; i < index; ++i) ptr = ptr->next;

        return ptr->data;

     }*/

    LinkedList<T>* GetSublist(const int start_index, const int end_index) const
    {
        if (start_index < 0 || start_index >= this->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (end_index < 0 || end_index > this->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (start_index > end_index) throw std::logic_error("end must be not less than start");

        int newsize = end_index - start_index;
        Record* ptr = this->head;
        T* newdata = new T[newsize];

        for (int i = 0; i < end_index; ++i)
        {
            if (i >= start_index) newdata[i - start_index] = ptr->data;
            ptr = ptr->next;
        }

        LinkedList<T>* newptr = new LinkedList<T>(newdata, newsize);
        delete[] newdata;

        return  newptr;

    }

    int GetLength() const
    {
        return  this->array->size;
    }

    void Append(const T data)
    {
        Record* newptr;
        newptr->data = data;
        newptr->next = this->head;
        this->head = newptr;
        this->array->size++;

        

    };

    void Prepend(const T data)
    {
        Record* newptr = this->head;
        while (newptr != nullptr) newptr = newptr->next;
        newptr = new Record;
        newptr->data = data;
        this->array->size++;
        
    }

    void Insert(const T data, const int index)
    {
        if (index < 0 || index > this->array->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        if (index == 0)
        {
            this->append(data);
        }
        else
        {
            Record* newptr,ptr;
            newptr->data = data;
            ptr = this->head;
            for (int i = 0; i  < index-1; i++) ptr = ptr->next;
            newptr->next = ptr->next;
            ptr->next = newptr;
            this->array->size++;
        }
    }

    LinkedList<T>* Concat(const LinkedList<T>* list)
    {
        const int newsize = this->array->size + list->size;
        T* newdata = new T[newsize];
        Record* ptr = this->head;

        for (int i = 0; i < this->array->size; i++) {
            newdata[i] = ptr->data;
            ptr = ptr->next;
        }

        ptr = list->head;
        for (int i = this->array->size; i < newsize; ++i) {
            newdata[i] = ptr->data;
            ptr = ptr->next;
        }

        LinkedList<T>* concatptr = new LinkedList<T>(newdata, newsize);
        delete[] newdata;
        return  concatptr;
    }

};

