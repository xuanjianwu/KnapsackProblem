#include "ProblemManager.h"


ProblemManager::ProblemManager() {
    capacity = 0;
    std::srand(std::time(NULL));
    ItemNum = this->NextRandom(ItemNumMin, ItemNumMax);
    ItemList = new PackageItem*[ItemNum];
    for (int i = 0; i < ItemNum; i++) {
        auto w = this->NextRandom(WeightMin, WeightMax);
        capacity += w;
        auto v = this->NextRandom(ValueMin, ValueMax);
        ItemList[i] = new PackageItem(i, w, v);
    }
    capacity *= Ratio;
}

ProblemManager::~ProblemManager() {
    if (ItemList != NULL) {
        for (int i = 0; i < ItemNum; i++) {
            if (ItemList[i] != NULL) {
                delete ItemList[i];
            }
        }
        delete ItemList;
    }
}

int ProblemManager::NextRandom(int min, int max) {
    return std::rand() % (max - min) + min;
}

void ProblemManager::ShowAnswer(std::vector<PackageItem> answers) {
    std::cout << "Answer list:" << std::endl;
    int totalWeight = 0, TotalValue = 0;
    for (int i = 0; i < answers.size(); i++) {
        std::cout << answers[i].id << "  ";
        totalWeight += answers[i].weight;
        TotalValue += answers[i].value;
    }
    std::cout << std::endl;
    std::cout << "Total weight: " << totalWeight << "  Bag Capacity: " << capacity << "  Total value: " << TotalValue << std::endl;
}

void ProblemManager::TestData() {
    capacity = 10;
    ItemNum = 5;
    ItemList[0] = new PackageItem(0, 2, 6);
    ItemList[1] = new PackageItem(1, 2, 3);
    ItemList[2] = new PackageItem(2, 6, 5);
    ItemList[3] = new PackageItem(3, 5, 4);
    ItemList[4] = new PackageItem(4, 4, 6);
}

ProblemManager* ProblemManager::GetInstance() {
    return ProblemManager::instance == NULL ? ProblemManager::instance = new ProblemManager() : ProblemManager::instance;
}

ProblemManager* ProblemManager::instance = NULL;