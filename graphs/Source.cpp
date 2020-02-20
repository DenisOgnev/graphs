#include <iostream>
#include <vector>

using namespace std;

vector<vector<float>> transform(vector<vector<float>> vec)
{
	vector<vector<float>> temp(5, vector<float>(5));
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			temp[i][vec[i][j]] = 1;
		}
	}
	return temp;
}

int main()
{
	vector<vector<float>> list =
	{ 
		{0.0f, 1.0f, 2.0f, 3.0f, 4.0f},
		{0.0f, 1.0f, 2.0f, 3.0f},
		{0.0f, 1.0f, 2.0f, 4.0f},
		{0.0f, 1.0f, 3.0f, 4.0f},
		{0.0f, 2.0f, 3.0f, 4.0f}
	};

	for (int i = 0; i < list.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < list[i].size(); j++)
		{
			cout << list[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	vector<vector<float>> matrix = transform(list);

	cout << "  ";

	for (int i = 0; i < matrix.size(); i++)
	{
		cout << i << " ";
	}

	cout << endl;

	for (int i = 0; i < matrix.size(); i++)
	{
		cout << i << " ";
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
}