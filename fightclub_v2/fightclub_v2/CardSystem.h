#pragma once
#include "CardStructure.h"

constexpr auto STARTING_HAND_SIZE = 5;
constexpr auto MAX_HAND_SIZE = 7;

class CardSystem
{
public:
	// #### Constructors & Destructor ####
	
	// #### Getter ####
	// #### Setter ####
	// #### Public Methods ####
	void DrawCard();
	void DrawCards(int i);
	void DrawStartingHand();
	void DiscardCard();
	void DiscardHand();
	void Merge();
	void InitializeBerserker();
	void InitializeFighter();
	void InitializeGuardian();
	// #### Public Attributes ####
	CardStructure m_deck;
	CardStructure m_hand;
	CardStructure m_discard_pile;
protected:
private:
};

