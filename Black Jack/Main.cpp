#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

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

int main()
{
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

	system("pause");
	return 0;
}