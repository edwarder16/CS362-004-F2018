#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TESTS 1000

int main () {
    srand(time(NULL));
    int coinsSkipped = 0;
    int i;
    int j;
    int m;
    int z;
    int hand, deck, discard;
    int test;
    int coinsInHand = 0;
    int testCoinsInHand = 0;
    int numPlayers;
    int randSeed;
    srand(time(NULL));
    struct gameState game, testGame;
    int k[10] = {adventurer, smithy, village, baron, feast, great_hall, council_room,
                 gardens, mine, remodel};

    printf("**** TESTING ADVENTURER CARD ****\n");

    for(z = 0; z < TESTS; z++)
    {

        randSeed = rand() % 100 + 1;
        numPlayers = rand() % 4 + 1;

        test = initializeGame(numPlayers, k, randSeed, &game);
        for(j = 0; j < numPlayers; j++) {
            hand = rand() % MAX_HAND;
            game.handCount[j] = hand;
            deck = rand() % (MAX_DECK - hand);
            game.deckCount[j] = deck;
            discard = rand() % (MAX_DECK - deck);
            game.discardCount[j] = discard;
        }

        for(m = 0; m < numPlayers; m++) {
            for (j = 0; j <game.discardCount[m]; j++)
            {
                game.discard[m][j] = rand() % 25;
            }
            for (j = 0; j < game.deckCount[m]; j++)
            {
                game.deck[m][j] = rand() % 25;
            }
            for (j = 0; j < game.handCount[m]; j++)
            {
                game.hand[m][j] = rand() % 25;
            }
        }
        memcpy(&testGame, &game, sizeof(struct gameState));
        for(m = 0; m < numPlayers; m++) {
            testGame.hand[m][testGame.handCount[m] - 1] = adventurer;
            cardEffect(adventurer, -1, -1, -1, &testGame, testGame.handCount[m] - 1, 0);

            printf("**** Test: Hand count is correct ****\n");
            if(testGame.handCount[m] == game.handCount[m] + 2) {
                printf("**** Passed ****\n");
            }
            else{
                printf("**** Failed ****\n");
            }

            printf("**** Test: Cards added are Coins ****\n");
            for(i = 0; i < testGame.handCount[m]; i++) {
                if(testGame.discard[m][i] == silver || testGame.discard[m][i] == gold ||
                   testGame.discard[m][i] == copper) {
                    testCoinsInHand += 1;
                }
            }

            for(i = 0; i < game.handCount[m]; i++) {
                if(game.discard[m][i] == silver || game.discard[m][i] == gold ||
                   game.discard[m][i] == copper) {
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
            for(i = 0; i < testGame.discardCount[m]; i++) {
                if(testGame.discard[m][i] == silver || testGame.discard[m][i] == gold ||
                   testGame.discard[m][i] == copper) {
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
            if(testGame.discardCount[m] == 2) {
                printf("**** Passed ****\n");
            }
            else {
                printf("**** Failed ****\n");
            }
        }
    }
    return 0;
}