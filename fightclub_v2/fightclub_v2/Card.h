#pragma once
#include <string>

class Card
{
public:
// #### Constructors & Destructor ####
	Card(const std::string& name, const std::string& description, int cost, int damage, int armor,
		 int health, int stamina, int strength, int defense, int draw, int discard);
	virtual ~Card();
// #### Getter ####
	const std::string& GetName() const;
	const std::string& GetDescription() const;
	const int GetCost() const;
	const int GetDamageModifier() const;
	const int GetArmorModifier() const;
	const int GetHealthModifier() const;
	const int GetStaminaModifier() const;
	const int GetStrengthModifier() const;
	const int GetDefenseModifier() const;
	const int GetDrawModifier() const;
	const int GetDiscardModifier() const;
// #### Setter ####
	void SetName(const std::string& name);
	void SetDescription(const std::string& description);
	void SetCost(const int cost);
	void SetDamageModifier(const int damage);
	void SetArmorModifier(const int armor);
	void SetHealthModifier(const int health);
	void SetStaminaModifier(const int stamina);
	void SetStrengthModifier(const int strength);
	void SetDefenseModifier(const int defense);
	void SetDrawModifier(const int draw);
	void SetDiscardModifier(const int discard);
// #### Public Methods ####
// #### Overloaded Operators ####
	friend std::ostream& operator<<(std::ostream& os, const Card& card);

protected:
	std::string m_name;
	std::string m_description;
	int m_cost;
	int m_attributes[8];
private:
};

/*
 *	attr[0]: damage
 *  attr[1]: armor
 *  attr[2]: health
 *  attr[3]: stamina
 *  attr[4]: strength
 *  attr[5]: defense
 *  attr[6]: draw
 *  attr[7]: discard
 */