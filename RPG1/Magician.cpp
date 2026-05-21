

#include "Magician.h"

Magician::Magician(std::string _id, int _HP, int _MP, int _Power, int _Defence) : Player(_id, _HP, _MP, _Power, _Defence)
{
	job = "마법사";

	MP += 30;
	CurrentMP += 30;
	Power += 30;

}

void Magician::Attack()
{
	std::cout << "* 파이어볼을 발사한다!\n";
}