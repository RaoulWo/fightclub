#include "SelectionScreen.h"
#include <iostream>
#include <Windows.h>
#include <string>

SelectionScreen::SelectionScreen(int x)
	: Navigation(1)
{
}

void SelectionScreen::Render(int i, bool mode)
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (this->GetCoord() == 0)
	{
		this->RenderLeftActive();
		this->RenderBottom(i, mode);
	}
	else if (this->GetCoord() == 1)
	{
		this->RenderMiddleActive();
		this->RenderBottom(i, mode);
	}
	else
	{
		this->RenderRightActive();
		this->RenderBottom(i, mode);
	}
}

void SelectionScreen::MoveLeft()
{
	this->SetCoord(this->GetCoord() - 1);
	if (this->GetCoord() < 0)
		this->SetCoord(0);
}

void SelectionScreen::MoveRight()
{
	this->SetCoord(this->GetCoord() + 1);
	if (this->GetCoord() > 2)
		this->SetCoord(2);
}

void SelectionScreen::RenderLeftActive()
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "#######################################################################################################################" << '\n'; // 1
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                           ,  /\\  ,              "; SetConsoleTextAttribute(hConsole, 15); cout << "          /\\           "; cout << "                                             "; cout << "#" << '\n'; // 5
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                          //'-||-'\\\\            "; SetConsoleTextAttribute(hConsole, 15); cout << "           ||           "; cout << "          |'-._/\\_.-'|                       "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                         (| -=||=- |)             "; SetConsoleTextAttribute(hConsole, 15); cout << "         ||             "; cout << "        |    ||    |                       "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                          \\\\,-||-.//            "; SetConsoleTextAttribute(hConsole, 15); cout << "           ||           "; cout << "          |___o()o___|                       "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                           `  ||  `               "; SetConsoleTextAttribute(hConsole, 15); cout << "         ||             "; cout << "        |__((<>))__|                       "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 15); cout << "         ||             "; cout << "        \\   o\\/o   /                       "; cout << "#" << '\n'; // 10
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 15); cout << "         ||             "; cout << "         \\   ||   /                        "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 15); cout << "      <======>          "; cout << "          \\  ||  /                         "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 15); cout << "         )(             "; cout << "           '.||.'                          "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                              ()                  "; SetConsoleTextAttribute(hConsole, 15); cout << "         ()             "; cout << "             ``                            "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                                                  "; SetConsoleTextAttribute(hConsole, 15); cout << "                        "; cout << "                                           "; cout << "#" << '\n';
	cout << "#"; SetConsoleTextAttribute(hConsole, 14); cout << "                          Berserker               "; SetConsoleTextAttribute(hConsole, 15); cout << "      Fighter           "; cout << "          Guardian                         "; cout << "#" << '\n';
}

void SelectionScreen::RenderMiddleActive()
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "#######################################################################################################################" << '\n'; // 1
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#"; cout << "                           ,  /\\  ,              "; SetConsoleTextAttribute(hConsole, 14); cout << "          /\\           "; SetConsoleTextAttribute(hConsole, 15); cout << "                                             "; cout << "#" << '\n'; // 5
	cout << "#"; cout << "                          //'-||-'\\\\            "; SetConsoleTextAttribute(hConsole, 14); cout << "           ||           "; SetConsoleTextAttribute(hConsole, 15); cout << "          |'-._/\\_.-'|                       "; cout << "#" << '\n';
	cout << "#"; cout << "                         (| -=||=- |)             "; SetConsoleTextAttribute(hConsole, 14); cout << "         ||             "; SetConsoleTextAttribute(hConsole, 15); cout << "        |    ||    |                       "; cout << "#" << '\n';
	cout << "#"; cout << "                          \\\\,-||-.//            "; SetConsoleTextAttribute(hConsole, 14); cout << "           ||           "; SetConsoleTextAttribute(hConsole, 15); cout << "          |___o()o___|                       "; cout << "#" << '\n';
	cout << "#"; cout << "                           `  ||  `               "; SetConsoleTextAttribute(hConsole, 14); cout << "         ||             "; SetConsoleTextAttribute(hConsole, 15); cout << "        |__((<>))__|                       "; cout << "#" << '\n';
	cout << "#"; cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 14); cout << "         ||             "; SetConsoleTextAttribute(hConsole, 15); cout << "        \\   o\\/o   /                       "; cout << "#" << '\n'; // 10
	cout << "#"; cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 14); cout << "         ||             "; SetConsoleTextAttribute(hConsole, 15); cout << "         \\   ||   /                        "; cout << "#" << '\n';
	cout << "#"; cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 14); cout << "      <======>          "; SetConsoleTextAttribute(hConsole, 15); cout << "          \\  ||  /                         "; cout << "#" << '\n';
	cout << "#"; cout << "                              ||                  "; SetConsoleTextAttribute(hConsole, 14); cout << "         )(             "; SetConsoleTextAttribute(hConsole, 15); cout << "           '.||.'                          "; cout << "#" << '\n';
	cout << "#"; cout << "                              ()                  "; SetConsoleTextAttribute(hConsole, 14); cout << "         ()             "; SetConsoleTextAttribute(hConsole, 15); cout << "             ``                            "; cout << "#" << '\n';
	cout << "#"; cout << "                                                  "; SetConsoleTextAttribute(hConsole, 14); cout << "                        "; SetConsoleTextAttribute(hConsole, 15); cout << "                                           "; cout << "#" << '\n';
	cout << "#"; cout << "                          Berserker               "; SetConsoleTextAttribute(hConsole, 14); cout << "      Fighter           "; SetConsoleTextAttribute(hConsole, 15); cout << "          Guardian                         "; cout << "#" << '\n';
}

