#include "ProblemManager.h"

int main() {
    auto core = ProblemManager::GetInstance();
    core->DynamicPlanning();
	core->Greedy();
    //system("pause");
    return 0;
}