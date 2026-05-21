#pragma once

#include "Player.h"

class Thief : public Player
{
public:
	Thief(std::string _id, int _HP, int _MP, int _Power, int _Defence);

	void Attack() override;
};