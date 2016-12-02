#include "ProblemManager.h"


ProblemManager::ProblemManager() {
    capacity = 0;
	std::srand((unsigned)std::time(NULL));
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

void ProblemManager::ShowAnswer(std::vector<PackageItem> answers, AnswerInfo answerInfo) {
	std::cout << "算法:  " << answerInfo.MethodName << std::endl << "计算时间:  " 
		<< std::setiosflags(std::ios::fixed) << std::setprecision(2) << answerInfo.CalTime << " ms" << std::endl;
    //std::cout << "Answer:  ";
    int totalWeight = 0, TotalValue = 0;
    for (unsigned int i = 0; i < answers.size(); i++) {
        //std::cout << answers[i].id << "  ";
        totalWeight += answers[i].weight;
        TotalValue += answers[i].value;
    }
    std::cout << std::endl;
	std::cout << "Weights: " << totalWeight << "  Values: " << TotalValue << std::endl << "Capacity: " << capacity << std::endl << std::endl;
}

void ProblemManager::ShowProblemInfo() {
	std::cout << "01背包问题:" << std::endl
		<< "背包问题规模:  " << ItemNum << std::endl
		<< "背包的总容量:  " << capacity << std::endl
		<< "物品重量范围:  " << WeightMin << "——" << WeightMax << std::endl
		<< "物品价值范围:  " << ValueMin << "——" << ValueMax << std::endl << std::endl;
}

void ProblemManager::TestData() {
    capacity = 10;
    ItemNum = 5;
    ItemList[0] = new PackageItem(0, 2, 6);
    ItemList[1] = new PackageItem(1, 2, 3);
    ItemList[2] = new PackageItem(2, 6, 5);
    ItemList[3] = new PackageItem(3, 5, 4);
    ItemList[4] = new PackageItem(4, 4, 6);
	//capacity = 12;
	//ItemNum = 8;
	//ItemList[0] = new PackageItem(0, 2, 13);
	//ItemList[1] = new PackageItem(1, 1, 10);
	//ItemList[2] = new PackageItem(2, 3, 24);
	//ItemList[3] = new PackageItem(3, 2, 15);
	//ItemList[4] = new PackageItem(4, 4, 28);
	//ItemList[5] = new PackageItem(5, 5, 33);
	//ItemList[6] = new PackageItem(6, 3, 20);
	//ItemList[7] = new PackageItem(7, 1, 8);
}

ProblemManager* ProblemManager::GetInstance() {
    return ProblemManager::instance == NULL ? ProblemManager::instance = new ProblemManager() : ProblemManager::instance;
}

ProblemManager* ProblemManager::instance = NULL;