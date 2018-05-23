#pragma once

class Card
{
public:
	enum CardSuit	// ����� ��� ����
	{
		Club,		//�����
		Diamond,	//�����
		Heart,		//�����
		Peak,		//����
		MAX_SUITS	//���������� ������������
	};

	enum CardRank	//����������� ����
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
		Rank_Jack,		//�����
		Rank_Queen,		//����
		Rank_King,		//������
		Rank_Ace,		//���
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
