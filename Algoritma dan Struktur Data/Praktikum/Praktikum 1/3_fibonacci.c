#include <stdio.h>

int fibonacci(int n, int a, int b){
    int loopIndex = 0;
    int tempValue1 = a, tempValue2 = b;
    int fibonacciResult = 0;
    while (loopIndex < (n - 2)){
        fibonacciResult = tempValue1 + tempValue2;
        tempValue1 = tempValue2;
        tempValue2 = fibonacciResult;
        loopIndex++;
    }
    return fibonacciResult;
}

int main(){
    int n, a, b;
    int outputResult;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    outputResult = fibonacci(n, a, b);
    printf("%d\n", outputResult);
}