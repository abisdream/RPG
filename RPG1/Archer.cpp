

#include "Archer.h"

Archer::Archer(std::string _id, int _HP, int _MP, int _Power, int _Defence) : Player(_id, _HP, _MP, _Power, _Defence)
{
	job = "궁수";

	HP += 30;
	CurrentHP += 30;
	Power += 30;

}

void Archer::Attack()
{
	std::cout << "* 화살을 발사한다!\n";
}