#include "Card.h"
#include <iostream>

Card::Card(const std::string& name, const std::string& description, int cost, int damage, int armor, int health, int stamina, int strength, int defense, int draw, int discard)
	: m_name(name), m_description(description), m_cost(cost)
{
	m_attributes[0] = damage;
	m_attributes[1] = armor;
	m_attributes[2] = health;
	m_attributes[3] = stamina;
	m_attributes[4] = strength;
	m_attributes[5] = defense;
	m_attributes[6] = draw;
	m_attributes[7] = discard;
#ifdef _DEBUG
	std::cout << "Card was created" << '\n';
#endif
}

Card::~Card()
{
#ifdef _DEBUG
	std::cout << "Card was destroyed" << '\n';
#endif
}

const std::string& Card::GetName() const
{
	return this->m_name;
}

const std::string& Card::GetDescription() const
{
	return this->m_description;
}

const int Card::GetCost() const
{
	return this->m_cost;
}

const int Card::GetDamageModifier() const
{
	return this->m_attributes[0];
}

const int Card::GetArmorModifier() const
{
	return this->m_attributes[1];
}

const int Card::GetHealthModifier() const
{
	return this->m_attributes[2];
}

const int Card::GetStaminaModifier() const
{
	return this->m_attributes[3];
}

const int Card::GetStrengthModifier() const
{
	return this->m_attributes[4];
}

const int Card::GetDefenseModifier() const
{
	return this->m_attributes[5];
}

const int Card::GetDrawModifier() const
{
	return this->m_attributes[6];
}

const int Card::GetDiscardModifier() const
{
	return this->m_attributes[7];
}

void Card::SetName(const std::string& name)
{
	this->m_name = name;
}

void Card::SetDescription(const std::string& description)
{
	this->m_description = description;
}

void Card::SetCost(const int cost)
{
	this->m_cost = cost;
	if (this->GetCost() < 0) // cost >= 0
		this->m_cost = 0;
}

void Card::SetDamageModifier(const int damage)
{
	this->m_attributes[0] = damage;
	if (this->GetDamageModifier() < 0) // damage >= 0
		this->m_attributes[0] = 0;
}

void Card::SetArmorModifier(const int armor)
{
	this->m_attributes[1] = armor;
	if (this->GetArmorModifier() < 0) // armor >= 0
		this->m_attributes[1] = 0;
}

void Card::SetHealthModifier(const int health)
{
	this->m_attributes[2] = health;
}

void Card::SetStaminaModifier(const int stamina)
{
	this->m_attributes[3] = stamina;
}

void Card::SetStrengthModifier(const int strength)
{
	this->m_attributes[4] = strength;
}

void Card::SetDefenseModifier(const int defense)
{
	this->m_attributes[5] = defense;
}

void Card::SetDrawModifier(const int draw)
{
	this->m_attributes[6] = draw;
}

void Card::SetDiscardModifier(const int discard)
{
	this->m_attributes[7] = discard;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << '\n'
	   << "Name        : " << card.GetName() << '\n'
	   << "Description : " << card.GetDescription() << '\n'
	   << "Cost        : " << card.GetCost() << '\n'
	   << "Damage      : " << card.GetDamageModifier() << '\n'
	   << "Armor       : " << card.GetArmorModifier() << '\n'
	   << "Health      : " << card.GetHealthModifier() << '\n'
	   << "Stamina     : " << card.GetStaminaModifier() << '\n'
	   << "Strength    : " << card.GetStrengthModifier() << '\n'
	   << "Defense     : " << card.GetDefenseModifier() << '\n'
	   << "Draw        : " << card.GetDrawModifier() << '\n'
	   << "Discard     : " << card.GetDiscardModifier() << '\n';
	return os;
}
