#pragma once
#include "UserInterface.h"
#include "Team.h"

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
	void Start();
	// #### Public Attributes ####
	UserInterface m_ui;
protected:
private:
	bool m_mode;
	int m_round_count;
};

