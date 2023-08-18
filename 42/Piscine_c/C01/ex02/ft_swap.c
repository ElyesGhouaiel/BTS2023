#include <stdio.h>

void ft_swap(int *a, int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int main(){
    int e,f;
    ft_swap(&e,&f);
    return(0);
}