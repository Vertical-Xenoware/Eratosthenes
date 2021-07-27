#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Eratosthenes(int *userInput) {

    int *numArray = calloc(sizeof(int), *userInput + 5);
    int element = 0;
    int seeds = 0;
    int value;
    int eliminator = 0;
    int primeSeed = 0;
    int *expiredSeeds = calloc(sizeof(int), 10000);
    int maxLocation = 0;
    int maxPrimeLocation = 0;
    


    for(element = 0, value = 1; element < *userInput; element++, value++) {
        numArray[element] = value;
    }

    for(element = 0; element < *userInput; element++) {
        if(numArray[element] == 1)
            numArray[element] = 0;        
    }

    for(eliminator = 0; eliminator < *userInput; eliminator++) {
        for(element = 0, value = 0; element < *userInput; element++) {
           reSeed:
           if(numArray[element] != 0 && numArray[element] != primeSeed) {
                primeSeed = numArray[element];     
            } else 
            {
                element++;
                goto reSeed;
            }
           for(seeds = 0; seeds <= 500; seeds++) {
                if(expiredSeeds[seeds] == primeSeed) {
                    element++;
                    goto reSeed;
                } 
            }
            goto Eratosthenes;             
        }
        Eratosthenes:

        for(element = 0; element < *userInput; element++){
            if(numArray[element] == 0) {
                continue;
            }
            if(numArray[element] == primeSeed) {
                continue;
            }
            if(numArray[element] % primeSeed == 0) { //|| numArray[element] >= primeSeed * primeSeed) {
                numArray[element] = 0;
            }
        }


        expiredSeeds[eliminator] = primeSeed;
        for(element = 0; element <= *userInput; element++) {
            if(numArray[element] > numArray[maxLocation]) {
                maxLocation = element;
            }
        }
        for(element = 0; element <= *userInput; element++) {
            if(expiredSeeds[element] > expiredSeeds[maxPrimeLocation]) {
                maxPrimeLocation = element;
            }
        }        
        if(expiredSeeds[maxPrimeLocation] == numArray[maxLocation]) {
            goto terminateEliminator;
        }
    }
    
    terminateEliminator:
    free(expiredSeeds);
    
    for(element = 0; element < *userInput; element++) {
        if(numArray[element] != 0) {
            printf("%d is a prime\n", numArray[element]);
        }
    }

    free(numArray);

}

int main() {

    int *primeInput = malloc(sizeof(int));
    printf("Please enter a value that will serve as the high limit.\n");
    scanf("%d", primeInput);

    Eratosthenes(primeInput); 
    free(primeInput);

    return 0;
}