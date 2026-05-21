#pragma once

#include <iostream>
#include <string>


class Player
{
protected:
    std::string id;
    std::string job;

    int HP;//최대 체력
    int MP;//최대 마나
    int Power;//공격력
    int Defence;//방어력

    int CurrentHP;//현재 체력
    int CurrentMP;//현재 마나

    int Level=1;//레벨

    int Exp = 0;
    int MaxExp = 100;


public:
    Player(std::string _id, int _HP,int _MP,int _Power,int _Defence);

	void PrintPlayerStatus() const;
    //void Attack(Monster* monster);

    std::string Getid() const;
    std::string GetJob() const;

    int GetHP() const;
    int GetMP() const;
    int GetPower() const;
    int GetDefence() const;
    int GetCurrentHP() const;
    int GetCurrentMP() const;
    int GetLevel() const;
    int GetExp() const;
    int GetMaxExp() const;

    void SetHP(int _HP);
    void SetMP(int _MP);
    void SetPower(int _Power);
    void SetDefence(int _Defence);
    void SetCurrentHP(int _CurrentHP);
    void SetCurrentMP(int _CurrentMP);
    void SetExp(int _Exp);
    void SetLevel(int _Level);

    virtual void Attack() = 0;

    virtual ~Player() {}

};