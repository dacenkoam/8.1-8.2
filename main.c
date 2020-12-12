 #include <stdio.h>
#include <stdlib.h>
 #include <stdlib.h>
int comp=0, change=0;
void bsort(int* a, int n){
    int i, j, buffer;
    for(i = 0 ; i<n-1; i++)
        for(j=n-2; j>=i; j--){
            if(a[j]>a[j+1]){
                buffer=a[j];
                a[j]=a[j+1];
                a[j+1]=buffer;
                change++;
            }
            comp++; }
}

void qsortt(int* a, int begin, int end)
{
    int l = begin, r = end;
    int mid=l+(r-l)/2;
    int middle = a[mid];
    while(l <= r)
    {

        while(l!=mid && a[l] < middle){ l++; comp++;}
        if (l!=mid) comp++;

        while(r!= mid && a[r] > middle){ r--; comp++;}
        if (r!=mid) comp++;


        if(l < r )
        {
            if (l!=r){
                int tmp = a[l];
                a[l] = a[r];
                a[r] = tmp;
                l++, r--;
                change++;
            }
            else {l++; r--;}
        }
        else if (l==r){l++;r--;}
    }
    if(begin < r)
        qsortt(a, begin, r);
    if(l < end)
        qsortt(a, l, end);
}


int main()
{
    int *pa, i, n,rrrrr;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while(1){
        comp=0; change=0;
        printf("Как сортировать?\n2 - быстрая сортировка\n0 - никак\n");
        scanf("%d",&rrrrr);
        switch(rrrrr){
        case 1: {printf("Введите количество элементов массива\n") ;
                scanf("%d", &n);
                pa = (int*) calloc(n, sizeof(int));
                printf("Введите элементы массива\n") ;
                for(i=0; i<n; i++){
                    scanf("%d", &pa[i]);}
                bsort(pa, n);
                for(i=0;i<n;i++){printf("%d ",pa[i]);}
                printf("\nSravneniy:%d   Perestanovok:%d\n",comp, change); break; }
        case 2:{ printf("Введите количество элементов массива\n") ;
                scanf("%d", &n);
                pa = (int*) calloc(n, sizeof(int));
                printf("Введите элементы массива\n") ;
                for(i=0; i<n; i++){
                    scanf("%d", &pa[i]);}
                qsortt(pa, 0, n-1) ;
                for(i=0;i<n;i++){printf("%d ",pa[i]);}
                printf("\nSravneniy:%d   Perestanovok:%d\n",comp, change); break; }
        case 0:{ return 0;}
    }
} }
