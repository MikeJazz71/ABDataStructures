#pragma once
#include <iostream>
using namespace std;

class Array
{
private:
	int* A;
	int size;
	int length;
	void Swap(int* x, int* y);


public:
	Array()
	{
		size = 10;
		length = 0;
		A = new int[size];
	}

	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int[size];
	}

	~Array()
	{
		delete[]A;
	}

	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int Delete(int index);
	int LinearSearch(int x);
	int BinarySearch(int key);
	int Get(int index);
	void Set(int index, int x);
	int Min();
	int Max();
	int Sum();
	float Average();
	void Reverse();
	void InsertSort(int x);
	bool IsSorted();
	void Rearrange();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Diff(Array arr2);
	Array* Inter(Array arr2);
};


inline void Array::Swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Array::Display()
{
	cout << "\n The Elements of the Array are\n";
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
}

inline void Array::Append(int x)
{
	if (length == size)
	{
		cout << "Array is full\n";
	}
	else
	{
		A[length] = x;
		length++;
	}
}

void Array::Insert(int index, int x)
{
	int i;
	if (index >= 0 && index < length)
	{
		for (i = length; i > index; i--)
		{
			A[i] = A[i - 1];
			A[index] = x;
			length++;
		}
	}
}

int Array::Delete(int index)
{
	if (length == 0)
	{
		cout << "Array is Empty\n";
	}
	else if (index >= 0 && index < length)

	{
		int x = A[index];
		for (int i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;


		return x;
	}
	else
	{
		cout << "Index given isn't valid\n";
	}
}

int Array::LinearSearch(int key)
{
	for (int i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			return i;
		}
	}
	return -1;
}

inline int Array::BinarySearch(int key)
{
	int mid, l, h;
	l = 0;
	h = length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;

		if (key == A[mid])
		{
			return mid;
		}
		else if (key < A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}

		return -1;
	}


	return 0;
}

inline int Array::Get(int index)
{
	if (index >= 0 && index < length)
	{
		return A[index];
	}
	return -1;
}

inline void Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
	{
		A[index] = x;
	}
}

inline int Array::Min()
{
	int min = A[0];
	for (int i = 1; i < length; i ++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
	}

	return min;
}

inline int Array::Max()
{
	int max = A[0];
	for (int i = 1; i < length; i++)
	{
		if (A[i] < max)
		{
			max = A[i];
		}
	}


	return max;
}

inline int Array::Sum()
{
	int sum = A[0];

	for (int i = 1; i < length; i++)
	{
		sum = sum + A[i];
	}

	return sum;
}

inline float Array::Average()
{
	return (float)Sum() / length;
}

inline void Array::Reverse()
{
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		Swap(&A[i], &A[j]);
	}
}

inline void Array::InsertSort(int x)
{
	int i = length - 1;
	if (size == length)
	{
		cout << "The array is full";
	}
	else
	{
		while (A[i] >= x)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = x;
	}
}

inline bool Array::IsSorted()
{
	int i;

	for (i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}

inline void Array::Rearrange()
{
	int i = 0;
	int j = length - 1;

	while (A[i] < 0) i++;
	while (A[j] > 0) j--;
	if (i < j) Swap(&A[i], &A[j]); 
	
	
}

inline Array* Array::Merge(Array arr2)
{
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);


	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j]) {
			arr3->A[k] = A[i];
			k++;
			i++; 

		} else
		{
			arr3->A[k] = arr2.A[j];
			k++;
			j++; 
		}

		
	}

	for (; i < length; i++)
	{
		arr3->A[k] = A[i];
		k++;
	}

	for (; j < arr2.length; j++)
	{
		arr3->A[k] = arr2.A[j];
		k++;
	}

	arr3->length = length = arr2.length;

	return arr3;


	
}

inline Array* Array::Union(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
		{
			arr3->A[k] = A[i];
			k++;
			j++; 
		} else if (arr2.A[j] < A[i])
		{
			arr3->A[k] = arr2.A[j];
			k++;
			j++; 
		} else
		{
			arr3->A[k] = A[i];
			k++;
			i++; 
			j++;
		}

		
	}

	for (; i < length ; i++)
	{
		arr3->A[k] = A[i];
		k++; 
	}

	for (; j < arr2.length; j++)
	{

		arr3->A[k] = A[j];
		k++; 
	}
	
	return arr3; 
}

inline Array* Array::Diff(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);


	while (A[i] < length && arr2.A[j])
	{
		if (A[i]< arr2.A[j])
		{
			i++; 
		} else if (arr2.A[j] < A[i])
		{
			j++; 
		} else
		{
			arr3->A[k] = A[i];
			i++;
			j++;
			k++; 
		}

		
	}
	arr3->length = k; 
	return arr3;
}

inline Array* Array::Inter(Array arr2)
{

	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
		{
			arr3->A[k] = A[i];
			k++;
			i++; 
		} else if  (arr2.A[j] < A[i])
		{
			j++; 
		} else
		{
			i++;
			j++; 
		}
		
	}

	for (; i < length; i++)
	{
		arr3->A[k] = A[i];
		i++;
		k++; 
	}

	arr3->length = k; 
	return arr3

	;
}
