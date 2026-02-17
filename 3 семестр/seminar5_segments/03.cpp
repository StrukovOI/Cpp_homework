#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b)
{
    size_t la = strlen(a);
    size_t lb = strlen(b);
    char* c = (char*)malloc(sizeof(char) * (la + lb + 1));
    strcpy(c, a);
    strcat(c, b);
    return c;
}

int main()
{
    char a[50], b[50];
    scanf("%s %s", a, b);
    char* res = concat(a, b);
    printf("%s", concat(a, b));
    free(res);
}