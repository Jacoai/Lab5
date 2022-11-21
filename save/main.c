#include <stdio.h>
#include "load.h"

int main()
{
    int menu=0;

    do
    {
        printf("1 Array\n");
        printf("2 Matrix\n");
        printf("3 Quit\n");
        scanf("%d",&menu);

    }
    while (menu<1  || menu>4);

    if(menu == 1)
        LoadRun("libArr.dll",1);
    if(menu == 2)
        LoadRun("libMat.dll",0);

    return 0;
}
