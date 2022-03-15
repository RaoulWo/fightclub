#pragma once
#include "CardSystem.h"

class CombatScreen
{
public:
	// #### Constructors & Destructor ####
	CombatScreen();

	// #### Getter ####
	const int GetCardCoord() const;
	const int GetNumberCoord() const;
	const bool GetActiveSelect() const;
	// #### Setter ####
	void SetCardCoord(int x);
	void SetNumberCoord(int x);
	void SetActiveSelect(bool b);
	// #### Public Methods ####
	void Render(const CardSystem& cardsystem);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
protected:
private:
	void RenderNumbers();

	void RenderHand(const CardSystem& cardsystem);
	void RenderCardName(const CardSystem& cardsystem, int i);
	void RenderCardDescription(const CardSystem& cardsystem);
	int m_card_coord;
	int m_number_coord;
	bool m_active_select;
};

