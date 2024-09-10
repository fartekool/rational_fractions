
#include <iostream>
#include <ciso646>
#include <string>
#include <cmath>
#include "matrix.h"

template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T>& A)
{
	for (int i = 0; i < A.m; ++i)
	{
		for (int j = 0; j < A.n; ++j)
		{
			os << A.numbers[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}
template <class T>
matrix<T>::matrix(): m(2), n(2)
{
	for (int i = 0; i < m; ++i)
		numbers.push_back({ 0, 0 });
}
template <class T>
matrix<T>::matrix(int m_, int n_) : m(m_), n(n_)
{	

	std::vector<T> str;
	for (int j = 0; j < n; ++j)
	{
		str.push_back(0);
	}
	for (int i = 0; i < m; ++i)
	{
		numbers.push_back(str);
	}
}
template <class T>
matrix<T>::matrix(std::vector<std::vector<T>> numbers_) : numbers(numbers_), m(numbers_.size()), n(numbers_[0].size()) {}
template <class T>
matrix<T>::matrix(const matrix<T>& A): m(A.m), n(A.n), numbers(A.numbers) {}

template <class T>
void matrix<T>::init_matrix(std::vector<std::vector<T>> numbers_)
{	
	m = numbers_.size();
	n = numbers_[0].size();
	numbers = numbers_;
}
template <class T>
T matrix<T>::det()
{	
	if (m != n or m < 1)
		throw 0;
	determinant = 0;
	if (m > 1)
	{
		for (int i = 0; i < n; ++i)
		{	
			matrix A(this->algebraic_complement(1, i + 1));
			determinant += pow(-1, i) * numbers[0][i] * A.det();

		}
	}
	if (m == 1)
		determinant = numbers[0][0];
	return determinant;
}
template <class T>
matrix<T> matrix<T>::algebraic_complement(int m_, int n_)
{
	matrix A(*this);
	A.numbers.erase(A.numbers.begin() + m_ - 1);
	A.m--;
	for (int i = 0; i < A.m; ++i)
	{
		A.numbers[i].erase(A.numbers[i].begin() + n_ - 1);
	}
	A.n--;
	return A;
}
template <class T>
matrix<T> matrix<T>::operator+(const matrix& A)
{	
	if (m != A.m or n != A.n)
		throw 0;
	matrix answer(m, n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			answer.numbers[i][j] = numbers[i][j] + A.numbers[i][j];
		}
	}
	return answer;
}
template <class T>
matrix<T> matrix<T>::operator-(const matrix& A)
{	
	if (m != A.m or n != A.n)
		throw 0;
	matrix answer(m, n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			answer.numbers[i][j] = numbers[i][j] - A.numbers[i][j];
		}
	}
	return answer;
}
template <class T>
matrix<T> matrix<T>::operator*(const matrix& A)
{	
	if (n != A.m)
		throw 0;
	matrix answer(m, A.n);
	for (int i = 0; i < answer.m; ++i)
	{
		for (int j = 0; j < answer.n; ++j)
		{
			T elem = 0;
			for (int k = 0; k < n; ++k)
			{
				
				elem += numbers[i][k] * A.numbers[k][j];
				
			}
			answer.numbers[i][j] = elem;
		}
	}
	return answer;
}
template <class T>
matrix<T>& matrix<T>::operator=(const matrix& A)
{
	m = A.m;
	n = A.n;
	numbers = A.numbers;
	return *this;
}
