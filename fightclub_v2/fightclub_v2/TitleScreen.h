#pragma once
#include "Navigation.h"

class TitleScreen : public Navigation
{
public:
	// #### Constructors & Destructor ####
	TitleScreen(int x);
	// #### Getter ####
	// #### Setter ####
	// #### Public Methods ####
	void Render();
	void MoveLeft();
	void MoveRight();
protected:
private:
};

