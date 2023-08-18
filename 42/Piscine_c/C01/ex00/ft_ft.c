#include <stdio.h>

void        ft_ft(int *ptr){
    *ptr = 42;
}
int main(){
    int a ;
    ft_ft(&a);
    }