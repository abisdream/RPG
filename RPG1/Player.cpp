
#include "Player.h"
#include "Monster.h"

class Monster;

Player::Player(std::string _id, int _HP, int _MP, int _Power, int _Defence)
{
	id = _id;

	HP = _HP;
	MP = _MP;

	Power = _Power;
	Defence = _Defence;

	CurrentHP = _HP;
	CurrentMP = _MP;



}

void Player::PrintPlayerStatus() const
{
	std::cout << "------------------------------------\n";

	std::cout << "닉네임 : " << id << "	| 직업: " << job << " |	LV.	" << Level << std::endl;
	std::cout << "HP : " << CurrentHP << " / "<< HP << " | MP : " << CurrentMP << " / " << MP << " | 공격력 : " << Power << " | 방어력: " << Defence << std::endl;

	std::cout << "------------------------------------\n";


}
/*
------------------------------------
닉네임: 철수 | 직업: 마법사 | Lv.1
HP: 80 | MP: 90 | 공격력: 40 | 방어력: 25
------------------------------------
*/
std::string Player::Getid() const
{
	return id;
}

std::string Player::GetJob() const
{
	return job;
}

int Player::GetHP() const
{
	return HP;
}

int Player::GetMP() const
{
	return MP;
}

int Player::GetPower() const
{
	return Power;
}

int Player::GetDefence() const
{
	return Defence;
}

int Player::GetCurrentHP() const
{
	return CurrentHP;
}

int Player::GetCurrentMP() const
{
	return CurrentMP;
}

int Player::GetLevel() const
{
	return Level;
}

int Player::GetExp() const
{
	return Exp;
}

int Player::GetMaxExp() const
{
	return MaxExp;
}


void Player::SetHP(int _HP)
{
	HP = _HP;
}

void Player::SetMP(int _MP)
{
	MP = _MP;
}

void Player::SetPower(int _Power)
{
	Power = _Power;
}

void Player::SetDefence(int _Defence)
{
	Defence = _Defence;
}

void Player::SetCurrentHP(int _CurrentHP)
{
	CurrentHP = _CurrentHP;
	if (CurrentHP > HP)
	{
		CurrentHP = HP;
	}
	if (CurrentHP < 0)
	{
		CurrentHP = 0;
	}
}


void Player::SetCurrentMP(int _CurrentMP)
{
	CurrentMP = _CurrentMP;
	if (CurrentMP > MP)
	{
		CurrentMP = MP;
	}
	if (CurrentMP < 0)
	{
		CurrentMP = 0;
	}
}

void Player::SetExp(int _Exp)
{
	Exp = _Exp;
}

/*void Player::Attack(Monster* monster)
{
	int damage = this->Power - monster->GetDefence();

	if (damage <= 0)
		damage = 1;

	int beforeHP = monster->GetHP();

	monster->SetHP(beforeHP - damage);

	std::cout << monster->GetName() << "에게 " << damage << " 데미지!\n";
	std::cout << "HP: " << beforeHP << " -> " << monster->GetHP() << "\n";
}*/