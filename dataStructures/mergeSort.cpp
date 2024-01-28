static void merge(int arr[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	int temp[10];

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while (i <= m)
	{
		temp[k++] = arr[i++];
	}
	while (j <= r)
	{
		temp[k++] = arr[j++];
	}

	for (int p = l;p <= r;p++)
	{
		arr[p] = temp[p];
	}
}
static void mergesort(int arr[], int l, int r)
{
	int mid;
	
	if (l<r)
	{
		mid = (l + r) / 2;
		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}

}
