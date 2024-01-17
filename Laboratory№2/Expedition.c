#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, k;
    int amountofplots, rezult = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    amountofplots = n * m;
    int *arrplots = malloc(amountofplots * sizeof(int));
    for (int i = 0; i < amountofplots; i++)
    {
        scanf("%d", &arrplots[i]);
    }

    scanf("%d", &k);
    int* arrmesklinit = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arrmesklinit[i]);
    }

    for (int i = 1; i < amountofplots; i++)
    {
        int j = i;
        while (j > 0 && arrplots[j - 1] > arrplots[j])
        {
            int tmp = arrplots[j - 1];
            arrplots[j - 1] = arrplots[j];
            arrplots[j] = tmp;
            j--;
        }
    }

    for (int i = 1; i < k; i++)
    {
        int j = i;
        while (j > 0 && arrmesklinit[j - 1] > arrmesklinit[j])
        {
            int tmp = arrmesklinit[j - 1];
            arrmesklinit[j - 1] = arrmesklinit[j];
            arrmesklinit[j] = tmp;
            j--;
        }
    }

    for (int i = 0; i < (((amountofplots) < (k)) ? (amountofplots) : (k)); i++)
    {
        for (int j = 0; j < (((amountofplots) < (k)) ? (amountofplots) : (k)); j++)
        {
            if (arrmesklinit[i] <= arrplots[j])
            {
                rezult++;
                arrplots[j] = 0;
                break;
            }
        }
    }
    printf("%d ", rezult);
    return 0;
}
