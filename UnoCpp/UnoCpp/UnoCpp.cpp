#include <iostream>

#include "GameManager.h"

int main()
{
	GameManager gameManager{};
	gameManager.Setup();
	return 0;
}

// int Core::RandomRange(int min, int maxInclusive)
// {
// 	std::mt19937 mt{std::random_device{}()};
// 	std::uniform_int_distribution distribution = std::uniform_int_distribution{min, maxInclusive};
//
// 	return distribution(mt);
// }

// const unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
// std::ranges::shuffle(cards, std::default_random_engine(seed));