// WAP to implement Max-Heapify Property on a given input array.

#include<iostream>

using namespace std;

//global decalaration 
#define size 10
int arr[20];

//swapping two numbers
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void max_heapify(int index)
{
	int l = 2 * index, r = 2 * index + 1; //finding left and right childs of the element
	int largest = index;

	//finding the largest from the parent, left child and right child
	if (arr[largest] < arr[l])
		largest = l;

	if (arr[largest] < arr[r])
		largest = r;

	/*if largest is not the parent, then exchange the parent with largest and call max_heapify
	for largest*/
	if (largest != index)
	{
		swap(arr[index], arr[largest]);
		max_heapify(largest);
	}
}

int main()
{
	int i;

	cout << "Enter an array : ";
	for (int j = 1; j <= size; j++)
		cin >> arr[j];

	cout << "\nEnter index of the element for which you want to apply Max-Heapify Property : ";
	cin >> i;

	cout << "\n\nEntered array : ";
	for (int j = 1; j <= size; j++)
		cout << arr[j] << " ";

	max_heapify(i);

	cout << "\nUpdated array : ";
	for (int j = 1; j <= 10; j++)
		cout << arr[j] << " ";

	return 0;
}
