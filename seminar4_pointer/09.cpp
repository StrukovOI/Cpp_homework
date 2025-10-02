#include <stdio.h>
#include <string.h>


void used_chars(const char* str, char* used)
{
    int lett[26] = {0};
    for (int i = 0; str[i]; ++i)
    {
        char el = str[i];
        if (el >= 'A' && el <= 'Z')
        {
            el += 32;
        }
        if (el >= 'a' && el <= 'z')
        {
            lett[el - 'a'] = 1;
        }
    }

    size_t ind = 0;
    for (int i = 0; i != 26; ++i)
    {
        if (lett[i])
        {
            used[ind] = ('a' + i);
            ind++;
        }
    }
    used[ind] = '\0';
}

int main() 
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);  // Напечатает "adeprsu"
    
    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);  // Ничего не напечатает (только перенос строки)
    
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);  // Напечатает "abcdefghijklmnopqrstuvwxyz"    
}