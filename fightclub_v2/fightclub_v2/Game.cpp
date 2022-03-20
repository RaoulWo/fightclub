#include "Game.h"
#include "Windows.h"

Game::Game()
	: m_mode(true), m_round_count(0)
{
}

const bool Game::GetMode() const
{
	return this->m_mode;
}

const int Game::GetRoundCount() const
{
	return this->m_round_count;
}

void Game::SetMode(bool b)
{
	this->m_mode = b;
}

void Game::SetRoundCount(int i)
{
	this->m_round_count = i % 4;

}

void Game::StartScreen()
{
	while (1) {
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
			if (this->m_ui.m_title_screen.GetCoord() == 0) {
				this->SetMode(true);
				return;
			}
			else {
				this->SetMode(false);
				return;
			}
		}
	}
}

void Game::CharacterSelect()
{
	int count = 0;
	// Character Select Loop
	do
	{
		system("cls");		
		this->m_ui.m_selection_screen.Render(count, this->GetMode());
		system("pause>nul");

		if (GetAsyncKeyState(VK_LEFT))
			this->m_ui.m_selection_screen.MoveLeft();
		if (GetAsyncKeyState(VK_RIGHT))
			this->m_ui.m_selection_screen.MoveRight();
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (this->m_ui.m_selection_screen.GetCoord() == 0)
				m_chosen_classes[count] = berserker;
			else if (this->m_ui.m_selection_screen.GetCoord() == 1)
				m_chosen_classes[count] = fighter;
			else
				m_chosen_classes[count] = guardian;
			system("cls");
			count++;
			continue;
		}
		if (GetAsyncKeyState(0x58)) // Code for X Key
		{
			for (int j = 0; j < 4; ++j)
				m_chosen_classes[j] = undefined;
			count = 0;
			system("cls");
			break;
		}

	} while (count < 4);

	// ##### Initialize Teams #####
	for (int i = 0; i < 4; ++i) {
		switch (m_chosen_classes[i]) {
		case berserker:
			m_decks[i].InitializeBerserker();
			break;
		case fighter:
			m_decks[i].InitializeFighter();
			break;
		case guardian:
			m_decks[i].InitializeGuardian();
			break;
		default:
			exit(-1);
			break;
		}
	}
}

