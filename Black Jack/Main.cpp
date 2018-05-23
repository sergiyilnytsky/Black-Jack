#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Card.h"
#include "Deck.h"

char getPlayerChoice()
{
	std::cout << "Press (h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackJack(Deck &deck)
{
	int playerTotal = 0;
	int dealerTotal = 0;

	// Dealer gets one card
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer has: " << dealerTotal << '\n';

	// Player gets two cards
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	while (true)
	{
		std::cout << "You have: " << playerTotal << std::endl;
		
		char choice = getPlayerChoice();
		if (choice == 's')
			break;
		playerTotal += deck.dealCard().getCardValue();

		if (playerTotal > 21)
			return false;
	}

	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << std::endl;
	}

	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();
	
	Deck deck;
	deck.shuffleDeck();

	if (playBlackJack(deck))
		std::cout << "YOU WIN!!!\n";
	else
		std::cout << "YOU LOSE!!!\n";

	system("pause");
	return 0;
}