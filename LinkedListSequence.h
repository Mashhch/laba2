#pragma once
#include "Sequence.h"
#include "LinkedList.h"
#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"

template <typename T>
class ListSequence : public Sequence<T> {
protected:
	LinkedList<T>list = LinkedList<T>();
public:
	ListSequence() {
		this->list = new LinkedList<T>();
		this->size = 0;
	}

	ListSequence(int size) {
		this->list = new LinkedList<T>(size);
		this->size = size;
	}

	ListSequence(const ListSequence<T>& list_) {
		this->list = new LinkedList<T>(list_.list);
		this->size = list_.size;
	}

	ListSequence(LinkedList<T>* list) {
		this->list = list;
		this->size = list->GetLenght();
	}

	ListSequence(T* items, int size) {
		this->list = new LinkedList<T>(items, size);
		this->size = size;
	}

	 T GetFirst() const override {
		return this->list.GetFirst();
	}

	 T GetLast() const override {
		return this->list.GetLast();
	}

	 T Get(int index) const override {
		return this->list.Get(index);
	}

	 int GetLength() const override
	 {
		 return  this->list.GetLength();
	 }
	 ListSequence<T>* GetSubsequence(int start, int end) const override {
		LinkedList<T>* subList = this->list.GetSublist(start, end);
		ListSequence<T>* NewList = new ListSequence<T>(subList);
		return NewList;
	}

	 void Set(int index, const T& item) override {
		this->list.Set(index, item);
	}

	 void Append(const T& item) override {
		this->list.Append(item);
		this->size++;
	}

	 void Prepend(const T& item) override {
		this->list.prepend(item);
		this->size++;
	}

	 void Insert(const T& item, int index) override {
		this->list.Insert(item, index);
		this->size++;
	}

	 ListSequence<T>* Concat(const Sequence<T> seq) const override {
		ListSequence<T>* newSequence = new ListSequence<T>();

		for (int i = 0; i < this->size; i++)
			newSequence->Append(this->Get(i));

		for (int i = 0; i < list.GetLength(); i++)
			newSequence->Append(list.Get(i));

		return newSequence;
	}

	 ~ListSequence() {
		delete this->list;
		this->size = 0;
	}

};
