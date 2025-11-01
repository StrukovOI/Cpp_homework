#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char bytes[3];
    FILE *file = fopen(argv[1], "rb");
    fseek(file, -3, SEEK_END);
    fread(bytes, 1, 3, file);

    for (int i = 0; i < 3; ++i)
    {
        printf("%02X ", bytes[i]);
    }

    fclose(file);
}