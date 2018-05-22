#include "Card.h"
#include <iostream>

Card::Card(Card::CardRank rank = Card::MAX_RANKS, Card::CardSuit suit = Card::MAX_SUITS) : m_rank(rank), m_suit(suit)
{

}

void Card::printCard() const//Вывод карты на консоль
{
	switch (this->m_rank)
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

	switch (this->m_suit)
	{
	case Club:		std::cout << static_cast<char>(5); break;
	case Diamond:	std::cout << static_cast<char>(4); break;
	case Heart:		std::cout << static_cast<char>(3); break;
	case Peak:		std::cout << static_cast<char>(6); break;
	}
}

int Card::getCardValue() const
{
	switch (this->m_rank)
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

