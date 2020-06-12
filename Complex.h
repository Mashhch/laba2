#pragma once

#include <complex>


template <typename T>
class complex {
private:
	T realPart;
	T imPart;

public:
	complex(T realPart = T(), T imPart = T())
		: realPart(realPart), imPart(imPart) {}

	T real() const {
		return this->realPart;
	}

	T im() const {
		return this->imPart;
	}

	complex operator+(int val) const {
		return complex(this->realPart + val, this->imPart);
	}

	complex operator+(const complex<T>& val) const {
		return complex(this->realPart + val.realPart, this->imPart + val.imPart);
	}

	template <typename U>
	complex operator*(U val) const {
		return complex(this->realPart * val, this->imPart * val);
	}

	template <typename U>
	bool operator==(const complex<U>& val) const {
		return this->realPart == val.real() && this->imPart == val.im();
	}

	template <typename U>
	bool operator!=(const complex<U>& val) const {
		return !this->operator==(val);
	}

};
