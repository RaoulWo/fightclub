#include "CombatScreen.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

CombatScreen::CombatScreen()
	: m_card_coord(0), m_number_coord(0), m_select_card(true), m_select_player(false)
{
}

const int CombatScreen::GetCardCoord() const
{
	return this->m_card_coord;
}

const int CombatScreen::GetNumberCoord() const
{
	return this->m_number_coord;
}

const bool CombatScreen::GetSelectCard() const
{
	return m_select_card;
}

const bool CombatScreen::GetSelectPlayer() const
{
	return m_select_player;
}



void CombatScreen::SetCardCoord(int x)
{
	this->m_card_coord = x;
	if (this->GetCardCoord() < 0)
		this->m_card_coord = 6;
	if (this->GetCardCoord() > 6)
		this->m_card_coord = 0;
}

void CombatScreen::SetNumberCoord(int x)
{
	this->m_number_coord = x;
	if (this->GetNumberCoord() < 0) {
		this->m_number_coord = 0;
	}
	if (this->GetNumberCoord() > 3) {
		this->m_number_coord = 3;
	}
}

void CombatScreen::SetSelectCard(bool b)
{
	m_select_card = b;
	m_select_player = !b;
}

void CombatScreen::SetSelectPlayer(bool b)
{
	m_select_player = b;
	m_select_card = !b;
}



void CombatScreen::Render(const CardSystem& cardsystem, const Team& team1, const Team& team2, int roundCount)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//cout << "x                                                         xx                                                       x" << '\n';
	cout << "#######################################################################################################################" << '\n'; // 1
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n'; // 5
	this->RenderNumbers();
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	this->RenderStats(team1, team2);
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	this->RenderHand(cardsystem,roundCount); //                                     xx
}

void CombatScreen::MoveUp()
{
	this->SetCardCoord(this->GetCardCoord() - 1);
}

void CombatScreen::MoveDown()
{
	this->SetCardCoord(this->GetCardCoord() + 1);
}

void CombatScreen::MoveLeft()
{
	this->SetNumberCoord(this->GetNumberCoord() - 1);
}

void CombatScreen::MoveRight()
{
	this->SetNumberCoord(this->GetNumberCoord() + 1);
}

