#include "CardSystem.h"
#include <cassert>

void CardSystem::DrawCard()
{
	if (this->m_hand.GetSize() == MAX_HAND_SIZE) 
		return;
	if (this->m_deck.GetSize() == 0) {
		this->Merge();
	}
	else {
		this->m_deck.DiscardCardTo(this->m_hand);
	}
}

void CardSystem::DrawCards(int i)
{
	assert(0 <= i);
	for (int j = 0; j < i; ++j) {
		this->DrawCard();
	}
}

void CardSystem::DrawStartingHand()
{
	this->DrawCards(STARTING_HAND_SIZE);
}

void CardSystem::DiscardCard()
{
	if (this->m_hand.GetSize() == 0) 
		return;
	this->m_hand.Shuffle();
	this->m_hand.DiscardCardTo(this->m_discard_pile);
}

void CardSystem::DiscardHand()
{
	while (this->m_hand.GetSize() > 0) {
		this->DiscardCard();
	}
}

void CardSystem::Merge()
{
	while (this->m_discard_pile.GetSize() > 0) {
		this->m_discard_pile.DiscardCardTo(this->m_deck);
	}
	this->m_deck.Shuffle();
}

void CardSystem::InitializeBerserker()
{
	Card strike("   Strike             ", "      Deal 6 damage to a single enemy                                                       ", 1, 6, 0, 0, 0, 0, 0, 0, 0);
	Card defend("   Defend             ", "      Increase your armor by 5                                                              ", 1, 0, 5, 0, 0, 0, 0, 0, 0);
	Card bludgeon("   Bludgeon           ", "      Deal 30 damage to a single enemy                                                      ", 3, 30, 0, 0, 0, 0, 0, 0, 0);
	Card cleave("   Cleave             ", "      Deal 8 damage to the enemy team                                                       ", 1, 8, 0, 0, 0, 0, 0, 0, 0);
	Card inflame("   Inflame            ", "      Permanently increase your strength by 2                                               ", 1, 0, 0, 0, 0, 2, 0, 0, 0);
	Card limitbreak("   Limit Break        ", "      Double your strength                                                                  ", 1, 0, 0, 0, 0, 2, 0, 0, 0);
	Card warcry("   Warcry             ", "      Draw 2 cards, then discard a card                                                     ", 0, 0, 0, 0, 0, 0, 0, 2, 1);
	Card bloodletting("   Bloodletting       ", "      Lose 10 health and gain 2 stamina for this turn                                       ", 0, 0, 0, -10, 2, 0, 0, 0, 0);

	for (int i = 0; i < 5; ++i) {
		this->m_deck.PushCard(strike);
		this->m_deck.PushCard(defend);
	}
	for (int j = 0; j < 2; ++j)
	{
		this->m_deck.PushCard(cleave);
		this->m_deck.PushCard(inflame);
		this->m_deck.PushCard(warcry);
		this->m_deck.PushCard(bludgeon);
	}
	this->m_deck.PushCard(limitbreak);
	this->m_deck.PushCard(bloodletting);
}

void CardSystem::InitializeFighter()
{
	Card strike("   Strike             ", "      Deal 6 damage to a single enemy                                                       ", 1, 6, 0, 0, 0, 0, 0, 0, 0);
	Card defend("   Defend             ", "      Increase your armor by 5                                                              ", 1, 0, 5, 0, 0, 0, 0, 0, 0);
	Card inflame("   Inflame            ", "      Permanently increase your strength by 2                                               ", 1, 0, 0, 0, 0, 2, 0, 0, 0);
	Card footwork("   Footwork           ", "      Permanently increase your defense by 2                                                ", 1, 0, 0, 0, 0, 0, 2, 0, 0);
	Card warcry("   Warcry             ", "      Draw 2 cards, then discard a card                                                     ", 0, 0, 0, 0, 0, 0, 0, 2, 1);
	Card pommelstrike("   Pommel Strike      ", "      Deal 8 damage to a single enemy, draw 1 card                                          ", 1, 8, 0, 0, 0, 0, 0, 1, 0);
	Card shieldbash("   Shield Bash        ", "      Deal 5 damage to a single enemy, gain 5 armor                                         ", 1, 5, 5, 0, 0, 0, 0, 0, 0);
	Card rampage("   Rampage            ", "      Deal 10 damage to a single enemy, the damage of this card increases by 5              ", 2, 10, 0, 0, 0, 0, 0, 0, 0);
	Card feed("   Feed               ", "      Deal 8 damage to a single enemy, increase your health by 8                            ", 2, 8, 0, 8, 0, 0, 0, 0, 0);

	for (int i = 0; i < 5; ++i) {
		this->m_deck.PushCard(strike);
		this->m_deck.PushCard(defend);
	}
	this->m_deck.PushCard(defend);
	for (int j = 0; j < 2; ++j)
	{
		this->m_deck.PushCard(pommelstrike);
		this->m_deck.PushCard(shieldbash);
		this->m_deck.PushCard(rampage);

	}
	this->m_deck.PushCard(inflame);
	this->m_deck.PushCard(footwork);
	this->m_deck.PushCard(warcry);
	this->m_deck.PushCard(feed);
}

void CardSystem::InitializeGuardian()
{
	Card strike("   Strike             ", "      Deal 6 damage to a single enemy                                                       ", 1, 6, 0, 0, 0, 0, 0, 0, 0);
	Card defend("   Defend             ", "      Increase your armor by 5                                                              ", 1, 0, 5, 0, 0, 0, 0, 0, 0);
	Card bastion("   Bastion            ", "      Increase the armor of your team by 6                                                  ", 1, 0, 6, 0, 0, 0, 0, 0, 0);
	Card footwork("   Footwork           ", "      Permanently increase your defense by 2                                                ", 1, 0, 0, 0, 0, 0, 2, 0, 0);
	Card shrugitoff("   Shrug it off       ", "      Gain 8 armor, draw 1 card                                                             ", 1, 0, 8, 0, 0, 0, 0, 1, 0);
	Card impervious("   Impervious         ", "      Increase your armor by 30                                                             ", 2, 0, 30, 0, 0, 0, 0, 0, 0);
	Card bodyslam("   Body Slam          ", "      Deal damage to a single enemy equals to your armor                                    ", 1, 0, 0, 0, 0, 0, 0, 0, 0);
	Card standtheground("   Stand the ground   ", "      Double your defense                                                                   ", 1, 0, 0, 0, 0, 0, 2, 0, 0);

	for (int i = 0; i < 4; ++i) {
		this->m_deck.PushCard(strike);
		this->m_deck.PushCard(defend);
	}
	this->m_deck.PushCard(defend);
	for (int j = 0; j < 2; ++j)
	{
		this->m_deck.PushCard(bastion);
		this->m_deck.PushCard(footwork);
		this->m_deck.PushCard(shrugitoff);
		this->m_deck.PushCard(impervious);
		this->m_deck.PushCard(bodyslam);
	}
	this->m_deck.PushCard(standtheground);
}
