#include "deck.h"

Deck::Deck() {
    reset();
}

void Deck::reset() {
    next = 0;
    int i, j;
    int k = 0;
    for (i = 0; i < SUIT_SIZE; i++)  {
        for (j = 0; j < SPOT_SIZE; j++) {
            deck[k].suit = Suit(i);
            deck[k].spot = Spot(j);
            k++;
        }
    }
}

void Deck::shuffle(int n) {
    Card deckStore[DeckSize];
    int k;
    for (k = 0; k < DeckSize; k++)
        deckStore[k] = deck[k];

    int i, j;
    if (n >=0 && n <= 26){
        for (i = 0; i < n; i++) {
            deck[2 * i] = deckStore[n + i];
            deck[2 * i + 1] = deckStore[i];
        }
        for (j = 2 * n; j < DeckSize; j++){
            deck[j] = deckStore[j];
        }
    }
    else if (n > 26 && n <= 52) {
        for (i = 0; i < DeckSize - n; i++){
            deck[2 * i] = deckStore[n + i];
            deck[2 * i + 1] = deckStore[i];
        }
        for (j = 2 * (DeckSize - n); j < DeckSize; j++){
            deck[j] = deckStore[j - (DeckSize - n)];
        }
    }
    next = 0;
}

Card Deck::deal() {
    if (next < DeckSize) {
        next++;
        return deck[next - 1];
    }
    else
        throw DeckEmpty();
}

int Deck::cardsLeft() {
    return DeckSize - next;
}