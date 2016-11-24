#include "ProblemManager.h"

int main() {
    auto core = ProblemManager::GetInstance();
	core->ShowProblemInfo();
    core->DynamicPlanning();
	core->Greedy();
    core->BackTracing();
	core->SimulatedAnealing();
    //system("pause");
    return 0;
}