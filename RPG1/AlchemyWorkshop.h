#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "PotionRecipe.h"

class AlchemyWorkshop
{
private:
	std::vector<PotionRecipe> recipes;

public:
	void AddRecipe(const PotionRecipe& recipe);
	
	void ShowAllRecipes() const;
	
	void SearchByName(std::string name) const;

	void SearchByIngredient(std::string ingredient) const;




};

