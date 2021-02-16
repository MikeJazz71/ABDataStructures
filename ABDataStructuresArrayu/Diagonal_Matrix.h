#pragma once
#include <iostream>
using namespace std;

class Matrix
{


private:


	int n;
	int* A;




public:

	Matrix() 
	{
	}
	Matrix(int n)

	{
		this->n = n;
		A = new int[n];

	}


	~Matrix() 
	{
		delete[]A;


	}

	int Get(int i, int j);
	void Set(int i, int j, int x);
	void Display();
	void Create(); 
	

};



int Matrix::Get(int i, int j)
{
	if (i == j)
	{
		return A[i - 1];
	}
	else
	{
		return 0;
	}
}


void Matrix::Set(int i, int j, int x)
{
	if (i == j)
	{
		A[i - 1] = x;
	}


}

void Matrix::Display() {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				cout << A[i] << "\t";
			}
			else
			{
				cout << "0\t";
			}
		} cout << endl;
	}

}

