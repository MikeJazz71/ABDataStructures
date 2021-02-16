
#include "ABArray.h"
#include "LinkedList.h"; 
using namespace std;


int main()
{
	int A[] = { 5, 10, 20 , 30, 40};
	LinkedList LL  = LinkedList(A, 5);
	LL.SortedList(22); 

	LL.Display();
	
	

	
	
	




	/*Array* arr1;
	int ch, sz, x, index, num, ele; 
	cout << "What is the Array size? \n";
	cin >> sz;
	arr1 = new Array(sz);

	cout << "How many intial elements: \n"; 
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "Enter the Element: "; 
		cin >> ele;
		arr1->Append(ele); 
	}
	

	do
	{

		cout << "\nMenu\n";
		cout << "1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Search\n";
		cout << "4. Sum\n"; 
		cout << "5. Display\n";
		cout << "6. Exit\n";

		cout << "Enter your choice: "; 
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter an index: ";
			cin >> index;
			cout << "Enter the element: ";
			cin >> x; 
			arr1->Insert(index, x);
			break;

		case 2: cout << "Enter index: ";
			cin >> index;
			x = arr1->Delete(index);
			cout << "Deleted index is " << x;
			break; 

		case 3: cout << "Enter an element to search for: ";
			cin >> x;
			index = arr1->LinearSearch(x);
			cout << "Element index is at " << index;
			break;

		case 4: cout << "Sum is: " << arr1->Sum();
			break;

		case 5: arr1->Display();

			
			
		}
		
	} while (ch < 6);

	*/
	return 0; 
	
	
	
	
}

