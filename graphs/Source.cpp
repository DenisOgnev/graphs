#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void showList(vector<vector<float>> l)
{
	for (int i = 0; i < l.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < l[i].size(); j++)
		{
			cout << l[i][j] << " ";
		}
		cout << endl;
	}
}

void showMatrix(vector<vector<bool>> m)
{
	cout << "  ";

	for (int i = 0; i < m.size(); i++)
	{
		cout << i << " ";
	}

	cout << endl;

	for (int i = 0; i < m.size(); i++)
	{
		cout << i << " ";
		for (int j = 0; j < m[i].size(); j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<bool>> transformToMatrix(vector<vector<float>> vec)
{
	vector<vector<bool>> temp(vec.size(), vector<bool>(vec.size()));
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			temp[i][vec[i][j]] = true;
		}
	}
	return temp;
}

vector<vector<float>> transformToList(vector<vector<bool>> m)
{
	vector<vector<float>> temp(m.size());
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			if (m[i][j] == true)
				temp[i].push_back(j);
		}
	}
	return temp;
}

void dfs(int v, vector<vector<float>> g)
{
	vector<bool> was(g.size());
	was[v] = true;

}

int main()
{
	vector<vector<float>> list =
	{
		{1.0f, 2.0f, 3.0f},				//0
		{0.0f, 4.0f, 5.0f},				//1
		{0.0f, 6.0f},					//2
		{0.0f, 7.0f},					//3
		{1.0f},							//4
		{1.0f, 9.0f},					//5
		{2.0f},							//6
		{3.0f, 8.0f},					//7
		{7.0f},							//8
		{5.0f}							//9

		//{0.0f, 1.0f, 2.0f, 3.0f},		//0
		//{0.0f, 1.0f, 4.0f, 5.0f},		//1
		//{0.0f, 2.0f, 6.0f},				//2
		//{0.0f, 3.0f, 7.0f},				//3
		//{1.0f, 4.0f},					//4
		//{1.0f, 5.0f, 9.0f},				//5
		//{2.0f, 6.0f},					//6
		//{3.0f, 7.0f, 8.0f},				//7
		//{7.0f, 8.0f},					//8
		//{5.0f, 9.0f}					//9
		//{6.0f, 10.0f},				//10
		//{6.0f, 11.0f},				//11
		//{9.0f, 12.0f},				//12
		//{9.0f, 13.0f},				//13

	};

	showList(list);

	cout << endl;

	vector<vector<bool>> matrix = transformToMatrix(list);

	showMatrix(matrix);

	cout << endl;

	vector<vector<float>> list1 = transformToList(matrix);
	showList(list1);

	system("pause");
}