#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assert(int i, int j)
{
    if(i == j)
    {
        return 1;
    }
    return 0;
}

int main ()
{
    printf("************** Testing Game Cost ******************\n");
    struct gameState s;
    int i;
    int cost[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

    for (i = curse; i <= salvager; i++) {
        if(assert(getCost(i), cost[i])) {
            printf("     Test Passed\n");
        }
        else {
            printf("     Test Failed\n");
        }
    }
}