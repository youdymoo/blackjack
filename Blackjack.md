# Blackjack

The implementation of a simplified version of the card game Blackjack, also sometimes called 21. 

It is a relatively simple game played with a standard deck of 52 playing cards. There are two participants, a dealer and a player. The player starts with a bankroll, and the game progresses in rounds called hands.

> **Blackjack**, also known as **twenty-one**, is a comparing [card game](https://en.wikipedia.org/wiki/Card_game) between usually several players and a dealer, where each player in turn competes against the dealer, but players do not play against each other. It is played with one or more [decks](https://en.wikipedia.org/wiki/Playing_card) of 52 cards, and is the most widely played [casino](https://en.wikipedia.org/wiki/Casino_game) banking game in the world.
>
> The objective of the game is to beat the dealer in one of the following ways:
>
> - Get 21 points on the player's first two cards (called a "blackjack" or "[natural](https://en.wikipedia.org/wiki/Natural_(gambling))"), without a dealer blackjack;
> - Reach a final score higher than the dealer without exceeding 21; or
> - Let the dealer draw additional cards until their hand exceeds 21.
>
> (from Wikipedia: Blackjack)

The implementation gives the the Deck ADT, the Hand Interface and the Player Interface (with two different AI players with distinct strategies) and the Driver program. The detailed files are summarized as 

* deck.cpp: the Deck ADT implementation
* hand.cpp: the Hand ADT implementation
* player.cpp: the two player ADT implementations
* blackjack.cpp: the simulation driver



Usage:

1. Compile the file to generate the program ``blackjack``. 

```
g++ -Wall –o blackjack blackjack.cpp card.cpp deck.cpp hand.cpp player.cpp rand.cpp
```

2. Run the program ``blackjack`` with the argument in the format ``<bankroll> <min-bet> <hands> <simple|counting> [<input_file_name>]`` .
3. The program will simulate the game process automatically for you. :)



Have fun with Blackjack! XD