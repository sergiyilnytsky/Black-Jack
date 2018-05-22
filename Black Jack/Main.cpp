#include <cstdlib>
#include <ctime>
#include <array>
#include <utility>
#include <iostream>
#include "Card.h"
/*



struct Card
{
	CardSuit suit;
	CardRank rank;
};

void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
	std::cout << std::endl;
}

void swapCards(Card &card1, Card &card2)
{
	std::swap(card1, card2);
}

void shuffleDeck(std::array <Card, 52> &deck)
{
	for (int i = 0; i < 52; ++i)
	{
		int randomCard = rand() % 51;
		swapCards(deck[i], deck[randomCard]);
	}
}

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

bool playBlackJack(const std::array<Card, 52> &deck)
{
	const Card *cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// Dealer gets one card
	dealerTotal += getCardValue(*cardPtr++);
	std::cout << "The dealer has: " << dealerTotal << '\n';

	// Player gets two cards
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	while (true)
	{
		std::cout << "You have: " << playerTotal << std::endl;

		if (playerTotal > 21)
			return false;

		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += getCardValue(*cardPtr++);
	}

	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		std::cout << "The dealer now has: " << dealerTotal << std::endl;
	}

	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}*/

int main()
{
	/*srand(unsigned int(time(0)));
	rand();

	std::array<Card, 52> deck;

	int card = 0;
	for (int suit = 0; suit < MAX_SUITS; ++suit)
	{
		for (int rank = 0; rank < MAX_RANKS; ++rank)
		{
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			++card;
		}
	}

	shuffleDeck(deck);
	
	if (playBlackJack(deck))
		std::cout << "YOU WIN!!!\n";
	else
		std::cout << "YOU LOSE!!!\n";*/
	
	const Card cardQueenHearts(Card::Rank_Queen, Card::Heart);
	cardQueenHearts.printCard();
	std::cout << " has the value " << cardQueenHearts.getCardValue() << '\n';

	system("pause");
	return 0;
}