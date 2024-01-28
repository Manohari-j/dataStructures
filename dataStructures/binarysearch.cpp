
int binarysearch(int arr[], int left, int right, int val)
{
	
	if (right >=1)
	{
		int mid = left + (right -left)/ 2;

		if (val == arr[mid])
		{
			return mid;
		}
		if (val < arr[mid])
		{
			return binarysearch(arr, left, mid - 1, val);
		}
		return binarysearch(arr, mid + 1, right, val);
		
	}
	return -1;
	

}
