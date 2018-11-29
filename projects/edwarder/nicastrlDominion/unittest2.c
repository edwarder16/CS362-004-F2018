#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int assert(int i, int j)
{
    if(i == j)
    {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    struct gameState state;
    int random;
    int i;
    int j;
    int k;
    int value[3] = {-1, -1, -1};
    for (i = curse; i <= treasure_map; i++) {
        state.supplyCount[i] = -1;
    }

    printf("***************** Test: No Province Cards *************\n");
    state.supplyCount[province] = 0;

    if(assert(isGameOver(&state), 1)) {
        printf("**** Passed ****\n");
        state.supplyCount[province] = -1;
    }
    else {
        printf("***** Failed ****\n");
    }

    printf("\n***************** Test: No Duchy and Estate Cards *************\n");
    state.supplyCount[duchy] = 0;
    state.supplyCount[estate] = 0;

    if(assert(isGameOver(&state), 0)) {
        printf("**** Passed ****\n");
        state.supplyCount[duchy] = -1;
        state.supplyCount[estate] = -1;
    }
    else {
        printf("***** Failed ****\n");
    }

    printf("\n***************** Test: 3 Supply Cards Out *************\n");
    for (i = curse; i <= treasure_map; i++) {
        for(j  = 0; j < 3; j++) {
            random = rand() % (salvager + 1);
            while(random == province) {
                random = rand() % (salvager + 1);
            }
            while(random == value[0] || random == value[1] || random == value[2]) {
                random = rand() % (salvager + 1);

            }
            value[j] = random;
            state.supplyCount[random] = 0;
        }
        printf("**** Supply Piles that are 0 = %d, %d, %d ****** \n", value[0], value[1], value[2]);
        if(assert(isGameOver(&state), 1)) {
            printf("**** Passed ****\n");
            value[0] = -1;
            value[1] = -1;
            value[2] = -1;
        }
        else {
            printf("***** Failed ****\n");
        }
        for (k = curse; k <= treasure_map; k++) {
            if(state.supplyCount[k] == 0) {
                state.supplyCount[k] = 1;
            }
        }
    }
}
