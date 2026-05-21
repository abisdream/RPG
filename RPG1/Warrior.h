#pragma once

#include "Player.h"

class Warrior : public Player
{
public :
	Warrior(std::string _id,int _HP,int _MP,int _Power,int _Defence );

	void Attack() override;
};