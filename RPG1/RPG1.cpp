

#include <iostream>
#include <string>
#include <vector>

#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include "Item.h"
#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"



void Battle(Player* player, Monster& monster, std::vector<Item>& inventory);

void setpotion(int count, int* p_HpPotion, int* p_MpPotion); //매개변수 선언

int main(void)
{
    std::string id;
    /*
    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    int HP = stat[0];//최대 체력
    int MP = stat[1];//최대 마나

    int currentHP = stat[0];//현재 체력
    int currentMP = stat[1];//현재 마나
    */
    int HP = 0;
    int MP = 0;
    
    int Power = 0;
    int Defence = 0;

    int HpPotion = 0;
    int MpPotion = 0;

    int choice = 0;
    

    bool IsGameStart = false;

    Player* player = nullptr;
    
    std::vector<Item> inventory;
    const int Max_Inventory = 10;

    AlchemyWorkshop workshop;

    std::vector<Monster> dungeon;

    dungeon.push_back(Monster("슬라임", "슬라임의 끈적한 젤리", 50, 10, 10, 10));
    dungeon.push_back(Monster("고블린", "고블린의 곤봉", 100, 15, 10, 20));

    PotionRecipe hpPotion;
    hpPotion.PotionName = "HP포션";
    hpPotion.M1 = "허브";
    hpPotion.M2 = "맑은물";

    workshop.AddRecipe(hpPotion);

    PotionRecipe staminaPotion;
    staminaPotion.PotionName = "스태미나포션";
    staminaPotion.M1 = "허브";
    staminaPotion.M2 = "베리";

    workshop.AddRecipe(staminaPotion);

    setpotion(5, &HpPotion, &MpPotion); //변수의 주소로 넘겨 원본 값 변경 사용안할경우 복사된 값만 바뀌고 원본 HP포션 값은 바뀌지 않는다


    std::cout << "===========================================\n";
    std::cout << "[Dungeon Escape Text RPG]\n";
    std::cout << "===========================================\n";


    std::cout << "용사의 이름을 입력해주세요 : ";
    std::getline(std::cin, id);
    std::cout << "\n";


    while (true)
    {
        std::cout << "HP와 MP를 입력해주세요 : ";
        //std::cin >> stat[0] >> stat[1];
        std::cin >> HP >> MP;


        //if (stat[0] > 50 && stat[1] > 50)
        if (HP > 50 && MP > 50)
        {
            
            break;
        }
        else
        {
            std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
        }
    }

    while (true)
    {
        std::cout << "공격력과 방어력을 입력해주세요 : ";
        //std::cin >> stat[2] >> stat[3];
        std::cin >> Power >> Defence;

        //if (stat[2] > 50 && stat[3] > 50)
        if (Power > 50 && Defence > 50)
        {

            break;
        }
        else
        {
            std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
        }
    }
    std::cout << "\n";
    
    //printStatus(id, stat);

    

    std::cout << "< 전직 시스템 >\n";
    std::cout << id << "님, 직업을 선택해주세요!\n";

    std::cout << "1. 전사  2. 마법사  3. 도적  4. 궁수\n";

    std::cout << "선택 : ";

    while (player == nullptr)
    {
        std::cin >> choice;
        

        switch (choice)
        {
        case 1:
            player = new Warrior(id, HP, MP, Power, Defence);
            std::cout << "전사로 전직했습니다.  (HP +30, 방어력 +30)\n";
            player->Attack();
            break;

        case 2:
            player = new Magician(id, HP, MP, Power, Defence);
            std::cout << "마법사로 전직했습니다.  (MP +30, 공격력 +30)";
            player->Attack();
            break;

        case 3:
            player = new Thief(id, HP, MP, Power, Defence);
            std::cout << "도적으로 전직했습니다.  (HP +15, MP +15, 공격력 +30)";
            player->Attack();
            break;

        case 4:
            player = new Archer(id, HP, MP, Power, Defence);
            std::cout << "궁수로 전직했습니다.  (HP +30, 공격력 +30)";
            player->Attack();
            break;

        default:
            std::cout << "다시 입력\n";
        }
    }
    

    player -> PrintPlayerStatus();



    std::cout << "\n" << "\n";
    std::cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.\n";

    while (!IsGameStart)
    {
        
        std::cout << "===========================================\n";
        std::cout << "<캐릭터 강화>\n";
        std::cout << "1. HP UP    2. MP UP    3. 공격력 2배\n";
        std::cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작\n";
        std::cout << "===========================================\n";
        std::cout << "번호를 선택해주세요 : ";
        std::cin >> choice;
        std::cout << "\n";
        
        switch (choice)
        {
        case 1:
            

            if (HpPotion > 0)
            {
                //HP += 20;
                player->SetHP(player->GetHP() + 20);
                player->SetCurrentHP(player->GetCurrentHP() + 20);
                HpPotion--;
                std::cout << "* HP가 20 증가했습니다.   (HP 포션 차감: 남은 포션 " << HpPotion << "개)\n";

            }

            else
            {
                std::cout << "포션 부족\n";
            }
            break;

        case 2:
            if (MpPotion > 0)
            {
                //MP += 20;
                player->SetMP(player->GetMP() + 20);
                player->SetCurrentMP(player->GetCurrentMP() + 20);
                MpPotion--;
                std::cout << "* MP가 20 증가했습니다.   (MP 포션 차감: 남은 포션 " << MpPotion << "개)\n";

            }
            else
            {
                std::cout << "포션 부족\n";
            }
            break;

        case 3:
            if (player->GetPower() < 200)
            {
                //Power *= 2;
                player->SetPower(player->GetPower() * 2);
                std::cout << "\n";
                std::cout << "공격력이 2배 상승했습니다. (공격력 : " << player->GetPower() << " )\n";
                break;
            }
            else
            {
                std::cout << "이미 강화했습니다.";
                break;
            }
        case 4:
            if (player->GetDefence() < 200)
            {
                //Defence *= 2;
                player->SetDefence(player->GetDefence() * 2);
                std::cout << "\n";
                std::cout << "방어력이 2배 상승했습니다. (방어력 : " << player->GetDefence() << " )\n";
                break;
            }
            else
            {
                std::cout << "이미 강화했습니다.";
                break;
            }
        case 5:
            std::cout << "\n";
            //printStatus(id, stat);
            player->PrintPlayerStatus();
            std::cout << "\n";
            break;
        case 0:
            std::cout << "게임을 시작합니다!\n";
            IsGameStart = true;
            break;
            


        default:
            std::cout << "다시 입력\n";
            
        }
        
        
    }

    

    // 메인 메뉴

    while (true)
    {
        std::cout << "\n=== 메인 메뉴 ===\n";
        std::cout << "1. 던전 입장\n";
        std::cout << "2. 인벤토리 확인\n";
        std::cout << "3. 포션 제작소\n";
        std::cout << "0. 게임 종료\n\n";
        std::cout << "선택 : ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "\n[던전 입장]\n";
            for (Monster& m : dungeon)
            {
                Battle(player, m, inventory);
            }
            
            break;
        }

        case 2:
        
           
            std::cout << "\n[ 인벤토리 ("<< inventory.size() << " / "<< Max_Inventory<<") ]\n";

            if (inventory.empty())
            {
                std::cout << "아이템이 없습니다.";
            }
            else
            {
                int index = 1;

                for (const Item& item : inventory)
                {
                    std::cout << index << ". ";
                    item.PrintInfo();
                    index++;
                }
            }
            break;

        case 3:
        {
            int alchemyChoice;

            while (true)
            {
                std::cout << "\n=== 포션 제작소 ===\n";
                std::cout << "1.전체 레시피 보기\n";
                std::cout << "2.포션 이름으로 검색\n";
                std::cout << "3.재료로 검색\n";
                std::cout << "0.돌아가기\n";
                std::cout << "\n선택 : ";
                
                std::cin >> alchemyChoice;

                if (alchemyChoice == 0)
                {
                    break;
                }

                switch (alchemyChoice)
                {
                    case 1:
                        workshop.ShowAllRecipes();
                        break;

                    case 2:
                    {
                        std::string name;

                        std::cout << "검색할 포션 이름 : ";
                        std::cin >> name;

                        workshop.SearchByName(name);
                        break;

                    }
                    case 3:
                    {
                        std::string ingredient;

                        std::cout << "검색할 재료 : ";
                        std::cin >> ingredient;

                        workshop.SearchByIngredient(ingredient);
                        break;

                    }

                    default:
                        std::cout << "다시 입력해주세요\n";

                }

            }
            

            break;

        }
            
           
         
        case 0:
            std::cout << "\n게임 종료\n";
            delete player;
            player = nullptr;
            return 0;


        default:
            std::cout << "잘못입력\n";
            break;
        }

        
    }







    
    return 0;
}



