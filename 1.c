#include <stdio.h>
#include <time.h>
const int size = 30;

void makeArr(int *m)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++)
    {
        m[i] = rand() % 101;
    }
}

void makeEmptyArr(int *m){
    int i;
    for (i=0;i<size;i++)m[i]=0;
}

void printArr(int *m)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", m[i]);
    }
}

void copyArr(int *m, int *n)
{
    int i;
    for (i = 0; i < size; i++)
    {
        n[i] = m[i];
    }
}

void swap(int *e, int r)
{
    int a;
    a = e[r];
    e[r] = e[r + 1];
    e[r + 1] = a;
}

void swapback(int *e, int r)
{
    int a;
    a = e[r - 1];
    e[r - 1] = e[r];
    e[r] = a;
}

void booble(int *m)
{
    int i, a1, a2, b, c = 0, p = 0;
    for (b = 0; b < size - 1; b++)
        for (i = 0; i < size - 1; i++)
        {
            c++;
            if (m[i] > m[i + 1])
            {
                p++;
                swap(m, i);
            }
        }
    printf("c = %d | p = %d\n", c, p);
}

void booblenew(int *m)
{
    int i, j = 0, n, c = 0, p = 0;
    do
    {
        n = j;
        for (i = size - 1; i > n; i--)
        {
            c++;
            if (m[i - 1] > m[i])
            {
                p++;
                j = i;
                swapback(m, i);
            }
        }
    } while (j - n);
    printf("c = %d | p = %d\n", c, p);
}

void shacker(int *m)
{
    int i, a, check, c = 0, p = 0;
    do
    {
        check = 0;
        for (i = size - 1; i > 0; --i)
        {
            c++;
            if (m[i - 1] > m[i])
            {
                p++;
                swapback(m, i);
                check = 1;
            }
        }
        for (i = 1; i < size; i++)
        {
            c++;
            if (m[i - 1] > m[i])
            {
                p++;
                swapback(m, i);
                check = 1;
            }
        }
    } while (check);
    printf("c = %d | p = %d\n", c, p);
}

void select(int *m)
{
    int i, j, min, a, c = 0, p = 0;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            c++;
            if (m[j] < m[min])
                min = j;
            p++;
        }
        a = m[i];
        m[i] = m[min];
        m[min] = a;
    }
    printf("c = %d | p = %d\n", c, p);
}

void insert(int *m)
{
    int i, j, a, c = 0;
    double p = 0;
    for (i = 1; i < size; i++)
    {
        a = m[i];
        p += 1. / 3;
        for (j = i - 1; j >= 0 && m[j] > a; j--, c++)
        {
            p += 1. / 3;
            m[j + 1] = m[j];
        }
        m[j + 1] = a;
        p += 1. / 3;
    }
    printf("c = %d | p = %f\n", c, p);
}

void shella(int *m){
    int i,j,temp,step = size/2,c=0,p=0;
    while (step>0){
        for(i=0;i<(size-step);i++){
            c++;
            j=i;
            while(j >= 0 && m[j]>m[j+step]){
                c++;p++;
                temp = m[j];
                m[j] = m[j+step];
                m[j+step] = temp;
                j--;
            }
        }
        step/=2;
    }
    printf("c = %d | p = %d\n", c, p);
}

void main()
{
    int A[size], B[size], C[size];
    printf("\nA:\n");
    makeArr(A);
    printArr(A);

    printf("\nB:\n");
    copyArr(A, B);
    printArr(B);

    printf("\nBooble:\n");
    booble(B);
    printArr(B);

    printf("\nBoobleNew:\n");
    copyArr(A, B);
    booblenew(B);
    printArr(B);

    printf("\nShaker:\n");
    copyArr(A, B);
    shacker(B);
    printArr(B);

    printf("\nSelect:\n");
    copyArr(A, B);
    select(B);
    printArr(B);

    printf("\nInsert:\n");
    copyArr(A, B);
    insert(B);
    printArr(B);

    printf("\nShella:\n");
    copyArr(A,B);
    shella(B);
    printArr(B);
}