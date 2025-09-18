#include <stdio.h>
#include <math.h>

const double step = 1e-2, eps = 1e-10;

double gamma(double x)
{
    double s = 0.0, t = 0.0, pred = pow(t, x - 1) * exp(-t);
    
    while (true)
    {
        t += step;
        double el = pow(t, x - 1) * exp(-t);
        double sq = (pred + el) * step / 2.0;
        
        if (sq < eps)
        {
            break;
        }
        s += sq;
        pred = el;
    }
    
    return s;
}

int main()
{
    double x;
    scanf("%lf", &x);
    
    if (x == (int)x)
    {
        int n = (int)x;
        long long fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
        }

        if (fact > 1e10)
        {
            printf("%.5e", (double)fact);
        }

        else
        {
            printf("%.1f", (double)fact);
        }
    }

    else
    {
            double result = gamma(x);
            if (result > 1e10)
            {
                printf("%.5e", result);
            }
            else
            {
                printf("%.6lf", result);
            }
    }
    
    return 0;
}