#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "rb");
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);
    printf("%i", size);
}