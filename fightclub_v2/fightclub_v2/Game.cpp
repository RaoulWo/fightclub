#include "Game.h"
#include "Windows.h"

Game::Game()
	: m_mode(true)
{
}

const bool Game::GetMode() const
{
	return this->m_mode;
}

void Game::SetMode(bool b)
{
	this->m_mode = b;
}

void Game::Start()
{
	int selectedCharacters[4] = { -1,-1,-1,-1 }; // 0 for Berserker, 1 for Fighter, 2 for Guardian, -1 not Assigned -> ErrorDetection
	
	while (1)
	{
		CardSystem deck1, deck2, deck3, deck4;
		system("cls");
		this->m_ui.m_title_screen.Render();
		system("pause>nul");

		if (GetAsyncKeyState(VK_LEFT))
		{
			this->m_ui.m_title_screen.MoveLeft();
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			this->m_ui.m_title_screen.MoveRight();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (this->m_ui.m_title_screen.GetCoord() == 0)
				this->SetMode(true);
			else
				this->SetMode(false);

			int selectCount = 0;
			// Character Select Loop
			while (1)
			{
				system("cls");
				// Exit Character Select and Initialize Teams
				if (selectCount == 4)
				{
					// ##### Initialize Teams #####
					// *** Team1 ***
					// Two Berserkers
					if (selectedCharacters[0] == 0 && selectedCharacters[1] == 0)
					{
						deck1.InitializeBerserker();
						deck2.InitializeBerserker();
					}
					// Two Fighters
					else if (selectedCharacters[0] == 1 && selectedCharacters[1] == 1)
					{
						deck1.InitializeFighter();
						deck2.InitializeFighter();
					}
					// Two Guardians
					else if (selectedCharacters[0] == 2 && selectedCharacters[1] == 2)
					{
						deck1.InitializeGuardian();
						deck2.InitializeGuardian();
					}
					// One Berserker, One Fighter
					else if (selectedCharacters[0] == 0 && selectedCharacters[1] == 1 ||
						selectedCharacters[0] == 1 && selectedCharacters[1] == 0)
					{
						deck1.InitializeBerserker();
						deck2.InitializeFighter();
					}
					// One Berserker, One Guardian
					else if (selectedCharacters[0] == 0 && selectedCharacters[1] == 2 ||
						selectedCharacters[0] == 2 && selectedCharacters[1] == 0)
					{
						deck1.InitializeBerserker();
						deck2.InitializeGuardian();
					}
					// One Fighter, One Guardian
					else if (selectedCharacters[0] == 1 && selectedCharacters[1] == 2 ||
						selectedCharacters[0] == 2 && selectedCharacters[1] == 1)
					{
						deck1.InitializeFighter();
						deck2.InitializeGuardian();
					}

					// *** Team2 *** 
					// Two Berserkers
					if (selectedCharacters[2] == 0 && selectedCharacters[3] == 0)
					{
						deck3.InitializeBerserker();
						deck4.InitializeBerserker();
					}
					// Two Fighters
					else if (selectedCharacters[2] == 1 && selectedCharacters[3] == 1)
					{
						deck3.InitializeFighter();
						deck4.InitializeFighter();
					}
					// Two Guardians
					else if (selectedCharacters[2] == 2 && selectedCharacters[3] == 2)
					{
						deck3.InitializeGuardian();
						deck4.InitializeGuardian();
					}
					// One Berserker, One Fighter
					else if (selectedCharacters[2] == 0 && selectedCharacters[3] == 1 ||
						selectedCharacters[2] == 1 && selectedCharacters[3] == 0)
					{
						deck3.InitializeBerserker();
						deck4.InitializeFighter();
					}
					// One Berserker, One Guardian
					else if (selectedCharacters[2] == 0 && selectedCharacters[3] == 2 ||
						selectedCharacters[2] == 2 && selectedCharacters[3] == 0)
					{
						deck3.InitializeBerserker();
						deck4.InitializeGuardian();
					}
					// One Fighter, One Guardian
					else if (selectedCharacters[2] == 1 && selectedCharacters[3] == 2 ||
						selectedCharacters[2] == 2 && selectedCharacters[3] == 1)
					{
						deck3.InitializeFighter();
						deck4.InitializeGuardian();
					}

					// SinglePlayer
					if (this->GetMode())
					{

					}
					// MultiPlayer
					else
					{

					}

					deck1.DrawStartingHand();
					deck2.DrawStartingHand();
					deck3.DrawStartingHand();
					deck4.DrawStartingHand();
					// CombatLoop
					while (1)
					{
						system("cls");
						this->m_ui.m_combat_screen.Render(deck1);
						system("pause>nul");
						if (GetAsyncKeyState(VK_UP))
						{
							this->m_ui.m_combat_screen.MoveUp();
						}
						if (GetAsyncKeyState(VK_DOWN))
						{
							this->m_ui.m_combat_screen.MoveDown();
						}

						this->m_ui.m_combat_screen.SetActiveSelect(true);

						if (this->m_ui.m_combat_screen.GetActiveSelect()) {
							if (GetAsyncKeyState(VK_LEFT))
							{
								this->m_ui.m_combat_screen.MoveLeft();
							}
							if (GetAsyncKeyState(VK_RIGHT))
							{
								this->m_ui.m_combat_screen.MoveRight();
							}
						}

					}

				}
				this->m_ui.m_selection_screen.Render(selectCount, this->GetMode());
				system("pause>nul");
				if (GetAsyncKeyState(VK_LEFT))
				{
					this->m_ui.m_selection_screen.MoveLeft();
				}
				if (GetAsyncKeyState(VK_RIGHT))
				{
					this->m_ui.m_selection_screen.MoveRight();
				}
				if (GetAsyncKeyState(VK_SPACE))
				{
					if (this->m_ui.m_selection_screen.GetCoord() == 0)
					{
						selectedCharacters[selectCount] = 0;
					}
					else if (this->m_ui.m_selection_screen.GetCoord() == 1)
					{
						selectedCharacters[selectCount] = 1;
					}
					else
					{
						selectedCharacters[selectCount] = 2;
					}
					system("cls");
					selectCount++;
					continue;
				}
				if (GetAsyncKeyState(0x58)) // Code for X Key
				{
					for (int j = 0; j < 4; ++j)
						selectedCharacters[j] = -1;
					selectCount = 0;
					system("cls");
					break;
				}

			}
		}
	}
}
