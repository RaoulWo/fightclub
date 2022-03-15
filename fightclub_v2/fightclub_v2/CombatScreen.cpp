#include "CombatScreen.h"
#include <iostream>
#include <Windows.h>

CombatScreen::CombatScreen()
	: m_card_coord(0)
{
}

const int CombatScreen::GetCardCoord() const
{
	return this->m_card_coord;
}

void CombatScreen::SetCardCoord(int x)
{
	this->m_card_coord = x;
	if (this->GetCardCoord() < 0)
		this->m_card_coord = 6;
	if (this->GetCardCoord() > 6)
		this->m_card_coord = 0;
}

void CombatScreen::Render(const CardSystem& cardsystem)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//cout << "x                                                          xx                                                       x" << '\n';
	cout << "#######################################################################################################################" << '\n'; // 1
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n'; // 5
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n'; // 10
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	this->RenderHand(cardsystem);
}

void CombatScreen::MoveUp()
{
	this->SetCardCoord(this->GetCardCoord() - 1);
}

void CombatScreen::MoveDown()
{
	this->SetCardCoord(this->GetCardCoord() + 1);
}

void CombatScreen::RenderHand(const CardSystem& cardsystem)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "#=====================================================================================================================#" << '\n';
	cout << "#                        |                                                                                            #" << '\n';
	cout << "# "; this->RenderCard(cardsystem, 0); cout << " |                                                                                            #" << '\n';
	cout << "# "; this->RenderCard(cardsystem, 1); cout << " |                                                                                            #" << '\n';
	cout << "# "; this->RenderCard(cardsystem, 2); cout << " |                                                                                            #" << '\n';
	cout << "# "; this->RenderCard(cardsystem, 3); cout << " |                                                                                            #" << '\n'; // 15
	cout << "# "; this->RenderCard(cardsystem, 4); cout << " |                                                                                            #" << '\n';
	cout << "# "; this->RenderCard(cardsystem, 5); cout << " |                                                                                            #" << '\n'; // 25
	cout << "# "; this->RenderCard(cardsystem, 6); cout << " |                                                                                            #" << '\n';
	cout << "#                        |                                                                                            #" << '\n';
	cout << "#######################################################################################################################" << '\n'; // 28 * 120
	//cout << "x                                                          xx                                                       x" << '\n';
}

void CombatScreen::RenderCard(const CardSystem& cardsystem, int i)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool isActive = false;
	if (this->GetCardCoord() == i)
	{
		isActive = true;
		SetConsoleTextAttribute(hConsole, 10); // 10 is green
	}

	if (i < cardsystem.m_hand.GetSize())
	{
		cout << cardsystem.m_hand.GetCard(i).GetName();
	}
	else
	{
		if (!isActive)
		{
			SetConsoleTextAttribute(hConsole, 8); // 8 is grey
		}
		cout << "   ----------------   ";
	}
	SetConsoleTextAttribute(hConsole, 15);
}
