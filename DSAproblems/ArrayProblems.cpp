#include<iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;

//1. Check if pair with the given Sum exists in Array
/*Input: arr[] = {0, -1, 2, -3, 1}, x= -2
Output: Yes
Explanation:  If we calculate the sum of the output,1 + (-3) = -2*/
//Naive Approach: T:O(n^2), s:O(1)
/*bool sumArray(int arr[], int n, int x)
{
	for (int i = 0;i < n-1;i++)
	{
		for (int j = i+1;j < n;j++)
		{
			if (x == (arr[j] + arr[i]))
			{
				return true;
			}
		}			
	}
	return false;
}*/

//Sorting and 2 pointers: T:O(nlogn), s:O(1)
/*
bool sumArray(int arr[], int n, int x)
{
	int l = 0;
	int r = n - 1;

	sort(arr, arr+n);

	while (l < r)
	{
		int sum = (arr[l] + arr[r]);
		if (x == sum)
		{
			return true;
		}
		else if (x < sum)
		{
			r--;
		}
		else
		{
			l++;
		}
	}
	return false;
}*/
//Binary Search (x-a[i]) :  T:O(nlogn), s:O(1)
/*
bool binarySearch(int arr[],int l, int r, int val)
{
	int mid = (l + r) / 2;
	if (arr[mid] == val)
		return true;
	else if (arr[mid] <val)
	{
		l = mid + 1;
	}
	else
	{
		r = mid - 1;
	}
	return false;

}
bool sumArray(int arr[], int n, int x)
{
	sort(arr, arr + n);
	
	for (int i = 0;i < n - 1;i++)
	{
		int target = x - arr[i];
		if (binarySearch(arr,(i + 1), (n - 1), target))
			return true;
	}
	return false;
	
}*/

//Hashing :  T:O(n), s:O(n)
bool sumArray(int arr[], int n, int x)
{
	unordered_set<int> s;

	for (int i = 0;i < n;i++)
	{
		int target = x-arr[i];
		if (s.find(target) != s.end())
			return true;
		s.insert(arr[i]);
	}
	return false;

	

}

int main()
{
	int arr[] = { 1, 4,45, 6, 10, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 16;
	if (sumArray(arr, n, x))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}