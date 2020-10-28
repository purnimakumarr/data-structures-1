//Upper Triangular Matrix using one-dimensional array

#include<iostream>
#include<stdlib.h>

using namespace std;

//only for formatting
void print()
{
	cout << endl;
	for (int i = 0; i <= 119; i++)
		cout << "-";
	cout << endl;
}

class UpperTriangularMatrix
{
	int* arr;
public:
	UpperTriangularMatrix(int);
	void insert(int, int, int, int);
	void show(int, int);
	int retrieval(int, int, int);
	~UpperTriangularMatrix();
};

//constructor
UpperTriangularMatrix::UpperTriangularMatrix(int size=10)
{
	if (size != 0)
		arr = new int[size * (size + 1) / 2];
	else
		arr = 0;
}

void UpperTriangularMatrix::insert(int data, int i, int j, int m)
{
		arr[m * i - i * (i + 1) / 2 + j] = data;
}

void UpperTriangularMatrix::show(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= i)
				cout << arr[m * i - i * (i + 1) / 2 + j] << "\t";
			else
				cout << "0" << "\t";
		}
		cout << endl;
	}
}

int UpperTriangularMatrix::retrieval(int m, int x, int y)
{
	if (x <= y)
		return arr[m * x - x * (x + 1) / 2 + y];
	else
		return 0;
}

//destructor
UpperTriangularMatrix::~UpperTriangularMatrix()
{
	delete[] arr;
}

int main()
{
	char ch; int m, n, data, x, y;

	cout << "Enter size of array :-\n";
	cout << "m : ";
	cin >> m;
	cout << "n: ";
	cin >> n;

	if (m != n)
	{
		cout << "Invalid size.";
		exit(0);
	}

	UpperTriangularMatrix obj(m);

	do
	{
		print();
		cout << "\t\t\t\t\t\tUPPER TRIANGULAR MATRIX";
		print();
		cout << "\n1. Enter Matrix";
		cout << "\n2. Print Matrix";
		cout << "\n3. Retrieve A Value";
		cout << "\n\nEnter choice : ";
		cin >> ch;

		switch (ch)
		{
		case '1': if (m != 0)
		{
			cout << "Enter Matrix :-\n";
			for(int i=0; i<m; i++)
				for (int j = 0; j < n; j++)
				{
					cout << "Enter data : ";
					cin >> data;
					if (j>=i) 
						obj.insert(data, i, j, m);
				}
		}
				else
		{
			cout << "\nEntered index is zero.";
			exit(0);
		}
				break;

		case '2': cout << "Matrix:-\n";
			obj.show(m, n);
			break;

		case '3': cout << "Enter index whose value you want to retrieve :-\n";
			cout << "x : ";
			cin >> x;
			cout << "y : ";
			cin >> y;
			if (x<0 || y<0 || x>m || y>n)
				cout << "\nIndex out of range.";
			else
				cout << "\nRetrieved Value : " << obj.retrieval(m, x, y);
			break;

		default: cout << "\nINVALID INPUT";
		}
	
		cout << "\nDo you want to continue? : ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