void Game::SinglePlayerCombat()
{
	int round = 0;
	bool turnOver = false;
	for (int i = 0; i < 4; ++i) {
		m_decks[i].DrawStartingHand();
	}
	do {
		system("cls");
		m_ui.m_combat_screen.Render(m_decks[round], m_teams[0], m_teams[1], round);
		system("pause>nul");

		if (round == 0 && !m_teams[0].m_members[0].GetAlive() ||
			round == 1 && !m_teams[1].m_members[0].GetAlive() ||
			round == 1 && !m_teams[0].m_members[1].GetAlive() ||
			round == 1 && !m_teams[1].m_members[1].GetAlive()) {
			round = (round + 1) % 4;
			turnOver = true;
		}

		if (turnOver) {
			if (round == 0 && m_teams[0].m_members[0].GetAlive()) {
				m_teams[0].m_members[0].SetArmor(0);
				m_teams[0].m_members[0].SetCurrStamina(m_teams[0].m_members[0].GetStartingStamina());
				m_decks[0].DiscardHand();
				m_decks[0].DrawStartingHand();
				turnOver = false;
			}
			else if (round == 1 && m_teams[1].m_members[0].GetAlive()) {
				m_teams[1].m_members[0].SetArmor(0);
				m_teams[1].m_members[0].SetCurrStamina(m_teams[1].m_members[0].GetStartingStamina());
				m_decks[2].DiscardHand();
				m_decks[2].DrawStartingHand();
				turnOver = false;
			}
			else if (round == 2 && m_teams[0].m_members[1].GetAlive()) {
				m_teams[0].m_members[1].SetArmor(0);
				m_teams[0].m_members[1].SetCurrStamina(m_teams[0].m_members[1].GetStartingStamina());
				m_decks[1].DiscardHand();
				m_decks[1].DrawStartingHand();
				turnOver = false;
			}
			else if (round == 3 && m_teams[1].m_members[1].GetAlive()) {
				m_teams[1].m_members[1].SetArmor(0);
				m_teams[1].m_members[1].SetCurrStamina(m_teams[1].m_members[1].GetStartingStamina());
				m_decks[3].DiscardHand();
				m_decks[3].DrawStartingHand();
				turnOver = false;
			}
			else {
				round = (round + 1) % 4;
				continue;
			}
		}
		

		if (GetAsyncKeyState(VK_UP) && m_ui.m_combat_screen.GetSelectCard())
			this->m_ui.m_combat_screen.MoveUp();
		if (GetAsyncKeyState(VK_DOWN) && m_ui.m_combat_screen.GetSelectCard())
			this->m_ui.m_combat_screen.MoveDown();
		if (GetAsyncKeyState(VK_LEFT) && m_ui.m_combat_screen.GetSelectPlayer())
			this->m_ui.m_combat_screen.MoveLeft();
		if (GetAsyncKeyState(VK_RIGHT) && m_ui.m_combat_screen.GetSelectPlayer())
			this->m_ui.m_combat_screen.MoveRight();
		if (GetAsyncKeyState(VK_SPACE) && m_ui.m_combat_screen.GetSelectCard())
		{
			if (this->m_ui.m_combat_screen.GetCardCoord() < m_decks[round].m_hand.GetSize()) {

			}
		}
		if (GetAsyncKeyState(0x58) && m_ui.m_combat_screen.GetSelectCard())
		{
			turnOver = true;
			round = (round + 1) % 4;
			continue;
		}

		if (round == 0 && (m_teams[0].m_members[0].GetCurrStamina() == 0 || m_decks[round].m_hand.GetSize() == 0)) {
			turnOver = true;
			round = (round + 1) % 4;
		}
		if (round == 0 && (m_teams[1].m_members[0].GetCurrStamina() == 0 || m_decks[round].m_hand.GetSize() == 0)) {
			turnOver = true;
			round = (round + 1) % 4;
		}
		if (round == 0 && (m_teams[0].m_members[1].GetCurrStamina() == 0 || m_decks[round].m_hand.GetSize() == 0)) {
			turnOver = true;
			round = (round + 1) % 4;
		}
		if (round == 0 && (m_teams[1].m_members[1].GetCurrStamina() == 0 || m_decks[round].m_hand.GetSize() == 0)) {
			turnOver = true;
			round = (round + 1) % 4;
		}

	} while (m_teams[0].GetAlive() && m_teams[1].GetAlive());

}









void Game::Loop()
{
	
	while (1)
	{
		this->StartScreen();
		this->CharacterSelect();
		this->SinglePlayerCombat();
			
		
			
	}

}









