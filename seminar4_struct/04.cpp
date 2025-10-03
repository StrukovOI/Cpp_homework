#include <stdio.h>
#include <stddef.h>

struct cat
{
    char x;
    size_t y;
};

struct dog
{
    size_t y;
    char x;
};

struct mouse
{
    char x;
    char y;
    size_t z;
};

struct rat
{
    char x;
    size_t z;
    char y;
};

struct fox
{
    char x;
    struct mouse y;
};

int main() {
    printf("char: sizeof = %zu, alignof = %zu\n", sizeof(char), alingof(char));
    printf("int: sizeof = %zu, alignof = %zu\n", sizeof(int), alingof(int));
    printf("size_t: sizeof = %zu, alignof = %zu\n", sizeof(size_t), alingof(size_t));
    printf("int[10]: sizeof = %zu, alignof = %zu\n", sizeof(int[10]), alingof(int[10]));
    printf("int*: sizeof = %zu, alignof = %zu\n", sizeof(int*), alingof(int*));
    printf("struct cat: sizeof = %zu, alignof = %zu\n", sizeof(struct cat), alingof(struct cat));
    printf("struct dog: sizeof = %zu, alignof = %zu\n", sizeof(struct dog), alingof(struct dog));
    printf("struct mouse: sizeof = %zu, alignof = %zu\n", sizeof(struct mouse), alingof(struct mouse));
    printf("struct rat: sizeof = %zu, alignof = %zu\n", sizeof(struct rat), alingof(struct rat));
    printf("struct fox: sizeof = %zu, alignof = %zu\n", sizeof(struct fox), alingof(struct fox));
    
    return 0;
}