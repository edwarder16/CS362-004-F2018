#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main () {
    int coinsSkipped;
    int i;
    int test;
    int coinsInHand;
    int testCoinsInHand;
    int numPlayer = 2;
    int randSeed = 100;
    int player1 = 0;
    srand(time(NULL));
    struct gameState game, testGame;
    int k[10] = {adventurer, smithy, village, baron, feast, great_hall, council_room,
                 gardens, mine, remodel};

    printf("**** TESTING SMITHY CARD ****\n");

    initializeGame(numPlayer, k, randSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));
    testGame.hand[player1][testGame.handCount[player1] - 1] = smithy;
    cardEffect(smithy, -1, -1, -1, &testGame, testGame.handCount[player1] - 1, 0);

    printf("**** Test: Hand Count Greater than Control GameState Struct ****\n");
    if(testGame.handCount > game.handCount) {
        printf("**** Passed ****\n");
    }
    else {
        printf("**** Fail ****");
    }

    printf("**** Test: 3 Extra Cards Added to Hand ****\n");
    if(testGame.handCount - game.handCount == 2) {
        printf("**** Passed ****\n");
    }
    else {
        printf("**** Fail ****");
    }


    return 0;

}