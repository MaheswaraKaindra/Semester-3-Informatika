#include <stdio.h>

void printTriangle(int numberOfRows){
    int rowIndex, colIndex, spaceIndex, starIndex;
    int maxSpace = 0;
    int maxStars = (2 * numberOfRows) - 1;
    for (rowIndex = 0; rowIndex < numberOfRows; ++rowIndex){
        for (spaceIndex = 0; spaceIndex < maxSpace; ++spaceIndex){
            printf(" ");
        }
        for (starIndex = 0; starIndex < maxStars; ++starIndex){
            printf("*");
        }
        printf("\n");
        maxSpace++;
        maxStars -= 2;
    }
}

int main(){
    int numberOfRows;
    scanf("%d", &numberOfRows);
    printTriangle(numberOfRows);
}