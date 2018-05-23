#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <cassert>

Deck::Deck()
{
	int card = 0;

	for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
	{
		for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
		{
			m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
			++card;
		}
	}
}

void Deck::swapCards(Card &card1, Card &card2)
{
	std::swap(card1, card2);
}

void Deck::printDeck() const
{
	
	for (const auto &card : m_deck)
	{
		card.printCard();
		std::cout << " ";
	}
	std::cout << std::endl;
}

void Deck::shuffleDeck()
{
	for (int i = 0; i < 52; ++i)
	{
		int randomCard = rand() % 51;
		swapCards(m_deck[i], m_deck[randomCard]);
	}
}

const Card& Deck::dealCard() 
{
	assert(m_cardIndex < 52);
	return m_deck[m_cardIndex++];
}
