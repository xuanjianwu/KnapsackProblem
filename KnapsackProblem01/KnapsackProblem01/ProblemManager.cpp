#include "ProblemManager.h"
#include <cstdlib>
#include <ctime>

ProblemManager::ProblemManager() {
    capacity = 0;
    std::srand(std::time(NULL));
    ItemNum = this->NextRandom(ItemNumMin, ItemNumMax);
    WeightArr = new int[ItemNum];
    ValueArr = new int[ItemNum];
    for (int i = 0; i < ItemNum; i++) {
        WeightArr[i] = this->NextRandom(WeightMin, WeightMax);
        capacity += WeightArr[i];
        ValueArr[i] = this->NextRandom(ValueMin, ValueMax);
    }
    capacity *= Ratio;
}

ProblemManager::~ProblemManager() {
    if (WeightArr != NULL) {
        delete[] WeightArr;
    }
    if (ValueArr != NULL) {
        delete[] ValueArr;
    }
}

int ProblemManager::NextRandom(int min, int max) {
    return std::rand() % (max - min) + min;
}

ProblemManager* ProblemManager::GetInstance() {
    return ProblemManager::instance == NULL ? ProblemManager::instance = new ProblemManager() : ProblemManager::instance;
}

ProblemManager* ProblemManager::instance = NULL;