#ifndef INCLUDE_MAIN
#define INCLUDE_MAIN

#include "Player.h"
#include "Monster.h"

void fightMonster(Player& p, Monster& m);
void attackMonster(Player& p, Monster& m);
void attackPlayer(Player& p, Monster& m);
bool fiftyPercentProbability();
bool thirtyPercentProbability();
int generateRandomNumber(int min, int max);
void handlePotion(Player& p);

#endif // INCLUDE_MAIN
