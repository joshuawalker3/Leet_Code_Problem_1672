#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max = 0;

    for (int i = 0; i < accountsSize; i++) {
        int sum = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            sum += accounts[i][j];
        }

        if (sum > max) { max = sum; }
    }

    return max;
}

int main() {
    int** accountsPtr = (int**)malloc(2 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        accountsPtr[i] = (int*)malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; i++) {
        accountsPtr[0][i] = i + 1;
    }

    for (int i = 0; i < 3; i++) {
        accountsPtr[1][i] = 3 - i;
    }

    int accountsSize = 3;
    int accountsColSize = 3;
    int* accountsColSizePtr = &accountsColSize;

    int max = maximumWealth(accountsPtr, accountsSize, accountsColSizePtr);

    printf("%d", max);

}
