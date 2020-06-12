#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"


template <typename T> class ArraySequence : public Sequence<T> {
protected:
	DynamicArray<T>* array;
	int size = 0;

public:


	ArraySequence() : Sequence<T>() {
		this->array = new DynamicArray<T>();
		this->size = 0;
	}

	ArraySequence(int size) : Sequence<T>() {
		this->array = new DynamicArray<T>(size);
	}


	ArraySequence(T* items, int size) : Sequence<T>() {
		this->array = new DynamicArray<T>(items, size);
		this->size = size;
	}

	ArraySequence(const ArraySequence<T>& arr) {
		this->array = new DynamicArray<T>(arr.array);
		this->size = arr.size;
	}

	 T GetFirst() const override {
		return this->array->Get(0);
	}

	 T GetLast() const override {
		return this->array->Get(this->size - 1);
	}

	 T Get(int index) const override {
		return this->array->Get(index);
	}

	 int GetLength() const override
	 {
		 return this->array->GetLength();
	 }

	 ArraySequence<T>* GetSubsequence(int startindex, int endindex) const override {
		if (startindex < 0 || startindex >= this->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		if (endindex < 0 || endindex > this->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		if (startindex > endindex) throw std::logic_error("endindex must be not less than startindex");

		int size = endindex - startindex;
		T* NewArray = new T[size];
		for (int i = 0; i < size; i++)
			NewArray[i] = this->array->Get(i + startindex);
		ArraySequence<T>* NewSequence = new ArraySequence<T>(NewArray, size);
		return NewSequence;
	}

	 ArraySequence<T>* �oncat(const Sequence<T>& list) const override {
		 ArraySequence<T>* newSequence = new ArraySequence<T>(this->size + list.size);
		 for (int i = 0; i < this->size; i++)
			 newSequence->Set(i, this->array->Get(i));
		 for (int i = 0; i < this->size; i++)
			 newSequence->Set(this->size + i, list.Get(i));
		 return newSequence;
	 }

	void Append(const T item) override {
		this->array->Resize(this->size + 1);
		T t1 = this->array->Get(0);
		T t2;
		for (int i = 0; i < this->size; i++) {
			t2 = t1;
			t1 = this->array->Get(i + 1);
			this->array->Set(i + 1, t2);
		}
		this->array->Set(0, item);
		this->size++;
	}

	 void Prepend(const T item) override {
		this->array->Resize(this->size + 1);
		this->array->Set(this->size, item);
		this->size++;
	}

	 void Insert(const T item, int index) override {
		if (index < 0 || index > this->size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		this->array->Resize(this->size + 1);
		T t1 = this->array->Get(index);
		T t2;
		for (int i = index; i < this->size; i++) {
			t2 = t1;
			t1 = this->array->Get(i + 1);
			this->array->Set(i + 1, t2);
		}
		this->array->Set(index, item);
		this->size++;
	}


	 void Set(int index, const T& item) override {
		 this->array->Set(index, item);
	 }

	 ~ArraySequence() {
		delete this->array;
		this->size = 0;
	}

};

