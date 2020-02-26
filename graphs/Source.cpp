#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<float>> list =
{
	{1, 2, 3, 4},
	{0, 2, 4},
	{0, 1},
	{0, 4},
	{0, 1, 3}

	//{1.0f, 2.0f, 3.0f},				//0
	//{0.0f, 4.0f, 5.0f},				//1
	//{0.0f, 6.0f},					//2
	//{0.0f, 7.0f},					//3
	//{1.0f},							//4
	//{1.0f, 9.0f},					//5
	//{2.0f},							//6
	//{3.0f, 8.0f},					//7
	//{7.0f},							//8
	//{5.0f}							//9

	//{0.0f, 1.0f, 2.0f, 3.0f},		//0
	//{0.0f, 1.0f, 4.0f, 5.0f},		//1
	//{0.0f, 2.0f, 6.0f},			//2
	//{0.0f, 3.0f, 7.0f},			//3
	//{1.0f, 4.0f},					//4
	//{1.0f, 5.0f, 9.0f},			//5
	//{2.0f, 6.0f},					//6
	//{3.0f, 7.0f, 8.0f},			//7
	//{7.0f, 8.0f},					//8
	//{5.0f, 9.0f},					//9
	//{6.0f, 10.0f},				//10
	//{6.0f, 11.0f},				//11
	//{9.0f, 12.0f},				//12
	//{9.0f, 13.0f},				//13

};

vector<vector<bool>> matrix;
vector<bool> was;
vector<bool> wasSt;
vector<bool> wasBfs;

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


void dfs(int start)
{
	if (was[start] == true)
		return;
	was[start] = true;
	for (int i = 0; i < list.size(); i++)
	{
		if (matrix[start][i] == true && was[i] == false)
		{
			cout << i << " ";
			dfs(i);
		}
	}
}

void stackDfs(int start)
{
	wasSt[start] = true;
	stack<float> st;
	st.push(start);

	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		for (int i = 0; i < list.size(); i++)
		{
			if (matrix[v][i] == true && wasSt[i] == false)
			{
				cout << i << " ";
				st.push(v);
				st.push(i);
				wasSt[i] = true;
				break;
			}
		}
	}
}

void bfs(int start)
{
	wasBfs[start] = true;
	queue<float> q;
	q.push(start);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < list.size(); i++)
		{
			if (matrix[v][i] && wasBfs[i] == false)
			{
				cout << i << " ";
				wasBfs[i] = true;
				q.push(i);
			}
		}
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


int main()
{
	showList(list);
	cout << endl;
	matrix = transformToMatrix(list);
	showMatrix(matrix);
	cout << endl;

	vector<vector<float>> list1 = transformToList(matrix);
	showList(list1);
	
	cout << endl;

	was.resize(matrix.size());
	wasSt.resize(matrix.size());
	wasBfs.resize(matrix.size());
	dfs(1);
	cout << endl;
	stackDfs(1);
	cout << endl;
	bfs(1);
	cout << "\n\n";



	system("pause");
}