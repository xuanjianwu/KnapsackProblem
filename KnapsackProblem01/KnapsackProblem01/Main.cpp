#include "ProblemManager.h"

int main() {
    auto core = ProblemManager::GetInstance();
    core->DynamicPlanning();
	core->Greedy();
    core->BackTracing();
    system("pause");
    return 0;
}