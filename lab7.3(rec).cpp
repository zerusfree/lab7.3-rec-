#include <iostream>
#include <iomanip>

using namespace std;

void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void Input(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];
	if (j < colCount - 1)
		Input(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Input(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl;
}

int CountOfRows(int** a, const int rowCount, const int colCount, const int input, int i, int j,int resultCount)
{
	int sumOfRowElements = 0;

	if (i < rowCount)
	{
		if (j < colCount)
		{
			sumOfRowElements += a[i][j];
			CountOfRows(a, rowCount, colCount, input, i, j + 1,resultCount);
		}

		if (sumOfRowElements / colCount < input)
		{
			resultCount++;
		}

		sumOfRowElements = 0;

		CountOfRows(a, rowCount, colCount, input, i + 1, j,resultCount);
	}
	else 
		return  resultCount;
}

void Change(int** a, int currentRow, const int rowCount, const int colCount, int i, int j)
{
	if (a[currentRow][currentRow] == 0)
	{
		cout << "Error";
		return;
	}
	if (j < colCount)
	{
		a[currentRow][j] = a[currentRow][j] / a[currentRow][currentRow];
		Change(a, currentRow, rowCount, colCount, i, j + 1);
	}
	else
		return;
	if (i < rowCount)
	{
		if (i > currentRow)
		{
			a[i][currentRow] = a[i][currentRow] - a[currentRow][currentRow] * a[i][currentRow];
		}
		Change(a, currentRow, rowCount, colCount, i + 1, j);
	}
	else
		return;
}


void Triangulating(int** a, const int rowCount, const int colCount,int i)
{
	if (i < rowCount - 1)
	{
		Change(a, i, rowCount, colCount,0,0);
		Triangulating(a, rowCount, colCount, i + 1);
	}
	else
		return;
}


int main()
{
	srand((unsigned)time(NULL));

	int Low = -7;
	int High = 7;
	int input;
	int	resultCount = 0;

	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	//Input(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	Triangulating(a, rowCount, colCount,0);
	Print(a, rowCount, colCount, 0, 0);

	cout << "Enter a number = ";
	cin >> input;
	cout << "Result = " << CountOfRows(a, rowCount, colCount, input,0,0,resultCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;


	return 0;
}
