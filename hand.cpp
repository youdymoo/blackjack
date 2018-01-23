#include "hand.h"

Hand::Hand() {
    discardAll();
}

void Hand::discardAll() {
    curValue.count = 0;
    curValue.soft = false;
}

void Hand::addCard(Card c) {
    int countCard;
    if (c.spot != ACE) {
        if (c.spot <= NINE) {
            countCard = c.spot + 2;
            curValue.count += countCard;
        }
        else if (c.spot >= TEN && c.spot <= KING) {
            countCard = 10;
            curValue.count += countCard;
        }

        if (curValue.count > 21 && curValue.soft) {
            curValue.count -= 10;
            curValue.soft = false;
        }
        return;
    }
    else  {
        countCard = 11;
        curValue.count += countCard;
        if (curValue.count > 21) {
            if (curValue.soft) {
                curValue.count -= 10;
                return;
            }
            else {
                curValue.count -= 10;
                curValue.soft = false;
                return;
            }
        }
        else {
            curValue.soft = true;
            return;
        }
    }
}

HandValue Hand::handValue() const {
    return curValue;
}