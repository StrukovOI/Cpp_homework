#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n)
{
    float* progression = (float*)malloc(n * sizeof(float));
    
    progression[0] = a;
    for (int i = 1; i != n; ++i)
    {
        progression[i] = progression[i-1] * r;
    }
    
    return progression;
}

int main()
{
    float* progression = get_geometric_progression(1.0, 3.0, 10);
    
    for (int i = 0; i != 10; ++i)
    {
        printf("3^%i = %.0f\n", i, progression[i]);
    }
    
    free(progression);

}