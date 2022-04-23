#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    int x,j,a = 0,b = 0;
    scanf("%d %d", &N, &x);
    int tab[x];
	int i = 0;
    while (i < N) {
        int A;
        int B;
        scanf("%d %d", &A, &B);
        j = 0;
        while(j < x)
        {
            if (j >= A && j <= A)
            {
                tab[j] += 1;
                j++;
            }
        }
		i++;
    }
    j = 0;
    while (j < x)
    {
        if (a > tab[j])
            a = tab[j];
        j++;
    }
    while (j < x)
    {
        if (b < tab[j])
            b = tab[j];
        j++;
    }
    printf("%d\n", a);
    printf("%d", b);
    return 0;
}