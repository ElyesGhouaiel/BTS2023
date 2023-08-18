#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argvc){
    (void)argvc;
    (void)argc;
    write(1,argc,1);
    write(1,argvc,1);
    return 0;
    }