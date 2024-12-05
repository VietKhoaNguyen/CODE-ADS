#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Complete this given function void findMax(int *max, int a), which assigns a value a to max if a > max.s
void findMax(int *max,int a){
    if (a > *max){
        *max = a;
    }
}
int main(){
    int max = 10;
    int a = 20;
    printf("The previous value:\n%d\n", max);
    findMax(&max,a);
    printf("The following value:\n%d", max);
    return 0;
}