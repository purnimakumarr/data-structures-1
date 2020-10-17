#include<iostream>

using namespace std;

//global declaration
int arr[20];
int size = 10;
int length = ::size;

int getParent(int i)
{
	return (i / 2);
}

int getLeft(int i)
{
	return 2 * i;
}

int getRight(int i)
{
	return (2 * i + 1);
}

//swap two values
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

//converts an array into max heap for a particular index
void max_heapify(int index)
{
	int l = getLeft(index), r = getRight(index); //finding left and right childs of the element
	int largest = index;

	//finding the largest from the parent, left child and right child
	if ((largest<=::length && l<=::length) && arr[largest] < arr[l])
		largest = l;

	if ((largest<=::length && r<=::length) && arr[largest] < arr[r])
		largest = r;

	/*if largest is not the parent, then exchange the parent with largest and call max_heapify
	for largest*/
	if (largest != index)
	{
		swap(arr[index], arr[largest]);
		max_heapify(largest);
	}
}

//converts an array into a max heap
void build_max_heap()
{
	for (int i = ::size / 2; i >= 1; i--)
	{
		max_heapify(i);
	}
}


int main()
{
	cout << "Enter any random array(size 10) : ";
	for (int i = 1; i <= ::size; i++)
		cin >> arr[i];

	build_max_heap();

	cout << "\nMax Heap : ";
	for (int i = 1; i <= ::size; i++)
	{
		cout << arr[i] << " ";
	}

	for (int j = ::size; j >= 2; j--)
	{
		swap(arr[1], arr[j]);
		::length = ::length - 1;
		max_heapify(1);
	}

	cout << "\nArray in ascending order : ";
	for (int i = 1; i <= ::size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}