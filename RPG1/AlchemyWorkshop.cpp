

#include "AlchemyWorkshop.h"

void AlchemyWorkshop::AddRecipe(const PotionRecipe& recipe)
{
	recipes.push_back(recipe);
}

void AlchemyWorkshop::ShowAllRecipes() const
{
	for (const PotionRecipe& recipe : recipes)
	{
		recipe.PrintRecipe();
	}
}

void AlchemyWorkshop::SearchByName(std::string name) const
{
	bool found = false;

	for (const PotionRecipe& recipe : recipes)
	{
		if (recipe.PotionName == name)
		{
			recipe.PrintRecipe();
			found = true;
		}
	}

	if (!found)
	{
		std::cout << "그런 레시피 이름은 존재하지 않습니다.\n";
	}


}


void AlchemyWorkshop::SearchByIngredient(std::string ingredient) const
{
	int count = 0;

	for (const PotionRecipe& recipe : recipes)
	{
		if (recipe.M1 == ingredient || recipe.M2 == ingredient)
		{
			recipe.PrintRecipe();
			count++;
		}
	}

	if (count == 0)
	{
		std::cout << "이 재료들이 포함된 레시피를 찾을 수 없습니다.\n";
	}
	else
	{
		std::cout << "총 " << count << "개의 레시피를 찾았습니다.\n";
	}
	



}

