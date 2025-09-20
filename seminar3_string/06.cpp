#include <stdio.h>
#include <string.h>

bool is_palindrom(char a[100])
{
	int l = strlen(a);
	for (int i = 0; i < l/2; ++i)
	{
		if (a[i] != a[l-i-1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
    char a[100];
	scanf("%s", a);

	if (is_palindrom(a))
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

}