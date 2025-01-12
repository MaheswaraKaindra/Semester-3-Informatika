#include <stdio.h>

int checkNext(int a, int b){
    if ((a % 2) == 0){
        if ((a * 2) > b){
            return 0;
        }
    } else {
        if ((a + 1) > b){
            return 0;
        }
    }
    return 1;
}

void printDeret(int a, int b){
    int tempValue = a;
    while (checkNext(tempValue, b)){
        printf("%d ", tempValue);
        if ((tempValue % 2) == 0){
            tempValue *= 2; 
        } else {
            tempValue += 1;
        }
    }
    printf("%d\n", tempValue);
}

int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printDeret(a, b);
}