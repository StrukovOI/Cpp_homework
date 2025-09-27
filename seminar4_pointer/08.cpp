#include <stdio.h>

void set_characters(char* begin, char* end, char c)
{
    for (int i = 0; i != (end - begin); ++i)
    {
        *(begin + i) = c;
    }
}

int main() 
{
    char s[] = "Sapere Aude";
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s);  // Напечатает Sabbbbbbude
    set_characters(s, &s[4], 'a');
    printf("%s\n", s);  // Напечатает aaaabbbbude
}