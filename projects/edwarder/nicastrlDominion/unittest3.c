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
    int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
                  sea_hag, tribute, smithy };
    srand(time(NULL));
    int randNum = 0;
    int player;
    int i;
    int j;
    int coins;
    int cop = 0, sil = 0, gol = 0;
    initializeGame(4, k, 100, &state);

    printf("\n**** Testing Update Coins ****\n");
    for(player = 0; player < 4; player++) {
        state.handCount[player] = 0;
        coins = 0;
        state.coins = 0;
        for(i = 0; i < MAX_HAND; i++) {
            randNum = rand() % (3);
            state.handCount[player] += 1;
            if(randNum == 0) {
                state.hand[player][i] = copper;
                updateCoins(player, &state, 0);
                coins += 1;
            }
            else if(randNum == 1) {
                state.hand[player][i] = silver;
                updateCoins(player, &state, 0);
                coins += 2;
            }
            else {
                state.hand[player][i] = gold;
                updateCoins(player, &state, 0);
                coins += 3;
            }
        }
        if(assert(state.coins, coins)) {
            printf("\n**** Passed ****\n");
        }
        else {
            printf("\n**** Failed ****\n");
        }
    }

    printf("\n**** Testing If All Coins Are Same ****\n");
    for(player = 0; player < 4; player++) {
        for(j = 0; j < 3; j++) {
            state.handCount[player] = 0;
            coins = 0;
            state.coins = 0;
            for (i = 0; i < MAX_HAND; i++) {
                state.handCount[player] += 1;
                if(j == 0) {
                    state.hand[player][i] = copper;
                    updateCoins(player, &state, 0);
                    coins += 1;
                }
                else if(j == 1) {
                    state.hand[player][i] = silver;
                    updateCoins(player, &state, 0);
                    coins += 2;
                }
                else{
                    state.hand[player][i] = gold;
                    updateCoins(player, &state, 0);
                    coins += 3;
                }
            }
            if(assert(state.coins, coins)) {
                printf("\n**** Passed ****\n");
            }
            else {
                printf("\n**** Failed ****\n");
            }
        }

    }
}