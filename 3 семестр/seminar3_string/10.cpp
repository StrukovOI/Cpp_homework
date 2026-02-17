#include <stdio.h>
#include <string.h>

int main()
{
	int n, d, x = 0, y = 0;
	
	scanf("%i", &n);
	for (int i = 0; i != n; ++i)
	{
		char s[100];
		scanf("%99s %i", s, &d);

		if (!strcmp(s, "North"))
		{

			y += d;
		}
		else if (!strcmp(s, "South"))
		{
			y -= d;	
		}
		else if (!strcmp(s, "East"))
		{
			x += d;
		}
		else
		{
			x -=d;
		}
	}

	printf("%i %i", x, y);
}