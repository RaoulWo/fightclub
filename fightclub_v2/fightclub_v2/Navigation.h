#pragma once

class Navigation
{
public:
	// #### Constructors & Destructor ####
	Navigation(int x);
	// #### Getter ####
	const int GetCoord() const;
	// #### Setter ####
	void SetCoord(int x);
	// #### Public Methods ####
	virtual void Render();
	virtual void MoveLeft();
	virtual void MoveRight();
protected:
	int m_coord;
private:
};