void CombatScreen::RenderNumbers()
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (this->GetSelectCard()) {
		cout << "#            1111                       2222                               3333                     44  44            #" << '\n';
		cout << "#              11                      22  22                             33  33                    44  44            #" << '\n';
		cout << "#              11                         22                                 33                     444444            #" << '\n'; // 10
		cout << "#              11                        22                               33  33                        44            #" << '\n';
		cout << "#            111111                    222222                              3333                         44            #" << '\n';
	}
	else {
		if (this->GetNumberCoord() == 0) {
			cout << "#            "; SetConsoleTextAttribute(hConsole, 14); cout << "1111  "; SetConsoleTextAttribute(hConsole, 15); cout << "                     2222                               3333                     44  44            #" << '\n';
			cout << "#            "; SetConsoleTextAttribute(hConsole, 14); cout << "  11  "; SetConsoleTextAttribute(hConsole, 15); cout << "                    22  22                             33  33                    44  44            #" << '\n';
			cout << "#            "; SetConsoleTextAttribute(hConsole, 14); cout << "  11  "; SetConsoleTextAttribute(hConsole, 15); cout << "                       22                                 33                     444444            #" << '\n'; // 10
			cout << "#            "; SetConsoleTextAttribute(hConsole, 14); cout << "  11  "; SetConsoleTextAttribute(hConsole, 15); cout << "                      22                               33  33                        44            #" << '\n';
			cout << "#            "; SetConsoleTextAttribute(hConsole, 14); cout << "111111"; SetConsoleTextAttribute(hConsole, 15); cout << "                    222222                              3333                         44            #" << '\n';
		} 
		else if (this->GetNumberCoord() == 1) {
			cout << "#            1111                      "; SetConsoleTextAttribute(hConsole, 14); cout << " 2222 "; SetConsoleTextAttribute(hConsole, 15); cout << "                              3333                     44  44            #" << '\n';
			cout << "#              11                      "; SetConsoleTextAttribute(hConsole, 14); cout << "22  22"; SetConsoleTextAttribute(hConsole, 15); cout << "                             33  33                    44  44            #" << '\n';
			cout << "#              11                      "; SetConsoleTextAttribute(hConsole, 14); cout << "   22 "; SetConsoleTextAttribute(hConsole, 15); cout << "                                33                     444444            #" << '\n'; // 10
			cout << "#              11                      "; SetConsoleTextAttribute(hConsole, 14); cout << "  22  "; SetConsoleTextAttribute(hConsole, 15); cout << "                             33  33                        44            #" << '\n';
			cout << "#            111111                    "; SetConsoleTextAttribute(hConsole, 14); cout << "222222"; SetConsoleTextAttribute(hConsole, 15); cout << "                              3333                         44            #" << '\n';
		}
		else if (this->GetNumberCoord() == 2) {
			cout << "#            1111                       2222                              "; SetConsoleTextAttribute(hConsole, 14); cout << " 3333 "; SetConsoleTextAttribute(hConsole, 15); cout << "                    44  44            #" << '\n';
			cout << "#              11                      22  22                             "; SetConsoleTextAttribute(hConsole, 14); cout << "33  33"; SetConsoleTextAttribute(hConsole, 15); cout << "                    44  44            #" << '\n';
			cout << "#              11                         22                              "; SetConsoleTextAttribute(hConsole, 14); cout << "   33 "; SetConsoleTextAttribute(hConsole, 15); cout << "                    444444            #" << '\n'; // 10
			cout << "#              11                        22                               "; SetConsoleTextAttribute(hConsole, 14); cout << "33  33"; SetConsoleTextAttribute(hConsole, 15); cout << "                        44            #" << '\n';
			cout << "#            111111                    222222                             "; SetConsoleTextAttribute(hConsole, 14); cout << " 3333 "; SetConsoleTextAttribute(hConsole, 15); cout << "                        44            #" << '\n';
		}
		else {
			cout << "#            1111                       2222                               3333                     "; SetConsoleTextAttribute(hConsole, 14); cout << "44  44"; SetConsoleTextAttribute(hConsole, 15); cout << "            #" << '\n';
			cout << "#              11                      22  22                             33  33                    "; SetConsoleTextAttribute(hConsole, 14); cout << "44  44"; SetConsoleTextAttribute(hConsole, 15); cout << "            #" << '\n';
			cout << "#              11                         22                                 33                     "; SetConsoleTextAttribute(hConsole, 14); cout << "444444"; SetConsoleTextAttribute(hConsole, 15); cout << "            #" << '\n'; // 10
			cout << "#              11                        22                               33  33                    "; SetConsoleTextAttribute(hConsole, 14); cout << "    44"; SetConsoleTextAttribute(hConsole, 15); cout << "            #" << '\n';
			cout << "#            111111                    222222                              3333                     "; SetConsoleTextAttribute(hConsole, 14); cout << "    44"; SetConsoleTextAttribute(hConsole, 15); cout << "            #" << '\n';
		}
	}
	

	SetConsoleTextAttribute(hConsole, 10);
	SetConsoleTextAttribute(hConsole, 15);
}

