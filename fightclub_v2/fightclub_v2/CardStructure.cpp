#include "CardStructure.h"
#include <iostream>
#include <cassert>
#include <algorithm> // algorithm, random for Shuffle()
#include <random>

auto rng = std::default_random_engine{}; // for Shuffle() method

CardStructure::CardStructure()
	: m_size(0)
{
#ifdef _DEBUG
	std::cout << "CardStructure was created" << '\n';
#endif
}

CardStructure::~CardStructure()
{
#ifdef _DEBUG
	std::cout << "CardStructure was created" << '\n';
#endif
}

const int CardStructure::GetSize() const
{
	return this->m_size;
}

const Card& CardStructure::GetCard(int index) const
{
	assert(0 <= index && index < this->GetSize()); 
	return this->m_cards.at(index);
}

void CardStructure::SetSize(int size)
{
	this->m_size = size;
	if (this->GetSize() < 0)
		this->m_size = 0;
}

void CardStructure::SetCard(const Card& card, int index)
{
	assert(0 <= index && index < this->GetSize());
	this->m_cards.at(index) = card;
}

void CardStructure::PushCard(const Card& card)
{
	this->m_cards.push_back(card);
	this->SetSize(this->GetSize() + 1);
}

void CardStructure::PopCard()
{
	assert(this->GetSize() > 0);

	this->m_cards.pop_back();
	this->SetSize(this->GetSize() - 1);
}

void CardStructure::DiscardCardTo(CardStructure& other)
{
	assert(this->GetSize() != 0);
	Card tmp = this->m_cards.back();
	this->PopCard();
	other.PushCard(tmp);
}

void CardStructure::Shuffle()
{
	std::shuffle(std::begin(this->m_cards), std::end(this->m_cards), rng);
}

std::ostream& operator<<(std::ostream& os, const CardStructure& cards)
{
	if (cards.GetSize() == 0) {
		os << "CardStructure is empty" << '\n';
	}
	else {
		for (int i = 0; i < cards.GetSize(); ++i) {
			os << cards.GetCard(i);
		}
		os << '\n';
	}
	return os;
}



