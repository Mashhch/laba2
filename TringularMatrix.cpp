
#include "ArraySequence.h"
#include "DynamicArray.h"
#include "Sequence.h"
#include "math.h"

//#include <stdexcept>

//#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
//#define NEGATIVE_SIZE_MESSAGE "size is negative"

template <typename T>
class Matrix {
protected:
	Sequence<T>* coefs;
	int size = 0;
	/*
public:

	Matrix(const int width) {
		if (width < 0) throw std::length_error(NEGATIVE_SIZE_MESSAGE);

		this->width = width;
		size = width * width;
		T* data = new T[size];
		for (int i = 0; i < size; ++i) this->massiv[i] = 0;

		this->coefs = new ArraySequence<T>(data, size);
	}

	Matrix(const T* data, const int width)
	{
		size = width * width;
		this->coefs = new ArraySequence<T>(data, size);
		this->size = size;
	}

	Matrix(const Matrix<T>& matrix)
	{
		this->coefs = matrix.coefs;
		this->width = sqrt(matrix.GetLength());
	}

	int GetLength() const
	{
		double width = sqrt(this->coefs->GetLength());
		return width;
	}

	T Get(int row, int column) const override {
		if (row < 0 || row >= this->width || column < 0 || column >= this->width)  throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		int index = this->width * (row - 1) + column;
		this->coefs.Get(index);
	}

	void Set(T item, int row, int column) override {
		
		if (row < 0 || row >= this->width || column < 0 || column >= this->width)  throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		int index = this->width * (row - 1) + column;
		this->coefs.array.Set(item, index);
		}

	Matrix<T>* operator+(const Matrix<T>& matrix) const {
		if (matrix->width != this->width) throw std::out_of_range("Widthes arent the same");
		Matrix<T>* newMatrix = new Matrix<T>(this.width);
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

	float GetNorm() const {
		float sum = 0;
		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->height; j++) {
				T elem = this->Get(i, j);
				sum += elem * elem;
			}
		return sqrt(sum);
	}

	template <typename U>
	Matrix<T>* operator*(U k) const {
		Matrix<T>* newMatrix = new Matrix<T>(this->width);
		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < this->width; j++) {
				newMatrix->Set(this->get(i, j) * k, i, j);
			}

		return newMatrix;
	}*/
};








