#pragma once

constexpr auto MAX_HEALTH = 99;
constexpr auto STARTING_STAMINA = 3;

class Character
{
public:
	// #### Constructor & Destructor ####
	Character();
	// #### Getter ####
	const int GetMaxHealth() const;
	const int GetCurrHealth() const;
	const int GetArmor() const;
	const int GetStartingStamina() const;
	const int GetCurrStamina() const;
	// #### Setter ####
	void SetCurrHealth(int x);
	void SetArmor(int x);
	void SetCurrStamina(int x);
protected:
	int m_max_health;
	int m_curr_health;
	int m_armor;
	int m_starting_stamina;
	int m_curr_stamina;
private:
};