void SelectionScreen::RenderRightActive()
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "#######################################################################################################################" << '\n'; // 1
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#"; cout << "                           ,  /\\  ,              "; cout << "          /\\           "; SetConsoleTextAttribute(hConsole, 14); cout << "                                             "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n'; // 5
	cout << "#"; cout << "                          //'-||-'\\\\            "; cout << "           ||           "; SetConsoleTextAttribute(hConsole, 14); cout << "          |'-._/\\_.-'|                       "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                         (| -=||=- |)             "; cout << "         ||             "; SetConsoleTextAttribute(hConsole, 14); cout << "        |    ||    |                       "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                          \\\\,-||-.//            "; cout << "           ||           "; SetConsoleTextAttribute(hConsole, 14); cout << "          |___o()o___|                       "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                           `  ||  `               "; cout << "         ||             "; SetConsoleTextAttribute(hConsole, 14); cout << "        |__((<>))__|                       "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                              ||                  "; cout << "         ||             "; SetConsoleTextAttribute(hConsole, 14); cout << "        \\   o\\/o   /                       "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n'; // 10
	cout << "#"; cout << "                              ||                  "; cout << "         ||             "; SetConsoleTextAttribute(hConsole, 14); cout << "         \\   ||   /                        "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                              ||                  "; cout << "      <======>          "; SetConsoleTextAttribute(hConsole, 14); cout << "          \\  ||  /                         "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                              ||                  "; cout << "         )(             "; SetConsoleTextAttribute(hConsole, 14); cout << "           '.||.'                          "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                              ()                  "; cout << "         ()             "; SetConsoleTextAttribute(hConsole, 14); cout << "             ``                            "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                                                  "; cout << "                        "; SetConsoleTextAttribute(hConsole, 14); cout << "                                           "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
	cout << "#"; cout << "                          Berserker               "; cout << "      Fighter           "; SetConsoleTextAttribute(hConsole, 14); cout << "          Guardian                         "; SetConsoleTextAttribute(hConsole, 15); cout << "#" << '\n';
}

void SelectionScreen::RenderBottom(int i, bool mode)
{
	using namespace std;
	string s;
	if (i < 2 && !mode)
		s = "    Player1, choose your Team!    ";
	if (i >= 2 && !mode)
		s = "    Player2, choose your Team!    ";
	if (i < 2 && mode)
		s = "         Choose your Team!        ";
	if (i >= 2 && mode)
		s = "       Choose your Enemies!       ";

	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                           ====================================                                      #" << '\n';
	cout << "#                                           |                                  |                                      #" << '\n';
	cout << "#                                           |"; cout << s;            cout << "|                                      #" << '\n'; // 15
	cout << "#                                           |                                  |                                      #" << '\n';
	cout << "#                                           ====================================                                      #" << '\n'; // 25
	cout << "#                                                                                                                     #" << '\n';
	cout << "#                                                                                                                     #" << '\n';
	cout << "#######################################################################################################################" << '\n'; // 28 * 120
	//cout << "x                                                          xx                                                          x" << '\n';
}
