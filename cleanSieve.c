#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sieve(int *highLimit) {

    variableAndMemoryAllocation:
    int *dirtyArr = calloc(sizeof(int), *highLimit + 5);
    memset(dirtyArr, 999999999, (*highLimit + 5) * sizeof(int));
    int dArrElement;
    int arrVal;
    int primeSeed = 0;
    int *expiredSeeds = calloc(sizeof(int), 100000);
    memset(expiredSeeds, 999999999, 100000 * sizeof(int));
    int expSElement;
    int elimination = 0;
    int max = 0;
    int primeMax = 0;    

    arrayPopulator:
    for(dArrElement = 0, arrVal = 1; dArrElement < *highLimit; dArrElement++, arrVal++) {
        dirtyArr[dArrElement] = arrVal;
    }

    specialEliminator:
    for(dArrElement = 0; dArrElement < *highLimit; dArrElement++) {
        if(dirtyArr[dArrElement] == 1) {
            dirtyArr[dArrElement] = 0;
        } 
    }

    mainEliminator:
    while(true) {
        primeSeeder:
        for(dArrElement = 0; dArrElement < *highLimit; dArrElement++) {
            reSeed:
            if(dirtyArr[dArrElement] == 0 || dirtyArr[dArrElement] == primeSeed) {
                dArrElement++;
                goto reSeed;    
            } else
            {
                primeSeed = dirtyArr[dArrElement];
                goto seedCheck;
            }
        }

        seedCheck:
        for(expSElement = 0; expSElement < *highLimit; expSElement++) {
            if(expiredSeeds[expSElement] == primeSeed) {
                goto reSeed;
            }
        }

        sieve:
        for(dArrElement = 0; dArrElement < *highLimit; dArrElement++) {
            if(dirtyArr[dArrElement] == primeSeed) {
                continue;
            }
            if(dirtyArr[dArrElement] % primeSeed == 0) {
                dirtyArr[dArrElement] = 0;
            }
        }

        seedStorage:
        expiredSeeds[elimination] = primeSeed;
        elimination++;

        maxComparison:
        for(dArrElement = 0; dArrElement < *highLimit; dArrElement++) {
            if(dirtyArr[dArrElement] > dirtyArr[max]) {
                max = dArrElement;
            }
        }

        for(expSElement = 0; expSElement < *highLimit; expSElement++) {
            if(expiredSeeds[expSElement] > expiredSeeds[primeMax]) {
                primeMax = expSElement;
            }
        }

        if(dirtyArr[max] == expiredSeeds[primeMax]) {
            goto printPrime;
        } 
    }

    printPrime:

    for(expSElement = 0; true; expSElement++) {
        if(expiredSeeds[expSElement] != -1) {
            printf("%d\n", expiredSeeds[expSElement]);
        }
        if(expiredSeeds[expSElement] == -1) {
            goto endSieve;
        }
    }

    endSieve:



}

int main() {
    
    int *input = calloc(sizeof(int), 1);
    *input = 500;
    sieve(input);
    
    return 0;
}