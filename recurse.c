#include <stdio.h>
#include <stdlib.h>

double rec_fact_up(int n){
    if(n<=1) return 1.0;
    else return rec_fact_up(n-1)*n;
}

unsigned long fib(int n){
    if(n==0 || n==1) return 1;
    return fib(n-1)+fib(n-2);
}

double rec_step(float x, int n){
    if (n<=0) return 1.0;
    else return rec_step(x,n-1)*x;
}

double rec_degree(double x, int n){
    double r;
    if(!n) return 1;
    if(!(n%2)) return r=rec_degree(x,n/2),r*r;
    else return x*rec_degree(x,n-1);
}

int NOD_rec(int a, int b){
    if(!(a%b)) return b;
    else return NOD_rec(b,a%b);
}

void printd(int k){
    if(k<0){
        putchar('-');
        k=-k;
    }
    if(k) printd(k/10);
    putchar(k%10 + '0');
}

void Reverse(){
    int ch;
    if((ch=getch())!='\r'){
        Reverse();
        putchar(ch);
    }
}

int sum(int *s, int n){
    if (n==1) return s[0];
    else return sum(s,n-1)+s[n-1];
}

int main(){
    int k,size,s[]={1,2,3,4,5,6,7};
    double x2;
    float x;
    printf("input K:\n");
    scanf("%d",&k);
    printf("k = %d\n",k);
    printf("factorial = %f\n",rec_fact_up(k));
    printf("input Size:\n");
    scanf("%d",&size);
    printf("Size = %d\n",size);
    printf("Fib: ");
    for(int i=0;i<=size;i++){
        printf("%ld ",fib(i));
    }
    printf("\ninput float x: ");
    scanf("%f",&x);
    printf("%f in step %d = %f",x,k,rec_step(x,5));
    printf("\ninput double x: ");
    scanf("%lf",&x2);
    printf("%lf in step %d = %lf",x2,k,rec_degree(x2,5));
    printf("\n NOD= %d\n", NOD_rec(k,size));
    printf("printd = ");
    printd(k);
    printf("\n Reverse = ");
    Reverse();
    printf("\n sum = %d", sum(s,size));
}