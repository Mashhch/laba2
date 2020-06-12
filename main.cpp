#include "Matrix.cpp"
#include <cassert>
#include <complex>
#include <iostream>


using namespace std;

#define Test_Norm_Failed "Test Norm Failed"
#define Test_Const "Test Const Falied"

void PrintMatrix(Matrix<float>* matrix) {
	int width = matrix->GetLength();
	for (int row = 0; row < width; row++) {
		for (int column = 0; column < width; column++) {
			cout << matrix->Get(row, column) << " ";
		}
		cout << "\n";
	}
}

Matrix<float>* InputMatrix() {
	Matrix<float>* matrix;

	int width = -1;

	while (true) {
		cout << "width: ";
		cin >> width;
		if (width > 0) break;
		cout << "width must be positive\n";
	}

	matrix = new Matrix<float>(width);

	cout << "elements of matrix:\n";
	for (int row = 0; row < width; row++) {
		for (int column = 0; column < width; column++) {
			float in;
			cin >> in;
			matrix->Set(in, row, column);
		}
	}

	bool tringular = matrix->IsTringular(matrix);
	if (tringular) {
		cout << "matrix: \n";
		PrintMatrix(matrix);
	}
	else {
		delete matrix;
		matrix = nullptr;
		cout << "\nIt's not tringular\n";
	}

	return matrix;
}


void PrintSum(Matrix<float>* A, Matrix<float>* B) {
	if (A == nullptr || B == nullptr) {
		cout << "A or B isn't Set\n";
		return;
	}

	if (A->GetLength() != B->GetLength()) {
		cout << "A and B has different sizes\n";
		return;
	}


	Matrix<float>* D = *A + *B;
	PrintMatrix(D);
	delete D;
}

void Printconst(Matrix<float>* A, float c) {
	if (A == nullptr) {
		cout << "A isn't Set\n";
		return;
	}
	cout << "const c = ";
	cin >> c;
	Matrix<float>* D = *A * c;
	PrintMatrix(D);
	delete D;
}


void TestConstSum() {
	Matrix<int> mat1(3);
	mat1.Set(1, 0, 0);
	mat1.Set(2, 0, 1);
	mat1.Set(3, 0, 2);
	mat1.Set(0, 1, 0);
	mat1.Set(5, 1, 1);
	mat1.Set(6, 1, 2);
	mat1.Set(0, 2, 0);
	mat1.Set(0, 2, 1);
	mat1.Set(9, 2, 2);

	Matrix<int> mat2(3);
	mat2.Set(6, 0, 0);
	mat2.Set(5, 0, 1);
	mat2.Set(4, 0, 2);
	mat2.Set(0, 1, 0);
	mat2.Set(0, 1, 1);
	mat2.Set(1, 1, 2);
	mat2.Set(0, 2, 0);
	mat2.Set(0, 2, 1);
	mat2.Set(9, 2, 2);

	Matrix<int>* mat3 = mat1 + mat2;

	assert(mat3->Get(0, 0) == 7);
	assert(mat3->Get(0, 1) == 7);
	assert(mat3->Get(0, 2) == 7);
	assert(mat3->Get(1, 0) == 0);
	assert(mat3->Get(1, 1) == 5);
	assert(mat3->Get(1, 2) == 7);
	assert(mat3->Get(2, 0) == 0);
	assert(mat3->Get(2, 1) == 0);
	assert(mat3->Get(2, 2) == 18);


	Matrix<int>* mat4 = *mat3 * 2;

	assert(mat4->Get(0, 0) == 14);
	assert(mat4->Get(0, 1) == 14);
	assert(mat4->Get(0, 2) == 14);
	assert(mat4->Get(1, 0) == 0);
	assert(mat4->Get(1, 1) == 10);
	assert(mat4->Get(1, 2) == 14);
	assert(mat4->Get(2, 0) == 0);
	assert(mat4->Get(2, 1) == 0);
	assert(mat4->Get(2, 2) == 36);


	delete mat3;
	delete mat4;
}

void PrintNorm(Matrix<float>* A) {
	if (A == nullptr) {
		cout << "A isn't Set\n";
		return;
	}
	cout << "Norm = " << A->GetNorm() << "\n";
}

void TestNorm() {
	{
		int arr1[9] = { 1, 1, 1, 0, 1, 0, 0, 0,0 };
		Matrix<int> A(arr1, 3);
		double k = A.GetNorm();
		assert(k == 2);
	}
	{
		int arr1[9] = { 0, 0, 0, 0, 0, 0, 4, 0,3 };
		Matrix<int> A(arr1, 3);
		double k = A.GetNorm();
		assert(k == 5);
	}
	{
		double arr1[9] = { 0, 0, 0, 0, 0.4, 0, 0, 0.3 };
		Matrix<double> A(arr1, 3);
		double k = A.GetNorm();
		assert(k == 0.5);
	}
}

void printMenu() {
	cout << "1. Set A\n2. Set B\n3. Get A+B \n4. Get c*B \n5. Get c*A\n6. Get norm of A\n7. Get norm of B \n8. exit\n";
}


void interface() {
	Matrix<float>* A = nullptr;
	Matrix<float>* B = nullptr;
	float c = 0;
	while (true) {
		printMenu();

		int choose = 0;
		cin >> choose;

		switch (choose) {
		case 1:
			if (A) delete A;
			A = InputMatrix();
			break;
		case 2:
			if (B) delete B;
			B = InputMatrix();
			break;
		case 3:
			PrintSum(A, B);
			break;
		case 4:
			Printconst(A, c);
			break;
		case 5:
			Printconst(B, c);
			break;
		case 6:
			PrintNorm(A);
			break;
		case 7:
			PrintNorm(B);
			break;
		case 8:
			exit(0);
			break;
		default:
			cout << "choose number from 1 to 8\n";
		}
		cout << "\n\n";
	}

}



int main() {
	TestNorm();
	TestConstSum();
	std::cout << " all tests Ok! " << std::endl;
	interface();

	return 0;
}