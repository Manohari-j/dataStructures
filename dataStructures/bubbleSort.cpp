
static void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

static void bubblesort(int a[], int n)
{
	bool swapped=false;

	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n-i-1;j++)
		{
			swapped = false;
			if (a[j] < a[j+1])
			{
				swap(a[j], a[j+1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}

}