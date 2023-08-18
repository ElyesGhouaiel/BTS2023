#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b){
    int c,d;
    c =*a / *b;
    d =*a % *b;
    *a=c;
    *b=d;
}

int main(){
    int a,b;
    a=36,b=5;
    printf("initdiv : %d\n",a);
    printf("initreste : %d\n",b);
    ft_ultimate_div_mod(&a,&b);
    printf("div : %d\n",a);
    printf("reste : %d\n",b);
}