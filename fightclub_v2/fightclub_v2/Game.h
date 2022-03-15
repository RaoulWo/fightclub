#pragma once
#include "UserInterface.h"

class Game
{
public:
	// #### Constructors & Destructor ####
	Game();
	// #### Getter ####
	const bool GetMode() const;
	// #### Setter ####
	void SetMode(bool b);
	// #### Public Methods ####
	void Start();
	// #### Public Attributes ####
	UserInterface m_ui;
protected:
private:
	bool m_mode;
};

