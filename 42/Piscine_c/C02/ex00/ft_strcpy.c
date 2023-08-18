#include <stdio.h>
#include <string.h>

char* ft_strcpy(char *dest, char *src){
    size_t i=0;
    while(src[i]!='\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i]='\0';
    return dest;
}

int main(){
    char dest[]="Bonjoour";

    ft_strcpy(dest,"oui");
    printf("%s \n",dest);
    return(0);
}