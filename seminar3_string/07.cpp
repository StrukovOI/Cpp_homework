#include <stdio.h>
#include <string.h>

void encrypt(char* str, int k)
{
	for (size_t i = 0; i < strlen(str); ++i)
	{

    	if (str[i] <= 'Z' && str[i] > 'A')
		{
			str[i] += k;
			if (str[i] > 'Z')
			{
				str[i] -= 26;
			}			
		}

		else if (str[i] >= 'a')
		{
			str[i] += k;
			if (str[i] > 'z')
			{
				str[i] -= 26;
			}
		}
	}
}

int main()
{
    int k;
    char c[100];
	scanf("%i ", &k);

	fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n")] = '\0';

    encrypt(c, k);
    printf("%s", c);
}