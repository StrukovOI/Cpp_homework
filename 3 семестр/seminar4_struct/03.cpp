#include <stdio.h>
#include <string.h>

struct game 
{
    char title[50];
    float rating;
};
typedef struct game Game;

int main()
{
    int n;
    scanf("%i ", &n);
    
    Game array[n];
    
    for (int i = 0; i != n; ++i)
    {
        char title[50];
        char temp;
        int k, s = 0, el;

        scanf("%[^:]", title);
        scanf("%c", &temp);
        scanf("%i", &k);
        
        for (int j = 0; j != k; ++j)
        {
            scanf("%i", &el);
            s += el;
        }
        
        strcpy(array[i].title, title);
        array[i].rating = (float)s / k;
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    }

    for (int i = 0; i != n - 1; ++i)
    {
        for (int j = i + 1; j != n; ++j)
        {
            if (array[i].rating < array[j].rating)
            {
                Game temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i != n; ++i)
    {
        printf("%s, %.3f\n", array[i].title, array[i].rating);
    }
    
    return 0;
}