void Battle(Player* player, Monster& monster, std::vector<Item>& inventory)
{
    

    monster.PrintMonsterStatus();

    std::cout << "\n[전투 시작!] " << player->Getid() << "(" << player->GetJob() << ")" << "vs" << monster.GetName() << std::endl;

    while (player->GetCurrentHP() > 0 && monster.GetHP() > 0)
    {
        std::cout << "\n--- 플레이어 턴 ---\n";
        player->Attack();

        int damage = player->GetPower() - monster.GetDefence();

        if (damage <= 0)
        {
            damage = 1;
        }

        int beforeHP = monster.GetHP();

        monster.SetHP(beforeHP - damage);

        std::cout << monster.GetName() << "에게 " << damage << " 데미지!" << std::endl;
        std::cout << monster.GetName() << "HP : " << beforeHP << " -> " << monster.GetHP() << std::endl;



        if (monster.GetHP() > 0)
        {
            std::cout << "\n--- 몬스터 턴 ---\n";
            monster.Attack(player);


        }

        if (monster.GetHP() <= 0)
        {
            monster.SetHP(0);
            std::cout << "\n★ 전투 승리!\n";
            std::cout << " -> " << monster.GetdropItemName() << "획득\n";
            std::cout << " -> " << "인벤토리에 저장되었습니다.\n";

            player->SetExp(player->GetExp() + 30);
            std::cout << "-> 경험치 +30 획득! "<< "(현재 경험치: "<< player->GetExp()<<" / "<<player->GetMaxExp()<<" )\n";


            inventory.push_back(monster.DropItem());


            break;
        }

        if (player->GetCurrentHP() <= 0)
        {
            player->SetCurrentHP(0);
            std::cout << "\n패배!\n";
            break;
        }

    }
}

void setpotion(int count, int* p_HpPotion, int* p_MpPotion) //매개변수 설정
{
    *p_HpPotion = count;
    *p_MpPotion = count;
}