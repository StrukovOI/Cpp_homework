#include <stdio.h>
#include <ctype.h>
int main()
{
    char a;
    scanf("%c", &a);
    if (isalpha(a))
        printf("Letter");
    else if (isdigit(a))
        printf("Digit");
	else
		printf("Other");
}