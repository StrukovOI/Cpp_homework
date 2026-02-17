#include <stdio.h>
#include <string.h>

int main() 
{
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};
    
    char *str_a = (char*)a;
    printf("a. %s", str_a);
    
    union
    {
        int nums[4];
        char str[16];
    } u;
    
    u.nums[0] = a[0];
    u.nums[1] = a[1];
    u.nums[2] = a[2];
    u.nums[3] = a[3];
    printf("b. %s", u.str);
    
    char str_c[16];
    memcpy(str_c, a, 16);
    printf("c. %s", str_c);
}