//
//int roundCount = 0;
//// CombatLoop
//while (1)
//{
//	system("cls");
//	if (roundCount == 0) { // Character 1
//		this->m_ui.m_combat_screen.Render(deck1, team1, team2, roundCount);
//		if (!team1.m_member1.GetAlive()) {
//			roundCount = (roundCount + 1) % 4;
//			continue;
//		}
//		if (team1.m_member1.GetCurrStamina() == 0) {
//			deck1.DrawStartingHand();
//			team1.m_member1.SetArmor(0);
//			team1.m_member1.SetCurrStamina(team1.m_member1.GetStartingStamina());
//		}
//
//	}
//	else if (roundCount == 1) { // Character 3
//		this->m_ui.m_combat_screen.Render(deck3, team1, team2, roundCount);
//		if (!team1.m_member2.GetAlive()) {
//			roundCount = (roundCount + 1) % 4;
//			continue;
//		}
//		if (team1.m_member2.GetCurrStamina() == 0) {
//			deck2.DrawStartingHand();
//			team1.m_member2.SetArmor(0);
//			team1.m_member2.SetCurrStamina(team1.m_member2.GetStartingStamina());
//		}
//	}
//	else if (roundCount == 2) { // Character 2
//		this->m_ui.m_combat_screen.Render(deck2, team1, team2, roundCount);
//		if (!team2.m_member1.GetAlive()) {
//			roundCount = (roundCount + 1) % 4;
//			continue;
//		}
//		if (team2.m_member1.GetCurrStamina() == 0) {
//			deck3.DrawStartingHand();
//			team2.m_member1.SetArmor(0);
//			team2.m_member1.SetCurrStamina(team2.m_member1.GetStartingStamina());
//		}
//	}
//	else { // Character 4
//		this->m_ui.m_combat_screen.Render(deck4, team1, team2, roundCount);
//		if (!team2.m_member2.GetAlive()) {
//			roundCount = (roundCount + 1) % 4;
//			continue;
//		}
//		if (team2.m_member2.GetCurrStamina() == 0) {
//			deck4.DrawStartingHand();
//			team2.m_member2.SetArmor(0);
//			team2.m_member2.SetCurrStamina(team2.m_member2.GetStartingStamina());
//		}
//	}
//	system("pause>nul");
//	
//	if (GetAsyncKeyState(VK_SPACE) && !this->m_ui.m_combat_screen.GetActiveSelect() && roundCount == 0)
//	{
//		if (this->m_ui.m_combat_screen.GetCardCoord() < deck1.m_hand.GetSize()) {
//			ActivateCard(deck1, this->m_ui.m_combat_screen.GetCardCoord(), roundCount, team1, team2);
//		}
//		deck1.DiscardHand();
//	}
//	if (GetAsyncKeyState(VK_SPACE) && !this->m_ui.m_combat_screen.GetActiveSelect() && roundCount == 1)
//	{
//		if (this->m_ui.m_combat_screen.GetCardCoord() < deck2.m_hand.GetSize()) {
//			ActivateCard(deck2, this->m_ui.m_combat_screen.GetCardCoord(), roundCount, team1, team2);
//		}
//		deck2.DiscardHand();
//	}
//	if (GetAsyncKeyState(VK_SPACE) && !this->m_ui.m_combat_screen.GetActiveSelect() && roundCount == 2)
//	{
//		if (this->m_ui.m_combat_screen.GetCardCoord() < deck3.m_hand.GetSize()) {
//			ActivateCard(deck3, this->m_ui.m_combat_screen.GetCardCoord(), roundCount, team1, team2);
//		}
//		deck3.DiscardHand();
//	}
//	if (GetAsyncKeyState(VK_SPACE) && !this->m_ui.m_combat_screen.GetActiveSelect() && roundCount == 3)
//	{
//		if (this->m_ui.m_combat_screen.GetCardCoord() < deck4.m_hand.GetSize()) {
//			ActivateCard(deck4, this->m_ui.m_combat_screen.GetCardCoord(), roundCount, team1, team2);
//		}
//		deck4.DiscardHand();
//	}
//
//	if (team1.m_member1.GetCurrHealth() <= 0) {
//		team1.m_member1.Die();
//	}
//	if (team1.m_member2.GetCurrHealth() <= 0) {
//		team1.m_member2.Die();
//	}
//	if (team2.m_member1.GetCurrHealth() <= 0) {
//		team2.m_member1.Die();
//	}
//	if (team2.m_member2.GetCurrHealth() <= 0) {
//		team2.m_member2.Die();
//	}
//	if (!team1.m_member1.GetAlive() && !team1.m_member2.GetAlive() ||
//		!team2.m_member1.GetAlive() && !team2.m_member2.GetAlive()) {
//		break;
//	}
//}
//
//
//
//
//
//
//


























































