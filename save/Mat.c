#include <stdio.h>
#include <stdlib.h>
#include "Mat.h"

void filMat(int*a,int size)
{
    for(;size>0;size--)
        *a++ = rand()%100 -50;
}
void outMat(int *a, int row, int col){
    int i;
    for(;row>0;row--)
    {
        for(i=0;i<col;i++)
            printf("%5d", *a++);
        printf("\n");
    }
}

int getMaxValueRow(int *a, int col)
{
	int max = *a;

	for(int j=1;j<col;j++)
		if(abs(max) < abs(*(a+j)))
			max = abs(*(a+j));
    return max;
}

void workMat(int *a, int row, int col)
{
	int maxRow = *a;
	for(int i=0;i<row;i++)
	{
		maxRow = getMaxValueRow(a+i*col,col);
		printf("%d row max =%d \n",i,maxRow);

		for(int j=0;j<col;j++)
		{
			if(abs(*(a+i*col+j)) == abs(maxRow))
				*(a+i*col+j) = -*(a+i*col+j);
		}
	}
}

