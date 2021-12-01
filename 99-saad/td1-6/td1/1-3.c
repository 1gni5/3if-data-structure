#include<stdio.h>
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)

int main(){
    int a1,a2,b1,b2;
    scanf(" %d", &a1);
    scanf(" %d", &b1);
    scanf(" %d", &a2);
    scanf(" %d", &b2);
    int result = 0;
    result = min(b1,b2) - max(a1,a2);
    if(result > 0) printf("%d\r\n", result);
    if(result<0) printf("%d\r\n", 0);
    return 0;
}