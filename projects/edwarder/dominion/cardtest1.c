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

    test = initializeGame(numPlayer, k, randSeed, &game);

    for(i = 0; i < game.deckCount[player1]; i++) {
        if(game.deck[player1][i] == copper) {
            game.deck[player1][i] = gold;
        }
    }

    printf("**** TESTING ADVENTURER CARD ****\n");

    game.deck[player1][0] = copper;
    game.deck[player1][1] = copper;
    game.deck[player1][2] = silver;
    game.deck[player1][3] = copper;

    memcpy(&testGame, &game, sizeof(struct gameState));
    testGame.hand[player1][testGame.handCount[player1] - 1] = adventurer;
    cardEffect(adventurer, -1, -1, -1, &testGame, testGame.handCount[player1] - 1, 0);

    printf("**** Test: Hand count is correct ****\n");
    if(testGame.handCount[player1] == game.handCount[player1] + 2) {
        printf("**** Passed ****\n");
    }
    else{
        printf("**** Failed ****\n");
    }

    printf("**** Test: Cards added are Coins ****\n");
    for(i = 0; i < testGame.handCount[player1]; i++) {
        if(testGame.discard[player1][i] == silver || testGame.discard[player1][i] == gold ||
          testGame.discard[player1][i] == copper) {
            testCoinsInHand += 1;
        }
    }

    for(i = 0; i < game.handCount[player1]; i++) {
        if(game.discard[player1][i] == silver || game.discard[player1][i] == gold ||
           game.discard[player1][i] == copper) {
            coinsInHand += 1;
        }
    }
    if(testCoinsInHand > coinsInHand) {
        printf("**** Passed ****\n");
    }
    else{
        printf("**** Failed ****\n");
    }

    printf("**** Test: Did not skip any coins ****\n");
    for(i = 0; i < testGame.discardCount[player1]; i++) {
        if(testGame.discard[player1][i] == silver || testGame.discard[player1][i] == gold ||
           testGame.discard[player1][i] == copper) {
            coinsSkipped += 1;
        }
    }

    if(coinsSkipped > 0){
        printf("**** Failed ****\n");
    }
    else{
        printf("**** Passed ****\n");
    }

    printf("**** Test: Appropriate amount of cards discarded? ****\n");
    if(testGame.discardCount[player1] == 2) {
        printf("**** Passed ****\n");
    }
    else {
        printf("**** Failed ****\n");
    }

    cardEffect(adventurer, -1, -1, -1, &testGame, testGame.handCount[player1] - 1, 0);

    return 0;
}