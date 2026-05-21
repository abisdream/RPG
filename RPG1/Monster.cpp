
#include "Monster.h"
#include "Player.h"
#include "Item.h"



Monster::Monster(std::string _name, std::string _dropItemName,int _HP, int _Power, int _Defence, int _dropItemPrice)
{
	name = _name;
	HP = _HP;
	Power = _Power;
	Defence = _Defence;
	dropItemName = _dropItemName;
	dropItemPrice = _dropItemPrice;
}

void Monster::PrintMonsterStatus() const
{
	std::cout << "------------------------------------\n";

	std::cout << "몬스터 : " << name << std::endl;
	std::cout << "HP : " << HP <<" | 공격력 : " << Power << " | 방어력: " << Defence << std::endl;

	std::cout << "------------------------------------\n";
}

int Monster::GetHP() const
{
	return HP;
}

int Monster::GetPower() const
{
	return Power;
}

int Monster::GetDefence() const
{
	return Defence;
}

void Monster::SetHP(int _HP)
{
	HP = _HP;
}

void Monster::Attack(Player* player)
{
	int Damage = Power - player->GetDefence();

	if (Damage <= 0)
	{
		Damage = 1;

	}

	int beforeHP = player->GetCurrentHP();


	player->SetCurrentHP(beforeHP - Damage);

	std::cout << name << "의 공격!\n";
	std::cout << Damage << "의 데미지를 입었다."<<std::endl;
	std::cout << player->Getid() << " HP : " <<beforeHP<< "->" << player->GetCurrentHP() << std::endl;


	

}

std::string Monster::GetName() const
{
	return name;
}

std::string Monster::GetdropItemName() const
{
	return dropItemName;
}

int Monster::GetdropItemPrice() const
{
	return dropItemPrice;
}

Item Monster::DropItem() const
{
	return { dropItemName, dropItemPrice };
}