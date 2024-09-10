#include <iostream>
#include <vector>
#include <cmath>
#include "rational.h"
#include "matrix.h"
int main()
{	
	using namespace std;

	matrix <rational> A(
		{
			{1, 2, 1},
			{2, 1, 1},
			{1, 1, 3}
		}
	);
	matrix <rational> P(
		{
			{1, -2, -1},
			{0, 1, -1},
			{0, 0, 3}
		}
	);
	std::cout << P.transposition() * A * P << endl;
	return 0;
}
