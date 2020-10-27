//Symmetric Triangular Matrix using one-dimensional array

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

class SymmetricTriangularMatrix
{
	int* arr;
public:
	SymmetricTriangularMatrix(int);
	void insert(int, int, int);
	void show(int, int);
	int retrieval(int, int);
	~SymmetricTriangularMatrix();
};

//constructor
SymmetricTriangularMatrix::SymmetricTriangularMatrix(int size = 10)
{
	if (size != 0)
		arr = new int[size * (size + 1) / 2];
	else
		arr = 0;
}

void SymmetricTriangularMatrix::insert(int data, int i, int j)
{
	arr[i * (i + 1) / 2 + j] = data;
}

void SymmetricTriangularMatrix::show(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= j)
				cout << arr[i * (i + 1) / 2 + j] << "\t";
			else
				cout << arr[i * (i + 1) / 2 + j] << "\t";
		}

		cout << endl;
	}
}

int SymmetricTriangularMatrix::retrieval(int x, int y)
{
	if (x <= y)
		return arr[x * (x + 1) / 2 + y];
	else
		return arr[y * (y + 1) / 2 + x];
}

//destructor
SymmetricTriangularMatrix::~SymmetricTriangularMatrix()
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

	SymmetricTriangularMatrix obj(m);

	do
	{
		system("cls");

		print();
		cout << "\t\t\t\t\t\tSYMMETRIC TRIANGULAR MATRIX";
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
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					cout << "Enter data : ";
					cin >> data;
					if (i >= j)
						obj.insert(data, i, j);
				}
		}
				else
			cout << "\nMatrix size entered is zero.";
			break;

		case '2': cout << "\nMatrix is:-\n";
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
				cout << "\nRetrieved Value : " << obj.retrieval(x, y);
			break;

		default: cout << "\nINVALID INPUT";
		}

		cout << "\nDo you wish to continue? : ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
