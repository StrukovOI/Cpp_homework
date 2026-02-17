#include <stdio.h>
#include <string.h>

void safe_strcpy (char a[], size_t n, const char b[])
{
	for (size_t i = 0; i < n - 1; ++i)
	{
		a[i] = b[i];
	}
	a[n-1] = '\0';
}

int main()
{
	char a[10] = "Mouse";
	char b[50] = "LargeElephant";
	safe_strcpy(a, 10, b);
	// printf("%s", a);
}