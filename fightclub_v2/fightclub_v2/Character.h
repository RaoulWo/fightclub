#pragma once

constexpr auto MAX_HEALTH = 99;
constexpr auto STARTING_STAMINA = 3;

class Character
{
public:
	// #### Constructor & Destructor ####
	Character();
	// #### Getter ####
	const bool GetAlive() const;
	const int GetMaxHealth() const;
	const int GetCurrHealth() const;
	const int GetArmor() const;
	const int GetStartingStamina() const;
	const int GetCurrStamina() const;
	const int GetStrength() const;
	const int GetDefense() const;
	// #### Setter ####
	void SetAlive(bool b);
	void SetCurrHealth(int x);
	void SetArmor(int x);
	void SetCurrStamina(int x);
	void SetStrength(int x);
	void SetDefense(int x);

	void Die();
protected:
	bool m_alive;
	int m_max_health;
	int m_curr_health;
	int m_armor;
	int m_starting_stamina;
	int m_curr_stamina;
	int m_strength;
	int m_defense;
private:
};

