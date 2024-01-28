#include <type_traits>
static int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int pindex = l;

	for (int i = l;i < r;i++)
	{
		if (arr[i] < pivot)
		{
			std::swap(arr[i], arr[pindex]);
			pindex++;
		}
	}
	std::swap(arr[r],arr[pindex]);

	return pindex;
}
static void quicksort(int arr[], int l, int r)
{
	if (l < r)
	{
		int p=partition(arr, l, r);
		quicksort(arr, l, p-1);
		quicksort(arr, p + 1, r);		
	}

}
