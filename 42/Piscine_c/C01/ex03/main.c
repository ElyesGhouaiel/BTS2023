void ft_div_mod(int a, int b, int *div, int *mod);

int main(){
    int a,b;
    int *p,*t;
    p=&a;
    t=&b;
    ft_div_mod(127,3,&a,&b);
}