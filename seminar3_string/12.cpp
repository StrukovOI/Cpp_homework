#include <stdio.h>

int main(int argc = 2, char** argv) 
{
    for (int i = 0; i < (int)argv[0]; ++i)
    {
        printf("%s\n", argv[1]);
    }
}