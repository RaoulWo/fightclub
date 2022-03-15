#include "TitleScreen.h"
#include <iostream>
#include <Windows.h>

TitleScreen::TitleScreen(int x)
	: Navigation(x)
{
}

void TitleScreen::Render()
{
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (this->GetCoord() == 0)
	{
		cout << "#######################################################################################################################" << '\n'; // 1
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                               ___________.__       .__     __         .__       ___.                                #" << '\n';
		cout << "#                               \\_   _____/|__| ____ |  |___/  |_  ____ |  |  __ _\\_ |__                              #" << '\n'; // 5
		cout << "#                                |    __)  |  |/ ___\\|  |  \\   __\\/ ___\\|  | |  |  \\ __ \\                             #" << '\n';
		cout << "#                                |     \\   |  / /_/  >   Y  \\  | \\  \\___|  |_|  |  / \\_\\ \\                            #" << '\n';
		cout << "#                                \\___  /   |__\\___  /|___|  /__|  \\___  >____/____/|___  /                            #" << '\n';
		cout << "#                                    \\/      /_____/      \\/          \\/               \\/                             #" << '\n';
		cout << "#                                                                                                                     #" << '\n'; // 10
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                   "; SetConsoleTextAttribute(hConsole, 12); cout << "======================="; SetConsoleTextAttribute(hConsole, 15); cout << "     "; cout << "======================"; cout << "                                #" << '\n';
		cout << "#                                   "; SetConsoleTextAttribute(hConsole, 12); cout << "|                     |"; SetConsoleTextAttribute(hConsole, 15); cout << "     "; cout << "|                    |"; cout << "                                #" << '\n';
		cout << "#                                   "; SetConsoleTextAttribute(hConsole, 12); cout << "|    Single Player    |"; SetConsoleTextAttribute(hConsole, 15); cout << "     "; cout << "|    Multi Player    |"; cout << "                                #" << '\n'; // 15
		cout << "#                                   "; SetConsoleTextAttribute(hConsole, 12); cout << "|                     |"; SetConsoleTextAttribute(hConsole, 15); cout << "     "; cout << "|                    |"; cout << "                                #" << '\n';
		cout << "#                                   "; SetConsoleTextAttribute(hConsole, 12); cout << "======================="; SetConsoleTextAttribute(hConsole, 15); cout << "     "; cout << "======================"; cout << "                                #" << '\n'; // 25
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#######################################################################################################################" << '\n'; // 28 * 120
		//cout << "x                                                          xx                                                          x" << '\n';
	}
	else
	{
		cout << "#######################################################################################################################" << '\n'; // 1
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                               ___________.__       .__     __         .__       ___.                                #" << '\n';
		cout << "#                               \\_   _____/|__| ____ |  |___/  |_  ____ |  |  __ _\\_ |__                              #" << '\n'; // 5
		cout << "#                                |    __)  |  |/ ___\\|  |  \\   __\\/ ___\\|  | |  |  \\ __ \\                             #" << '\n';
		cout << "#                                |     \\   |  / /_/  >   Y  \\  | \\  \\___|  |_|  |  / \\_\\ \\                            #" << '\n';
		cout << "#                                \\___  /   |__\\___  /|___|  /__|  \\___  >____/____/|___  /                            #" << '\n';
		cout << "#                                    \\/      /_____/      \\/          \\/               \\/                             #" << '\n';
		cout << "#                                                                                                                     #" << '\n'; // 10
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                   "; cout << "======================="; SetConsoleTextAttribute(hConsole, 12); cout << "     "; cout << "======================"; SetConsoleTextAttribute(hConsole, 15); cout << "                                #" << '\n';
		cout << "#                                   "; cout << "|                     |"; SetConsoleTextAttribute(hConsole, 12); cout << "     "; cout << "|                    |"; SetConsoleTextAttribute(hConsole, 15); cout << "                                #" << '\n';
		cout << "#                                   "; cout << "|    Single Player    |"; SetConsoleTextAttribute(hConsole, 12); cout << "     "; cout << "|    Multi Player    |"; SetConsoleTextAttribute(hConsole, 15); cout << "                                #" << '\n'; // 15
		cout << "#                                   "; cout << "|                     |"; SetConsoleTextAttribute(hConsole, 12); cout << "     "; cout << "|                    |"; SetConsoleTextAttribute(hConsole, 15); cout << "                                #" << '\n';
		cout << "#                                   "; cout << "======================="; SetConsoleTextAttribute(hConsole, 12); cout << "     "; cout << "======================"; SetConsoleTextAttribute(hConsole, 15); cout << "                                #" << '\n'; // 25
		cout << "#                                                                                                                     #" << '\n';
		cout << "#                                                                                                                     #" << '\n';
		cout << "#######################################################################################################################" << '\n'; // 28 * 120
		//cout << "x                                                          xx                                                          x" << '\n';
	}
}

void TitleScreen::MoveLeft()
{
	this->SetCoord(this->GetCoord() - 1);
	if (this->GetCoord() < 0)
		this->SetCoord(0);
}

void TitleScreen::MoveRight()
{
	this->SetCoord(this->GetCoord() + 1);
	if (this->GetCoord() > 1)
		this->SetCoord(1);
}
