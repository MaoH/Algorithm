#include<iostream>
#include<vector>
#include<cassert>
#include<queue>
#include<functional>

using namespace std;

int max_k_qsort_help(vector<int>& vec, int begin, int end, int k)
{
	int pivot = vec[begin];
	int i = begin, j = end;
	while (i < j)
	{
		while (i < j && vec[j] <= pivot)
			j--;
		vec[i] = vec[j];
		while (i < j && vec[i] >= pivot)
			i++;
		vec[j] = vec[i];
	}
	vec[i] = pivot;
	if (k == i + 1)
	{
		return pivot;
	}
	else if (k < i + 1)
	{
		return max_k_qsort_help(vec, begin, i - 1, k);
	}
	else
	{
		return max_k_qsort_help(vec, i + 1, end, k);
	}
}

//qsort
int max_k_qsort(vector<int> vec, int k)
{
	assert(!vec.empty());
	assert(vec.size() >= k);
	return max_k_qsort_help(vec, 0, vec.size() - 1, k);
}


//priority_queue
int max_k_queue(vector<int>& vec, int k)
{
	assert(!vec.empty());
	assert(vec.size() >= k);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < vec.size(); i++)
	{
		if (i < k)
		{
			q.push(vec[i]);
		}
		else
		{
			if (vec[i] > q.top())
			{
				q.pop();
				q.push(vec[i]);
			}
		}

	}
	return q.top();
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,100,1000 };
	cout << max_k_queue(v, 4) << endl;
	vector<int> v1 = { 1,2,3,4,5,6,7,100,1000 };
	cout << max_k_qsort(v1, 4);
	getchar();
	getchar();
}