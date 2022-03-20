#pragma once
#include "UserInterface.h"
#include "Team.h"

enum Classes {
	undefined = -1, berserker = 0, fighter = 1, guardian = 2
};

class Game
{
public:
	// #### Constructors & Destructor ####
	Game();
	// #### Getter ####
	const bool GetMode() const;
	const int GetRoundCount() const;
	// #### Setter ####
	void SetMode(bool b);
	void SetRoundCount(int i);
	// #### Public Methods ####
	void StartScreen();
	void CharacterSelect();
	void SinglePlayerCombat();
	void Loop();
	void ActivateCard(CardSystem& deck, int i, int& round, Team& team1, Team& team2);
	// #### Public Attributes ####
	UserInterface m_ui;

protected:
private:
	Team m_teams[2];
	Classes m_chosen_classes[4]{ undefined, undefined, undefined, undefined };
	CardSystem m_decks[4];
	bool m_mode;
	int m_round_count;
};

