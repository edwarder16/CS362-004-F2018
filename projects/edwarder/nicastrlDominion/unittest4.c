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
    struct gameState state;
    int buys;
    int coins;
    int i;
    int supply;
    int cost[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

    for (i = curse; i <= treasure_map; i++) {
        state.supplyCount[i] = 1;
    }

    printf("\n**** Testing: Buy Card with 0 Buys *****\n");
    coins = 10;
    state.coins = coins;
    state.numBuys = 0;
    buys = 0;
    if (assert(buyCard(buys, &state), -1)) {
        printf("**** Passed ****\n");
        printf("**** Testing: Buys not Decremented *****\n");
        if (assert(state.numBuys, buys)) {
            printf("**** Passed ****\n");
            printf("**** Testing: Supply not Decremented *****\n");
            if (assert(state.supplyCount[0], 1)) {
                printf("**** Passed ****\n");
                printf("**** Testing: Coins Decremented Properly *****\n");
                if(assert(state.coins, coins)) {
                    printf("**** Passed ****\n");
                }
                else {
                    printf("**** Failed ****\n");
                }
            }
            else {
                printf("**** Failed ****\n");
            }
        }
        else {
            printf("\n**** Failed ****\n");
        }
    }
    else {
        printf("\n**** Failed ****\n");
    }



    printf("\n**** Testing: Buy Card with -1 Buys *****\n");
    coins = 10;
    state.coins = coins;
    state.numBuys = -1;
    buys = -1;

    printf("**** Testing: Function Failed or Succeeded Appropriately *****\n");
    if (assert(buyCard(0, &state), -1)) {
        printf("**** Passed ****\n");
        printf("**** Testing: Buys not Decremented *****\n");
        if (assert(state.numBuys, buys)) {
            printf("**** Passed ****\n");
            printf("**** Testing: Supply not Decremented *****\n");
            if (assert(state.supplyCount[i], 0)) {
                printf("**** Passed ****\n");
                printf("**** Testing: Coins Decremented Properly *****\n");
                if(assert(state.coins, coins)) {
                    printf("**** Passed ****\n");
                }
                else {
                    printf("**** Failed ****\n");
                }
            }
            else {
                printf("**** Failed ****\n");
            }
        }
        else {
            printf("**** Failed ****\n");
        }
    }
    else {
        printf("**** Failed ****\n");
    }

    printf("\n**** Testing: Supply of 0 Buys 1 *****\n");
    for (i = curse; i <= treasure_map; i++) {
        coins = 10;
        state.coins = coins;
        buys = 1;
        state.numBuys = buys;
        state.supplyCount[i] = 0;
        printf("**** Testing: Function Failed or Succeeded Appropriately *****\n");
        if(assert(buyCard(i, &state), -1)) {
            printf("**** Testing: Buys not Decremented *****\n");
            if(assert(state.numBuys, buys)) {
                printf("**** Testing: Supply not Decremented *****\n");
                if(assert(state.supplyCount[i], 0)) {
                    printf("**** Passed ****\n");
                    printf("**** Testing: Coins Decremented Properly *****\n");
                    if(assert(state.coins, coins)) {
                        printf("**** Passed ****\n");
                    }
                    else {
                        printf("**** Failed ****\n");
                    }
                }
                else {
                        printf("**** Failed ****\n");
                }
            }
            else {
                printf("**** Failed ****\n");
            }
        }
        else {
            printf("**** Failed ****\n");
        }
    }

    for (i = curse; i <= treasure_map; i++) {
        coins = rand() % (5) + 10;
        state.coins = coins;
        buys = rand() % (5) + 1;
        state.numBuys = buys;
        supply = rand() % (5) + 1;
        state.supplyCount[i] = supply;
        printf("**** Testing: Function Failed or Succeeded Appropriately *****\n");
        if(assert(buyCard(i, &state), 0)) {
            printf("**** Passed ****\n");
            printf("**** Testing: Buys Decremented *****\n");
            if(assert(state.numBuys, buys -= 1)) {
                printf("**** Testing: Supply Decremented *****\n");
                if(assert(state.supplyCount[i], supply -= 1)) {
                    printf("**** Passed ****\n");
                    printf("**** Testing: Coins Decremented Properly *****\n");
                    if(assert(state.coins, coins -= cost[i])) {
                        printf("**** Passed ****\n");
                    }
                    else {
                        printf("**** Failed ****\n");
                    }
                }
                else {
                    printf("**** Failed ****\n");
                }
            }
            else {
                printf("**** Failed ****\n");
            }
        }
        else {
            printf("\n**** Failed ****\n");
        }
    }
}