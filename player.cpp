#include "player.h"

class SimplePlayer : public Player {
public:
    SimplePlayer() {}

    int bet(unsigned int bankroll, unsigned int minimum) {
        if (minimum <= bankroll)
            return minimum;
        else
            return bankroll;
    }

    bool draw(Card dealer, const Hand &player) {
        if (!player.handValue().soft) {
            if (player.handValue().count <= 11)
                return true;
            else if (player.handValue().count == 12) {
                if (dealer.spot >= FOUR && dealer.spot <= SIX)
                    return false;
                else
                    return true;
            }
            else if (player.handValue().count >= 13 && player.handValue().count <= 16) {
                if (dealer.spot >= TWO && dealer.spot <= SIX)
                    return false;
                else
                    return true;
            }
            else if (player.handValue().count >= 17)
                return false;
        }
        else {
            if (player.handValue().count <= 17)
                return true;
            else if (player.handValue().count == 18) {
                if (dealer.spot == TWO || dealer.spot == SEVEN || dealer.spot == EIGHT)
                    return false;
                else
                    return true;
            }
            else if (player.handValue().count >= 19)
                return false;
        }
    }

    void expose(Card c) {
        return;
    }

    void shuffled() {
        return;
    }

};

class CountingPlayer : public Player {
private:
    int count;

public:
    CountingPlayer() : count(0){}

    int bet(unsigned int bankroll, unsigned int minimum) {
        if (count >= 2) {
            if (2 * minimum <= bankroll)
                return 2 * minimum;
            else
                return minimum;
        }
        else
            return minimum;
    }

    bool draw(Card dealer, const Hand &player) {
        if (!player.handValue().soft) {
            if (player.handValue().count <= 11)
                return true;
            else if (player.handValue().count == 12) {
                if (dealer.spot == FOUR || dealer.spot == FIVE || dealer.spot == SIX)
                    return false;
                else
                    return true;
            }
            else if (player.handValue().count >= 13 && player.handValue().count <= 16) {
                if (dealer.spot >= TWO && dealer.spot <= SIX)
                    return false;
                else
                    return true;
            }
            else if (player.handValue().count >= 17)
                return false;
        }
        else {
            if (player.handValue().count <= 17)
                return true;
            else if (player.handValue().count == 18) {
                if (dealer.spot == TWO || dealer.spot == SEVEN || dealer.spot == EIGHT)
                    return false;
                else
                    return true;
            }
            else if (player.handValue().count >= 19)
                return false;
        }
    }

    void expose(Card c){
        if (c.spot >= TEN && c.spot <= ACE)
            count -= 1;
        else if (c.spot >= TWO && c.spot <= SIX)
            count += 1;
    }

    void shuffled() {
        count = 0;
    }

};

static SimplePlayer simplePlayer;
extern Player *get_Simple(){
    return &simplePlayer;
}

static CountingPlayer countingPlayer;
extern Player *get_Counting(){
    return &countingPlayer;
}