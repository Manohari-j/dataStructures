static int fact(int n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1);
}

static int recurfact(int n)
{
	int f=1;
	for (int i = 1;i <= n;i++)
	{
		f *= i;
	}
	return f;
}