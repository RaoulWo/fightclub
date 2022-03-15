#pragma once
#include "Card.h"
#include <vector>

class CardStructure
{
public:
	// #### Constructors & Destructor ####
	CardStructure();
	~CardStructure();
	// #### Getter ####
	const int GetSize() const;
	const Card& GetCard(int index) const;
	// #### Setter ####
	void SetSize(int size);
	void SetCard(const Card& card, int index);

	// #### Public Methods ####
	void PushCard(const Card& card);
	void PopCard();
	void DiscardCardTo(CardStructure& other);
	void Shuffle();

	// #### Overloaded Operators ####
	friend std::ostream& operator<<(std::ostream& os, const CardStructure& cards);
protected:
	int m_size;
	std::vector<Card> m_cards;
private:
};

