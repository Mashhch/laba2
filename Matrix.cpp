#include "ArraySequence.h"
#include "DynamicArray.h"
#include "Sequence.h"
#include "math.h"
#include <iostream>
using namespace std;

#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"

template <typename T>
class Matrix {
protected:
	Sequence<T>* coefs = nullptr;
	int width = 0;
public:

	Matrix(const int width) {
		if (width < 0) throw std::length_error(NEGATIVE_SIZE_MESSAGE);

		this->width = width;
		int size = width * width;
		T* data = new T[size];
		for (int i = 0; i < size; ++i) data[i] = 0;

		this->coefs = new ArraySequence<T>(data, size);
	}

	Matrix( T* data, const int width)
	{
		this->width = width;
		int size = width * width;
		this->coefs = new ArraySequence<T>(data, size);

	}

	Matrix(const Matrix<T>& matrix)
	{
		this->coefs = matrix.coefs;
		this->width = sqrt(matrix.GetLength());
	}

	int GetLength() const
	{
		return this->width;
	}

	T Get(int row, int column) const {
		if (row < 0 || row >= this->width || column < 0 || column > this->width)  throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		int index = this->width * row + column;
		return this->coefs->Get(index);
	}

	void Set(T item, int row, int column) {

		if (row < 0 || row >= this->width || column < 0 || column > this->width)  throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
			
		int index = this->width * row + column;
		this->coefs->Set(index, item);
	}

	bool IsTringular(const Matrix<float>* matrix) {
		bool islow = true;
		bool ishigh = true;
		bool istringular = false;
		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++) {
				if ((j > i) & (matrix->Get(i, j) != 0))
					ishigh = false;
				if ((j < i) & (matrix->Get(i, j) != 0))
					islow = false;
			}
		if ((islow == true) || (ishigh == true))
			istringular = true;
		return istringular;
	}
	Matrix<T>* operator+(const Matrix<T>& matrix) const {
		if (matrix.width != this->width) throw std::out_of_range("Widthes arent the same");
		Matrix<T>* newMatrix = new Matrix<T>(this->width);
		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++) {
				newMatrix->Set(this->Get(i, j) + matrix.Get(i, j), i, j);
			}
		return newMatrix;
	}


	bool operator==(const Matrix<T>& matrix) const {
		if (this->width != matrix.width) return false;

		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++)
				if (this->Get(i, j) != matrix.Get(i, j)) return false;


		return true;
	}



	bool operator==(const Matrix<T>* matrix) const {
		if (this->width != matrix->width) return false;

		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++)
				if (this->Get(i, j) != matrix->Get(i, j)) return false;


		return true;
	}

	double GetNorm() const {
		float sum = 0;
		float norm = 0;
		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++) {
				T elem = this->Get(i, j);
				sum += static_cast<float>(elem) * static_cast<float>(elem);
			}
		norm = sqrt(sum);
		return norm;
	}

	template <typename U>
	Matrix<T>* operator*(U k) const {
		Matrix<T>* newMatrix = new Matrix<T>(this->width);
		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++) {
				newMatrix->Set(this->Get(i, j) * k, i, j);
			}

		return newMatrix;
	}
};