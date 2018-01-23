#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "player.h"
#include "deck.h"
#include "card.h"
#include "hand.h"
#include "rand.h"

using namespace std;

int main(int argc, char *argv[]) {
    int bankroll;
    bankroll = atoi(argv[1]);

    int minbet;
    minbet = atoi(argv[2]);

    int hands;
    hands = atoi(argv[3]);

    string playerType;
    bool playerSimple = true;
    playerType = argv[4];
    if (playerType == "simple")
        playerSimple = true;
    else if (playerType == "counting")
        playerSimple = false;

    bool shuffleMode = false;
    string fileName = "";
    if (argc == 6) {
        fileName = argv[5];
        shuffleMode = true;
    }

    Hand player_hand;
    Hand dealer_hand;

    Player *player;
    if (playerSimple)
        player = get_Simple();
    else
        player = get_Counting();

    Deck deck;
    cout << "# Shuffling the deck\n";
    int cut, i;
    if (!shuffleMode) {
        for (i = 0; i < 7; i++) {
            cut = get_cut();
            cout << "cut at " << cut << endl;
            deck.shuffle(cut);
            player->shuffled();
        }
    }
    else {
        ifstream inputFile;
        inputFile.open(fileName.c_str());
        while (!inputFile.eof()) {
            inputFile >> cut;
            if (inputFile) {
                cout << "cut at " << cut << endl;
                deck.shuffle(cut);
                player->shuffled();
            }
            else {
                break;
            }
        }
        inputFile.close();
    }

    int wager = minbet;
    int thishand = 1;

    while (bankroll >= minbet && deck.cardsLeft() > 0 && thishand <= hands) {
        cout << "# Hand " << thishand << " bankroll " << bankroll << endl;

        if (deck.cardsLeft() < 20) {
            cout << "# Shuffling the deck\n";
            for (i = 0; i < 7; i++) {
                cut = get_cut();
                cout << "cut at " << cut << endl;
                deck.shuffle(cut);
                player->shuffled();
            }
        }

        wager = player->bet(bankroll, minbet);
        cout << "# Player bets " << wager << endl;

        Card cardA = deck.deal();
        player->expose(cardA);
        player_hand.addCard(cardA);
        cout << "Player dealt " << SpotNames[cardA.spot]
             << " of " << SuitNames[cardA.suit] << endl;
        Card cardB = deck.deal();
        player->expose(cardB);
        dealer_hand.addCard(cardB);
        cout << "Dealer dealt " << SpotNames[cardB.spot]
             << " of " << SuitNames[cardB.suit] << endl;
        Card cardC = deck.deal();
        player->expose(cardC);
        player_hand.addCard(cardC);
        cout << "Player dealt " << SpotNames[cardC.spot]
             << " of " << SuitNames[cardC.suit] << endl;
        Card cardD = deck.deal();
        dealer_hand.addCard(cardD);

        if (player_hand.handValue().count == 21) {
            wager = 3 * wager / 2;
            cout << "# Player dealt natural 21\n";
            bankroll += wager;
        }
        else {
            while (player_hand.handValue().count < 21 && player->draw(cardB, player_hand)) {
                cardC = deck.deal();
                player->expose(cardC);
                player_hand.addCard(cardC);
                cout << "Player dealt " << SpotNames[cardC.spot]
                     << " of " << SuitNames[cardC.suit] << endl;
            }

            cout << "Player's total is " << player_hand.handValue().count << endl;
            if (player_hand.handValue().count > 21) {
                cout << "# Player busts\n";
                bankroll -= wager;
            } else {
                player->expose(cardD);
                cout << "Dealer's hole card is " << SpotNames[cardD.spot]
                     << " of " << SuitNames[cardD.suit] << endl;

                while (dealer_hand.handValue().count < 17) {
                    Card cardE = deck.deal();
                    player->expose(cardE);
                    dealer_hand.addCard(cardE);
                    cout << "Dealer dealt " << SpotNames[cardE.spot]
                         << " of " << SuitNames[cardE.suit] << endl;
                }

                cout << "Dealer's total is " << dealer_hand.handValue().count << endl;

                if (dealer_hand.handValue().count > 21) {
                    cout << "# Dealer busts\n";
                    bankroll += wager;
                }
                else {
                    if (player_hand.handValue().count > dealer_hand.handValue().count) {
                        cout << "# Player wins\n";
                        bankroll += wager;
                    } else if (player_hand.handValue().count < dealer_hand.handValue().count) {
                        cout << "# Dealer wins\n";
                        bankroll -= wager;
                    } else {
                        cout << "# Push\n";
                    }
                }
            }
        }

        thishand++;
        player_hand.discardAll();
        dealer_hand.discardAll();
    }

    cout << "# Player has " << bankroll << " after " << thishand - 1 << " hands\n";

    return 0;
}


