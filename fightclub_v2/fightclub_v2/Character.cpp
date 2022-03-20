#include "Character.h"

Character::Character()
	: m_alive(true), m_max_health(MAX_HEALTH), m_curr_health(MAX_HEALTH), m_armor(0), m_starting_stamina(STARTING_STAMINA), m_curr_stamina(STARTING_STAMINA), m_strength(0), m_defense(0)
{
}

const bool Character::GetAlive() const
{
	return this->m_alive;
}

const int Character::GetMaxHealth() const
{
	return this->m_max_health;
}

const int Character::GetCurrHealth() const
{
	return this->m_curr_health;
}

const int Character::GetArmor() const
{
	return this->m_armor;
}

const int Character::GetStartingStamina() const
{
	return this->m_starting_stamina;
}

const int Character::GetCurrStamina() const
{
	return this->m_curr_stamina;
}

const int Character::GetStrength() const
{
	return  this->m_strength;
}

const int Character::GetDefense() const
{
	return this->m_defense;
}

void Character::SetAlive(bool b)
{
	this->m_alive = b;
}

void Character::SetCurrHealth(int x)
{
	this->m_curr_health = x;
	if (this->GetCurrHealth() > this->GetMaxHealth())
		this->m_curr_health = this->GetMaxHealth();
	if (this->GetCurrHealth() < 0)
		this->m_curr_health = 0;
}

void Character::SetArmor(int x)
{
	this->m_armor = x;
	if (this->GetArmor() < 0)
		this->m_armor = 0;
}

void Character::SetCurrStamina(int x)
{
	this->m_curr_stamina = x;
	if (this->GetCurrStamina() < 0)
		this->m_curr_stamina = 0;
}

void Character::SetStrength(int x)
{
	this->m_strength = x;
}

void Character::SetDefense(int x)
{
	this->m_defense = x;
}

void Character::Die()
{
	SetAlive(false);
	SetCurrHealth(0);
	SetArmor(0);
	SetCurrStamina(0);
}
