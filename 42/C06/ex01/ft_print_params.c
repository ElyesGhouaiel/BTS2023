#include <stdio.h>
#include <unistd.h>

void        ft_putstr(char *str){
    int i=0;
    while(str[i]!='\0'){
    write(1,&str[i],1);
    i++;
    }
}

int main (int argc, char **argvc){
    (void)argvc;
    (void)argc;
    write(1,&argc,1);
    ft_putstr(argvc[1]);
    return (0);
}