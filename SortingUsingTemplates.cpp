/*
Write a program, using templates, to sort a list of n elements. Give user the option
to perform sorting using Insertion sort, Bubble sort or Selection sort.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

void print()
{
    cout << endl;
    for (int i = 0; i < 119; i++)
        cout << "-";
    cout << endl;
}
//swap two values
void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

//bubble sort
template <class T>
void bubble_sort(T arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < (n - 1); j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

//selection sort       
template <class T>
void selection_sort(T arr[], int n)
{
    int i, j, pos;
    T small;

    for (i = 0; i < n; i++)
    {
        small = arr[i];
        pos = i;
        for (j = i; j < n; j++)
            if (arr[j] < small)
            {
                small = arr[j];
                pos = j;
            }

        swap(arr[i], arr[pos]);
    }
}

//insertion sort
template <class T>
void insertion_sort(T arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((temp < arr[j]) && (j >= 0))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main()
{
    int array[10], n;
    char ch;

    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter Array : ";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    do
    {
        system("cls");
        print();
        cout << "\t\t\t\t\t\tMENU TO PERFORM SORTING";
        print();
        cout << "\n1. BUBBLE SORT";
        cout << "\n2. SELECTION SORT";
        cout << "\n3. INSERTION SORT";
        cout << "\n\nEnter choice : ";
        cin >> ch;

        switch (ch)
        {
        case '1': bubble_sort<int>(array, n);
            cout << "\nSorted Array : ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            break;
        case '2': selection_sort<int>(array, n);
            cout << "\nSorted Array : ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            break;
        case '3': insertion_sort<int>(array, n);
            cout << "\nSorted Array : ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            break;
        default: cout << "\nINVALID INPUT";
        }

        cout << "\nDo you want to conitune? : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}