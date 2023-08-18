#include <stdio.h>

int ft_strlen(char *str){
    int c=0;
    while (str[c] != '\0'){
        c++;
    }       
    return c;
}

int main(){
    int t;
    t = ft_strlen("Let's go!");
    return (0);
}