//void Game::ActivateCard(CardSystem& deck, int i, int& round, Team& team1, Team& team2)
//{
//	int id = deck.m_hand.GetCard(i).GetId();
//	int target;
//	Character* self;
//	if (round == 0) {
//		self = &team1.m_member1;
//	}
//	else if (round == 1) {
//		self = &team1.m_member2;
//	}
//	else if (round == 2) {
//		self = &team2.m_member1;
//	}
//	else {
//		self = &team2.m_member2;
//	}
//
//	if (deck.m_hand.GetCard(i).GetCost() > self->GetCurrStamina())
//		return;
//	else {
//		self->SetCurrStamina(self->GetCurrStamina() - deck.m_hand.GetCard(i).GetCost());
//	}
//
//	if (id == 0) { // strike
//		m_ui.m_combat_screen.SetActiveSelect(true);
//		while (1) {
//			this->m_ui.m_combat_screen.Render(deck, team1, team2, round);
//			system("pause>nul");
//			if (this->m_ui.m_combat_screen.GetActiveSelect()) {
//				if (GetAsyncKeyState(VK_LEFT))
//				{
//					this->m_ui.m_combat_screen.MoveLeft();
//				}
//				if (GetAsyncKeyState(VK_RIGHT))
//				{
//					this->m_ui.m_combat_screen.MoveRight();
//				}
//				if (GetAsyncKeyState(VK_SPACE))
//				{
//					if ((round == 0 || round == 1) && 
//						(m_ui.m_combat_screen.GetNumberCoord() == 2)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team2.m_member1.GetArmor();
//						team2.m_member1.SetArmor(team2.m_member1.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team2.m_member1.SetCurrHealth(team2.m_member1.GetCurrHealth() - diff);
//						break;
//					}
//					if ((round == 0 || round == 1) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 3)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team2.m_member2.GetArmor();
//						team2.m_member2.SetArmor(team2.m_member2.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team2.m_member2.SetCurrHealth(team2.m_member2.GetCurrHealth() - diff);
//						break;
//					}
//					if ((round == 2 || round == 3) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 0)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team1.m_member1.GetArmor();
//						team1.m_member1.SetArmor(team1.m_member1.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team1.m_member1.SetCurrHealth(team1.m_member1.GetCurrHealth() - diff);
//						break;
//					}
//					if ((round == 2 || round == 3) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 1)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team1.m_member2.GetArmor();
//						team1.m_member2.SetArmor(team1.m_member2.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team1.m_member2.SetCurrHealth(team1.m_member2.GetCurrHealth() - diff);
//						break;
//					}
//				}
//			}
//		}
//		m_ui.m_combat_screen.SetActiveSelect(false);
//	}
//	else if (id == 1) { // bludgeon
//		m_ui.m_combat_screen.SetActiveSelect(true);
//		while (1) {
//			this->m_ui.m_combat_screen.Render(deck, team1, team2, round);
//			system("pause>nul");
//			if (this->m_ui.m_combat_screen.GetActiveSelect()) {
//				if (GetAsyncKeyState(VK_LEFT))
//				{
//					this->m_ui.m_combat_screen.MoveLeft();
//				}
//				if (GetAsyncKeyState(VK_RIGHT))
//				{
//					this->m_ui.m_combat_screen.MoveRight();
//				}
//				if (GetAsyncKeyState(VK_SPACE))
//				{
//					if ((round == 0 || round == 2) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 2)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team2.m_member1.GetArmor();
//						team2.m_member1.SetArmor(team2.m_member1.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team2.m_member1.SetCurrHealth(team2.m_member1.GetCurrHealth() - diff);
//						break;
//					}
//					if ((round == 0 || round == 2) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 3)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team2.m_member2.GetArmor();
//						team2.m_member2.SetArmor(team2.m_member2.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team2.m_member2.SetCurrHealth(team2.m_member2.GetCurrHealth() - diff);
//						break;
//					}
//					if ((round == 1 || round == 3) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 0)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team1.m_member1.GetArmor();
//						team1.m_member1.SetArmor(team1.m_member1.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team1.m_member1.SetCurrHealth(team1.m_member1.GetCurrHealth() - diff);
//						break;
//					}
//					if ((round == 1 || round == 3) &&
//						(m_ui.m_combat_screen.GetNumberCoord() == 1)) {
//						int diff = deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength() - team1.m_member2.GetArmor();
//						team1.m_member2.SetArmor(team1.m_member2.GetArmor() - deck.m_hand.GetCard(i).GetDamageModifier() + self->GetStrength());
//						team1.m_member2.SetCurrHealth(team1.m_member2.GetCurrHealth() - diff);
//						break;
//					}
//				}
//			}
//		}
//		m_ui.m_combat_screen.SetActiveSelect(false);
//	}
//	else if (id == 2) { // cleave
//
//	}
//	else if (id == 3) { // pommelstrike
//
//	}
//	else if (id == 4) { // shieldbash
//
//	}
//	else if (id == 5) { // rampage
//
//	}
//	else if (id == 6) { // feed
//
//	}
//	else if (id == 7) { // bodyslam
//
//	}
//	else if (id == 8) { // defend
//
//	}
//	else if (id == 9) { // impervious
//
//	}
//	else if (id == 10) { // shrugitoff
//
//	}
//	else if (id == 11) { // bastion
//
//	}
//	else if (id == 12) { // inflame
//
//	}
//	else if (id == 13) { // footwork
//
//	}
//	else if (id == 14) { // limitbreak
//
//	}
//	else if (id == 15) { // standtheground
//
//	}
//	else if (id == 16) { // warcry
//
//	}
//	else if (id == 17) { // bloodletting
//
//	}
//	round = (round + 1) % 4;
//}
