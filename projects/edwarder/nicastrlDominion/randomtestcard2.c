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
    int j;
    int m;
    int z;
    int hand, deck, discard;
    int test;
    int numPlayers;
    int randSeed;
    srand(time(NULL));
    struct gameState game, testGame;
    int k[10] = {adventurer, smithy, village, baron, feast, great_hall, council_room,
                 gardens, mine, remodel};

    printf("**** TESTING SMITHY CARD ****\n");

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
            testGame.hand[m][testGame.handCount[m] - 1] = smithy;
            cardEffect(smithy, -1, -1, -1, &testGame, testGame.handCount[m] - 1, 0);

            printf("**** Test: Hand Count Greater than Control GameState Struct ****\n");
            if (testGame.handCount > game.handCount) {
                printf("**** Passed ****\n");
            } else {
                printf("**** Fail ****");
            }

            printf("**** Test: 3 Extra Cards Added to Hand ****\n");
            if (testGame.handCount - game.handCount == 2) {
                printf("**** Passed ****\n");
            } else {
                printf("**** Fail ****");
            }
        }
    }

    return 0;
}