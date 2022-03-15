#pragma once
#include "CardSystem.h"

class CombatScreen
{
public:
	// #### Constructors & Destructor ####
	CombatScreen();

	// #### Getter ####
	const int GetCardCoord() const;
	// #### Setter ####
	void SetCardCoord(int x);
	// #### Public Methods ####
	void Render(const CardSystem& cardsystem);
	void MoveUp();
	void MoveDown();
protected:
private:
	void RenderHand(const CardSystem& cardsystem);
	void RenderCard(const CardSystem& cardsystem, int i);
	int m_card_coord;
};

