#pragma once
#include "TitleScreen.h"
#include "SelectionScreen.h"
#include "CombatScreen.h"

class UserInterface
{
public:
	// #### Constructors & Destructor ####
	UserInterface();
	// #### Getter ####
	// #### Setter ####
	// #### Public Methods ####
	// #### Public Attributes ####
	TitleScreen m_title_screen;
	SelectionScreen m_selection_screen;
	CombatScreen m_combat_screen;
protected:
private:
};

