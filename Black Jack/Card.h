#pragma once

class Card
{
public:
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

private:
	CardRank m_rank;
	CardSuit m_suit;

public:
	Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS);

	void printCard() const;

	int getCardValue() const;

};
