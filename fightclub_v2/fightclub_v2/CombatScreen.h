#pragma once
#include "CardSystem.h"
#include "Team.h"

class CombatScreen
{
public:
	// #### Constructors & Destructor ####
	CombatScreen();

	// #### Getter ####
	const int GetCardCoord() const;
	const int GetNumberCoord() const;
	const bool GetSelectCard() const;
	const bool GetSelectPlayer() const;
	// #### Setter ####
	void SetCardCoord(int x);
	void SetNumberCoord(int x);
	void SetSelectCard(bool b);
	void SetSelectPlayer(bool b);
	// #### Public Methods ####
	void Render(const CardSystem& cardsystem, const Team& team1, const Team& team2, int roundCount);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
protected:
private:
	void RenderNumbers();
	void RenderStats(const Team& team1, const Team& team2);
	void RenderHand(const CardSystem& cardsystem, int roundCount);
	void RenderCardName(const CardSystem& cardsystem, int i);
	void RenderCardDescription(const CardSystem& cardsystem);
	int m_card_coord;
	int m_number_coord;
	bool m_select_player;
	bool m_select_card;
};

