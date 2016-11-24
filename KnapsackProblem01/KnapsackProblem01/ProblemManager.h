#ifndef PROBLEM_MANAGER_H
#define PROBLEM_MANAGER_H

#include "PackageItem.hpp"
#include "AnswerInfo.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>

#define ItemNumMin 500
#define ItemNumMax 1000
#define WeightMin 1
#define WeightMax 100
#define ValueMin 1
#define ValueMax 100
#define Ratio 0.5

class ProblemManager {
private:
    int capacity;
    int ItemNum;
    PackageItem** ItemList;

    static ProblemManager* instance;
    ProblemManager();
    ProblemManager(const ProblemManager&) = delete;

public:
    static ProblemManager* GetInstance();
    ~ProblemManager();
    inline int NextRandom(int min, int max);
    
    void DynamicPlanning();
    void Greedy();
    void BackTracing();
    void SimulatedAnealing();

    void TestData();
    void ShowAnswer(std::vector<PackageItem> answers, AnswerInfo answerInfo);
	void ShowProblemInfo();
};



#endif /* PROBLEM_MANAGER_H */