#pragma once
#include "Navigation.h"

class SelectionScreen : public Navigation
{
public:
	// #### Constructors & Destructor ####
	SelectionScreen(int x);
	// #### Getter ####
	// #### Setter ####
	// #### Public Methods ####
	void Render(int i, bool mode);
	void MoveLeft();
	void MoveRight();
protected:
private:
	void RenderLeftActive();
	void RenderMiddleActive();
	void RenderRightActive();
	void RenderBottom(int i, bool mode); // true -> singleplayer, false -> multiplayer
};

