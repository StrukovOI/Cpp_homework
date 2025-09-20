#include <stdio.h>
#include <ctype.h>

int main() {
    int sum = 0;
    char c;

    c = getchar();
    while (c != '\n')
	{
        sum += c - '0';
    	c = getchar();
    }
    
    printf("%i", sum);
    return 0;
}