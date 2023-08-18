#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod){
    int z,y;
    div=&z;
    mod=&y;
    z=a/b;
    y=a%b;
}
int main(){
    int a,b;
    int *p,*t;
    p=&a;
    t=&b;
    ft_div_mod(15,3,&a,&b);
}