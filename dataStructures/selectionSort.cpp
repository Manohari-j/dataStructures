
static void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

static void Selectionsort(int a[], int n)
{
	
	for (int i = 0;i < n - 1;i++)
	{
		int min = i;
		for (int j = i + 1;j < n;j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a[i], a[min]);
		}
	}

}