#include "load.h"
#include <stdio.h>
#include "Ar.h"
#include <windows.h>
#include "Mat.h"

void LoadRun(const char * const s, int flag) {
	int A[35];
    void*  lib;


    lib = LoadLibrary(s);
    if (lib == NULL) {
        printf("cannot open library '%s'\n", s);
        return;
    }

    if(flag)
    {
        void (*filArr)(int*,int);
        void (*outArr)(int*,int);
        int (*getMaxValue)(int*,int);
        void (*work)(int*,int,int);

        filArr = (void (*)(int*,int))GetProcAddress((HINSTANCE)lib, "fillar");
        outArr = (void (*)(int*,int))GetProcAddress((HINSTANCE)lib, "outArr");
        getMaxValue = (int (*)(int*,int))GetProcAddress((HINSTANCE)lib, "getMaxValue");
        work = (void (*)(int*,int,int))GetProcAddress((HINSTANCE)lib, "work");

        if(filArr == NULL){
            printf("cannot open filArr");
            return;
        }
        if(outArr== NULL){
            printf("cannot open outArr");
            return;
        }
        if(getMaxValue == NULL){
            printf("cannot open getMaxValue");
            return;
        }
        if(work == NULL){
            printf("cannot open work");
            return;
        }

        int max = A[0];
        filArr(A,35);
        printf("Array: \n");
        outArr(A,35);
        max = getMaxValue(A,35);
        printf("\nMax = %d",max);
        work(A,35,max);
        printf("\nChanged Array: \n");
        outArr(A,35);
    }
    else
    {
        int B[9][8];

        void (*filMat)(int*,int);
        void (*outMat)(int*,int,int);
        int (*getMaxValueRow)(int*,int);
        void (*workMat)(int*,int,int);

        filMat = (void (*)(int*,int))GetProcAddress((HINSTANCE)lib, "filMat");
        outMat = (void (*)(int*,int,int))GetProcAddress((HINSTANCE)lib, "outMat");
        getMaxValueRow = (int (*)(int*,int))GetProcAddress((HINSTANCE)lib, "getMaxValueRow");
        workMat = (void (*)(int*,int,int))GetProcAddress((HINSTANCE)lib, "workMat");

        if(filMat == NULL){
            printf("cannot open filMat");
            return;
        }
        if(outMat== NULL){
            printf("cannot open outMat");
            return;
        }
        if(getMaxValueRow == NULL){
            printf("cannot open getMaxValue");
            return;
        }
        if(workMat == NULL){

            printf("cannot open workMat");
            return;
        }

        filMat(B[0],9*8);
        printf("Matrix: \n");
        outMat(B[0],9,8);
        workMat(B[0],9,8);
        printf("\nChanged Matrix: \n");
        outMat(B[0],9,8);

    }

    FreeLibrary((HINSTANCE)lib); //выгрузка библиотеки;
}
