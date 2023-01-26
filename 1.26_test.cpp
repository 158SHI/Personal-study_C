#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<queue>

using namespace std;

void test1(void)
{
	vector<vector<int>> v = { {1,2,3,4,5}, {6,7,8,9,10} };
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void test2(void)
{
	int row = 0;
	int col = 0;
	cin >> row >> col;
	vector<vector<int>> v(row);
	for (int i = 0; i < row; i++)
	{
		v[i].resize(col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void test3(void)
{
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cout << arr[i] << " ";
	}
	delete[n] arr;
}

void test4(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.clear();

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test5(void)
{
	pair<int, int> p(0, 0);
	cin >> p.first >> p.second;
	cout << p.first + 1 << " " << p.second - 1 << endl;
}

void test6(void)
{
	int row = 3;
	int col = 4;
	vector<vector<int>> maze(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

void PrintPair(pair<int, int> pos)
{
	cout << pos.first << " " << pos.second << endl;
}

void test7(void)
{
	pair<int, int> pos(5, 8);
	PrintPair(pair<int, int>(pos.first + 1, pos.second - 1));
}

void test8(void)
{
	stack<int> st;
	st.push(1);
	st.pop();
}

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		vector<int> retNums;
		priority_queue< int, vector<int>, less<int> > heap;
		for (int i = 0; i < k; i++)
		{
			heap.push(arr[i]);
		}
		for (int i = k; i < arr.size(); i++)
		{
			if (arr[i] < heap.top())
			{
				heap.pop();
				heap.push(arr[i]);
			}
		}
		while(!heap.empty())
		{
			retNums.push_back(heap.top());
			heap.pop();
		}
		return retNums;
	}
};

void test9(void)
{
	Solution s;
	vector<int> v = { 3, 2, 1 };
	s.getLeastNumbers(v, 2);
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}