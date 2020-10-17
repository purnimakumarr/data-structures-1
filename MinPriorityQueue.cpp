/*
Write a mennu driven program to impplement Min_Priority_Queue that supports the following
operations:-
1. Heap_Decrease_Key
2. Min_Heap_Insert
3. Heap_Minimum
4. Heap_Extract_Min
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

//global declaration
int size = 10;
int arr[20];

int getParent(int i)
{
	return floor(i / 2);
}

int getLeft(int i)
{
	return 2 * i;
}

int getRight(int i)
{
	return (2 * i + 1);
}

//swap two numbers
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void min_heapify(int index)
{
	int l = getLeft(index), r = getRight(index); //finding left and right childs of the element
	int smallest = index;

	//finding the largest from the parent, left child and right child
	if (arr[smallest] > arr[l])
		smallest = l;

	if (arr[smallest] > arr[r])
		smallest = r;

	/*if largest is not the parent, then exchange the parent with largest and call max_heapify
	for largest*/
	if (smallest != index)
	{
		swap(arr[index], arr[smallest]);
		min_heapify(smallest);
	}
}

void heap_decrease_key(int index, int value)
{
	if (value < arr[index])
	{
		arr[index] = value;

		while (index > 1 && arr[getParent(index)] > arr[index])
		{
			swap(arr[getParent(index)], arr[index]);
			index = getParent(index);
		}

		cout << "\nUpdated array : ";
		for (int j = 1; j <= ::size; j++)
			cout << arr[j] << " ";
	}
	else
		cout << "Value entered is greater than existing value. Cannot increase value.";

}

void min_heap_insert(int value)
{
	::size++; //increases size of array
	arr[::size] = value+1;
	heap_decrease_key(::size, value);

}

int heap_minimum()
{
	return arr[1];
}

int heap_extract_min()
{
	int temp = arr[1];
	swap(arr[1], arr[::size]);
	::size--;
	min_heapify(1);

	return temp;
}


int main()
{
	char ch; int option, i, value;

	cout << "Enter array : ";
	for (int j = 1; j <= ::size; j++)
		cin >> arr[j];

	do
	{
		system("cls");
		cout << "Array:-  \n\n";
		for (int j = 1; j <= ::size; j++)
			cout << arr[j]<<" ";

		cout << endl<< endl;

		for (int j = 0; j < 120; j++)
			cout << "-";
		cout << "\n\t\t\t\tMENU TO PERFORM FOLLOWING OPERATIONS ON MIN PRIORITY QUEUE\n";
		for (int j = 0; j < 120; j++)
			cout << "-";

		cout << "\n\n1. Heap Decrease Key";
		cout << "\n2. Min Heap Insert";
		cout << "\n3. Heap Minimum";
		cout << "\n4. Heap Extract Minimum";
		cout << "\nEnter choice: ";
		cin >> option;

		switch (option)
		{
		case 1: cout << "\nEnter index : ";
			cin >> i;
			cout << "\nEnter new value (sholud be <arr[index]) : ";
			cin >> value;
			heap_decrease_key(i, value);
			break;

		case 2: cout << "Enter value to be inserted : ";
			cin >> value;
			min_heap_insert(value);
			break;

		case 3: i = heap_minimum();
			cout << "Smallest element : " << i;
			break;

		case 4: value = heap_extract_min();
			cout << "\nValue Deleted : " << value;
			cout << "\nUpdated array : ";
			for (int j = 1; j <= ::size; j++)
				cout << arr[j] << " ";
			break;

		default: cout << "\nINVALID INPUT";
		}
		cout << "\nDo you want to go back to menu(y/n) : ";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}