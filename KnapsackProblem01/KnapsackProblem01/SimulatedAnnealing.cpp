#include "ProblemManager.h"

void ProblemManager::SimulatedAnealing() {
    int* solution = new int[ItemNum];
    memset(solution, 0, sizeof(int)* ItemNum);
    
    int w = 0, v = 0;
    for (int i = 0; i < ItemNum; i++) {
        w += ItemList[i]->weight * solution[i];
        v += ItemList[i]->value * solution[i];
    }
    double t0 = 500;
    double t = t0;
    double a = 0.95f;
    double e = 0.0001f;
    int L = 10 * ItemNum;
    int i, j;
    while (t > e) {
        std::srand(std::time(NULL));
        for (int k = 0; k < L; k++) {
            i = std::rand() % ItemNum;
            if (solution[i] == 0) {
                if ()
            }
        }
    }
}