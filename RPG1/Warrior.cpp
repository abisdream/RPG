

#include "Warrior.h"

Warrior::Warrior(std::string _id, int _HP, int _MP, int _Power, int _Defence) : Player( _id, _HP, _MP, _Power, _Defence)
{
	job = "전사";

	HP += 30;
	CurrentHP += 30;
	Defence += 30;

}

void Warrior::Attack()
{
	std::cout << "* 검을 강하게 휘두른다!\n";
}