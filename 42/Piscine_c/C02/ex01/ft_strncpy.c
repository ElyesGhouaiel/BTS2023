
#include <stdio.h>
#include <string.h>

char *ft_strncpy(char *dest, char *src, unsigned int n){
    size_t i=0;
while(i < n && src[i]!='\0')
    {
    dest[i] = src[i];
    i++;
    }
    dest[i]='\0';
    return dest;
}

int main(){
    char dest[]="Bonjoour";
    ft_strncpy(dest,"oui!",4);
    printf("%s \n",dest);
    return(0);
}