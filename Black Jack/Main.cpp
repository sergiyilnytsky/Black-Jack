#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <utility>

enum CardSuit	// масти для карт
{
	Club,		//трефы
	Diamond,	//бубны
	Heart,		//червы
	Peak,		//пики
	MAX_SUITS	//количество перечислений
};

enum CardRank	//достоинства карт
{
	Rank_2,
	Rank_3,
	Rank_4,
	Rank_5,
	Rank_6,
	Rank_7,
	Rank_8,
	Rank_9,
	Rank_10,
	Rank_Jack,		//Валет
	Rank_Queen,		//Дама
	Rank_King,		//Король
	Rank_Ace,		//Туз
	MAX_RANKS
};

struct Card
{
	CardSuit suit;
	CardRank rank;
};

void printCard(const Card &card)	//Вывод карты на консоль
{
	switch (card.rank)
	{
		case Rank_2:		std::cout << "2"; break;
		case Rank_3:		std::cout << "3"; break;
		case Rank_4:		std::cout << "4"; break;
		case Rank_5:		std::cout << "5"; break;
		case Rank_6:		std::cout << "6"; break;
		case Rank_7:		std::cout << "7"; break;
		case Rank_8:		std::cout << "8"; break;
		case Rank_9:		std::cout << "9"; break;
		case Rank_10:		std::cout << "10"; break;
		case Rank_Jack:		std::cout << "J"; break;
		case Rank_Queen:	std::cout << "Q"; break;
		case Rank_King:		std::cout << "K"; break;
		case Rank_Ace:		std::cout << "A"; break;
	}

	switch (card.suit)
	{
		case Club:		std::cout << static_cast<char>(5); break;
		case Diamond:	std::cout << static_cast<char>(4); break;
		case Heart:		std::cout << static_cast<char>(3); break;
		case Peak:		std::cout << static_cast<char>(6); break;
	}
}

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

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
		case Rank_2: return 2;
		case Rank_3: return 3;
		case Rank_4: return 4;
		case Rank_5: return 5;
		case Rank_6: return 6;
		case Rank_7: return 7;
		case Rank_8: return 8;
		case Rank_9: return 9;
		case Rank_10: return 10;
		case Rank_Jack: return 10;
		case Rank_Queen: return 10;
		case Rank_King: return 10;
		case Rank_Ace: return 11;
	}

	return 0;
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
}

int main()
{
	srand(unsigned int(time(0)));
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
		std::cout << "YOU LOSE!!!\n";
	
	system("pause");
	return 0;
}