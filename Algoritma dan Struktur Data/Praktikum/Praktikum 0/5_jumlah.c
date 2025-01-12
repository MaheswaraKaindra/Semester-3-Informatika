#include <stdio.h>

int hitungJumlah(int n, int k){
    int resultValue = 0;
    int tempValue;
    int loopIndex;
    for (loopIndex = 0; loopIndex < n; ++loopIndex){
        scanf("%d", &tempValue);
        if ((tempValue % k) != 0){
            resultValue += tempValue;
        }
    }
    return resultValue;
}

int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int resultValue = hitungJumlah(n, k);
    printf("%d\n", resultValue);
}