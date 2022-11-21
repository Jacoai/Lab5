#include "ar.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillar(int*a,int n)
{
    srand(time(NULL));

	for(int i=0;i<n;i++)
		a[i] = rand()%100 - 50;
}
void outArr(int*a,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
}
int getMaxValue(int *a, int n)
{
	int max = a[0];
	for(int i=0;i<n;i++)
		if(abs(max)< abs(a[i]))
			max = a[i];

	return max;
}

void work(int *a, int n, int maxValue)
{
	for(int i=0;i<n;i++)
		if(abs(a[i]) == abs(maxValue))
			a[i] = - a[i];
}
