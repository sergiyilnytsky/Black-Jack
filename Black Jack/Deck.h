#pragma once

#include "Card.h"
#include <array>

class Deck
{
private:
	std::array <Card, 52> m_deck;
	int m_cardIndex = 0;
	static void swapCards(Card &card1, Card &card2);
public:
	Deck();
	void printDeck() const;
	void shuffleDeck();
	const Card& dealCard();
};