#pragma once

#include "Player.h"

class Magician : public Player
{
public:
	Magician(std::string _id, int _HP, int _MP, int _Power, int _Defence);

	void Attack() override;
};