void CombatScreen::RenderStats(const Team& team1, const Team& team2)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "#    "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "    "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "             "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "    "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "    #" << '\n';
	cout << "#    "; SetConsoleTextAttribute(hConsole, 11); cout << "| "; cout << setfill('0') << setw(2) << team1.m_members[0].GetArmor(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "| "; cout << setfill('0') << setw(2) << team1.m_members[0].GetCurrHealth(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "| "; cout << setfill('0') << setw(2) << team1.m_members[0].GetCurrStamina(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "    "; SetConsoleTextAttribute(hConsole, 11); cout << "| "; cout << setfill('0') << setw(2) << team1.m_members[1].GetArmor(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "| "; cout << setfill('0') << setw(2) << team1.m_members[1].GetCurrHealth(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "| "; cout << setfill('0') << setw(2) << team1.m_members[1].GetCurrStamina(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "             "; SetConsoleTextAttribute(hConsole, 11); cout << "| "; cout << setfill('0') << setw(2) << team2.m_members[0].GetArmor(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "| "; cout << setfill('0') << setw(2) << team2.m_members[0].GetCurrHealth(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "| "; cout << setfill('0') << setw(2) << team2.m_members[0].GetCurrStamina(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "    "; SetConsoleTextAttribute(hConsole, 11); cout << "| "; cout << setfill('0') << setw(2) << team2.m_members[1].GetArmor(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "| "; cout << setfill('0') << setw(2) << team2.m_members[1].GetCurrHealth(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "| "; cout << setfill('0') << setw(2) << team2.m_members[1].GetCurrStamina(); cout << " |"; SetConsoleTextAttribute(hConsole, 15); cout << "    #" << '\n';
	cout << "#    "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "    "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "             "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "    "; SetConsoleTextAttribute(hConsole, 11); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 12); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "  "; SetConsoleTextAttribute(hConsole, 10); cout << "======"; SetConsoleTextAttribute(hConsole, 15); cout << "    #" << '\n';
}

void CombatScreen::RenderHand(const CardSystem& cardsystem, int roundCount)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (roundCount == 0) {
		cout << "#=====================================================================================================================#" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 0); cout << " |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 1); cout << " |                                                                        |"; cout << "       1111        #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 2); cout << " |                                                                        |"; cout << "         11        #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 3); cout << " |"; this->RenderCardDescription(cardsystem);                    cout << "|"; cout << "         11        #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 4); cout << " |                                                                        |"; cout << "         11        #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 5); cout << " |                                                                        |"; cout << "       111111      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 6); cout << " |                                                                        |                   #" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "#######################################################################################################################" << '\n'; // 28 * 120
		//cout << "x                                                          xx                                                       x" << '\n';
	}
	else if (roundCount == 1) {
		cout << "#=====================================================================================================================#" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 0); cout << " |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 1); cout << " |                                                                        |"; cout << "        3333       #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 2); cout << " |                                                                        |"; cout << "       33  33      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 3); cout << " |"; this->RenderCardDescription(cardsystem);                    cout << "|"; cout << "          33       #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 4); cout << " |                                                                        |"; cout << "       33  33      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 5); cout << " |                                                                        |"; cout << "        3333       #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 6); cout << " |                                                                        |                   #" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "#######################################################################################################################" << '\n'; // 28 * 120
		//cout << "x                                                          xx                                                       x" << '\n';
	}
	else if (roundCount == 2) {
		cout << "#=====================================================================================================================#" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 0); cout << " |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 1); cout << " |                                                                        |"; cout << "        2222       #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 2); cout << " |                                                                        |"; cout << "       22  22      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 3); cout << " |"; this->RenderCardDescription(cardsystem);                    cout << "|"; cout << "          22       #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 4); cout << " |                                                                        |"; cout << "         22        #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 5); cout << " |                                                                        |"; cout << "       222222      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 6); cout << " |                                                                        |                   #" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "#######################################################################################################################" << '\n'; // 28 * 120
		//cout << "x                                                          xx                                                       x" << '\n';
	}
	else {
		cout << "#=====================================================================================================================#" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 0); cout << " |                                                                        |                   #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 1); cout << " |                                                                        |"; cout << "       44  44      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 2); cout << " |                                                                        |"; cout << "       44  44      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 3); cout << " |"; this->RenderCardDescription(cardsystem);                    cout << "|"; cout << "       444444      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 4); cout << " |                                                                        |"; cout << "           44      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 5); cout << " |                                                                        |"; cout << "           44      #" << '\n';
		cout << "# "; this->RenderCardName(cardsystem, 6); cout << " |                                                                        |                   #" << '\n';
		cout << "#                        |                                                                        |                   #" << '\n';
		cout << "#######################################################################################################################" << '\n'; // 28 * 120
		//cout << "x                                                          xx                                                       x" << '\n';
	}
}

















void CombatScreen::RenderCardName(const CardSystem& cardsystem, int i)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool isActive = false;
	if (this->GetCardCoord() == i)
	{
		isActive = true;
		SetConsoleTextAttribute(hConsole, 14); // 14 is yellow
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

void CombatScreen::RenderCardDescription(const CardSystem& cardsystem)
{
	using namespace std;
	if (this->GetCardCoord() < cardsystem.m_hand.GetSize()) {
		cout << cardsystem.m_hand.GetCard(this->GetCardCoord()).GetDescription();
	}
	else {
		cout << "                                                                        ";
	}
}
