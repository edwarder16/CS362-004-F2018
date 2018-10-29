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

    printf("**** TESTING VILLAGE CARD ****\n");

    initializeGame(numPlayer, k, randSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));
    testGame.hand[player1][testGame.handCount[player1] - 1] = village;
    cardEffect(village, -1, -1, -1, &testGame, testGame.handCount[player1] - 1, 0);

    printf("**** Test: 2 additional actions ****\n");
    if((testGame.numActions - game.numActions) == 2) {
        printf("**** Pass ****\n");
    }
    else {
        printf("**** Fail ****\n");
    }

    printf("**** Test: 1 additional card received ****\n");
    if(testGame.handCount[player1] == game.handCount[player1]) {
        printf("**** Pass ****\n");
    }
    else {
        printf("**** Fail ****\n");
    }

    printf("**** Test: 1 card discarded****\n");
    if(testGame.playedCardCount == 1) {
        printf("**** Pass ****\n");
    }
    else {
        printf("**** Fail ****\n");
    }

    return 0;
}
