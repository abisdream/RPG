#pragma once

#include <iostream>
#include <string>
#include "Item.h"


class Player;

class Monster
{
private:
	std::string name;
	std::string dropItemName;
	

	int HP;
	int Power;
	int Defence;
	int dropItemPrice;



public:
	Monster(std::string _name, std::string _dropItemName,int _HP, int _Power,int _Defence,int _dropItemPrice);

	void Attack(Player* player);

	void PrintMonsterStatus() const;

	std::string GetName() const;
	std::string GetdropItemName() const;

	int GetHP() const;
	int GetPower() const;
	int GetDefence() const;
	int GetdropItemPrice() const;

	void SetHP(int _HP);

	Item DropItem() const;
	
};

