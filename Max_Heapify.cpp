// WAP to implement Max-Heapify Property on a given input array.

#include<iostream>

using namespace std;

//global decalaration 
#define size 11
int arr[size];

//swapping two numbers
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void max_heapify(int key)
{
	int l = 2 * key, r = 2 * key + 1; //finding left and right childs of the element
	int largest = key;

	//finding the largest from the parent, left child and right child
	if (arr[largest] < arr[l])
		largest = l;

	if (arr[largest] < arr[r])
		largest = r;

	/*if largest is not the parent, then exchange the parent with largest and call max_heapify
	for largest*/
	if (largest != key)
	{
		swap(arr[key], arr[largest]);
		max_heapify(largest);
	}
}

int main()
{
	int k;

	cout << "Enter an array : ";
	for (int i = 1; i <= 10; i++)
		cin >> arr[i];

	cout << "\nEnter key of the element for which you want to apply Max-Heapify Property : ";
	cin >> k;

	cout << "\n\nEntered array : ";
	for (int i = 1; i <= 10; i++)
		cout << arr[i] << " ";

	max_heapify(k);

	cout << "\nUpdated array : ";
	for (int i = 1; i <= 10; i++)
		cout << arr[i] << " ";

	return 0;
}