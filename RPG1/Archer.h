#pragma once

#include "Player.h"

class Archer : public Player
{
public:
	Archer(std::string _id, int _HP, int _MP, int _Power, int _Defence);

	void Attack() override;
};