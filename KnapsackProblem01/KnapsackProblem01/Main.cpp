#include "ProblemManager.h"

int main() {
    auto core = ProblemManager::GetInstance();
    core->DynamicPlanning();
    system("pause");
    return 0;
}