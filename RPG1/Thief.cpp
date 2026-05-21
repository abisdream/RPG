

#include "Thief.h"

Thief::Thief(std::string _id, int _HP, int _MP, int _Power, int _Defence) : Player(_id, _HP, _MP, _Power, _Defence)
{
	job = "도적";

	HP += 15;
	CurrentHP += 15;
	MP += 15;
	CurrentMP += 15;
	Power += 30;

}

void Thief::Attack()
{
	std::cout << "* 단검을 투척한다!\n";
}